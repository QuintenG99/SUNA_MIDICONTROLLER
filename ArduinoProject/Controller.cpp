#include "Controller.h"

Controller::Controller(Logger* logger)
  : strip(NUM_LEDS, LEDRING_PIN, NEO_GRB + NEO_KHZ800),
    activeBank(0)
{
  strip.begin();
  
  this->logger = logger;

  lcdEventTime = 0;
  lcdEventActive = false;

  for(int i = 0; i < NUM_ENCODERS; i++)
  {
    encoders[i].begin(
      encoderConfigs[i].pinA,
      encoderConfigs[i].pinB,
      encoderConfigs[i].buttonPin,
      &strip,
      i * LEDS_PER_ENCODER
    );
  }

  uint32_t colors[NUM_BANKS] =
  {
    strip.Color(BANK1_COLOR),      
    strip.Color(BANK2_COLOR),      
    strip.Color(BANK3_COLOR),       
    strip.Color(BANK4_COLOR),       
    strip.Color(BANK5_COLOR),    
    strip.Color(BANK6_COLOR),    
    strip.Color(BANK7_COLOR),    
    strip.Color(BANK8_COLOR)     
  };

  for(int i = 0; i < NUM_BANKS; i++)
  {
    banks[i].begin(MASTER_RESET, colors[i], bankConfigs[i].program);
    bankButtons[i].begin(bankConfigs[i].buttonPin);
  }

  midi.begin();
  lcd.begin();

  setBank(0);

  logger->info("Controller", "Controller gestart");
}

void Controller::update()
{


  for(int i = 0; i < NUM_ENCODERS; i++)
  {
    encoders[i].update();

    if(encoders[i].hasChanged())
    {
      banks[activeBank].setValue(i, encoders[i].getValue());
    }

    if(encoders[i].hasChanged())
    {
      midi.sendEncoderCC(activeBank, i, encoders[i].getValue());
      lcd.showEncoder(activeBank +1, i + 1, encoders[i].getValue());

      lcdEventTime = millis();
      lcdEventActive = true;
    }

    if(encoders[i].buttonPressed())
    {
      banks[activeBank].resetEncoder(i);
      encoders[i].setValue(0);

      midi.sendEncoderCC(activeBank, i, 0);
      midi.sendButtonCC(activeBank, i, 127);
      lcd.showButton(activeBank + 1, i + 1);

      lcdEventTime = millis();
      lcdEventActive = true;
    }

    if(encoders[i].buttonReleased())
    {
      midi.sendButtonCC(activeBank, i, 0);
    }
  }

  for(int i = 0; i < NUM_BANKS; i++)
  {
    bankButtons[i].update();
    
    if(bankButtons[i].pressed())
    {
      setBank(i);
    }
  }

  if(banks[activeBank].update())
  {
    for(int i = 0; i < NUM_ENCODERS; i++)
    {
      encoders[i].setValue(banks[activeBank].getValue(i));
    }

    lcd.showMasterReset(activeBank + 1);

    lcdEventTime = millis();
    lcdEventActive = true;
  }

  if(lcdEventActive && millis() - lcdEventTime >= 5000)
  {
    lcd.clearEvent();
    lcdEventActive = false;
  }

  strip.show();
}

void Controller::setBank(int bank)
{
  activeBank = bank;

  // DEBUG: opgeslagen waarden controleren vóór ze naar de encoders gaan
  Serial.println("----- BANK DEBUG -----");
  Serial.print("BANK: ");
  Serial.println(activeBank + 1);

  for(int i = 0; i < NUM_ENCODERS; i++)
  {
    Serial.print("ENC");
    Serial.print(i + 1);
    Serial.print(" STORED VALUE: ");
    Serial.println(banks[activeBank].getValue(i));
  }

  Serial.println("----------------------");

  lcdEventActive = false;

  for(int i = 0; i < NUM_ENCODERS; i++)
  {
    encoders[i].setColor(banks[activeBank].getColor());
    encoders[i].setValue(banks[activeBank].getValue(i));
  }

  midi.sendProgramChange(banks[activeBank].getProgram());
  lcd.showBank(activeBank + 1);
}

Adafruit_NeoPixel* Controller::getStrip()
{
  return &strip;
}

void Controller::showWelcome()
{
  lcd.showWelcome();
}