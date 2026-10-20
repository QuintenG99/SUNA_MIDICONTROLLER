#include "Bank.h"

Bank::Bank()
{
  for(int i = 0; i < NUM_ENCODERS; i++)
  {
    values[i] = 0;
  }

  color = 0;
  program = 0;
}

void Bank::begin(uint8_t resetPin, uint32_t color, uint8_t program)
{
  masterReset.begin(resetPin);
  this->color = color;
  this->program = program;
}

int Bank::getValue(int encoder)
{
  return values[encoder];
}

void Bank::setValue(int encoder, int value)
{
  values[encoder] = constrain(value, 0, 127);
}

void Bank::resetEncoder(int encoder)
{
  //debug
  Serial.print("RESET: ");
  Serial.print(encoder);
  Serial.print(" OLD VALUE: ");
  Serial.println(values[encoder]);

  values[encoder] = 0;

  Serial.print("NEW VALUE: ");
  Serial.println(values[encoder]);
}

void Bank::resetAll()
{
  for(int i = 0; i < NUM_ENCODERS; i++)
  {
    values[i] = 0;
  }
}


bool Bank::update()
{
  masterReset.update();
  
  if(masterReset.pressed())
  {
    resetAll();
    return true;
  }

  return false;
}

uint32_t Bank::getColor()
{
  return color;
}

uint8_t Bank::getProgram()
{
  return program;
}