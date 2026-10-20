#include "Macro.h"
#include "Enc.h"

Enc::Enc()
{
  changed = false;
  buttonPressedEvent = false;
  buttonReleasedEvent = false;
}

void Enc::begin(uint8_t pinA, uint8_t pinB, uint8_t buttonPin, Adafruit_NeoPixel* strip, uint8_t ledStart)
{
  rotary.begin(pinA, pinB);
  button.begin(buttonPin);
  ledring.begin(strip, ledStart, LEDS_PER_ENCODER);
}

void Enc::update()
{
  int oldValue = rotary.getValue();

  rotary.update();
  button.update();

  buttonPressedEvent = button.pressed();
  buttonReleasedEvent = button.released();

  int newValue = rotary.getValue();

  changed = (oldValue != newValue);

  if(changed)
  {
    ledring.setValue(newValue);
  }
}

int Enc::getValue()
{
  return rotary.getValue();
}

void Enc::setValue(int value)
{
  rotary.setValue(value);
  ledring.setValue(value);
}

void Enc::setColor(uint32_t color)
{
  ledring.setColor(color);
}

bool Enc::hasChanged()
{
  return changed;
}

bool Enc::buttonPressed()
{
  return buttonPressedEvent;
}

bool Enc::buttonReleased()
{
  return buttonReleasedEvent;
}