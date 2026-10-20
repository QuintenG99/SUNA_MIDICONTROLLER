#include "Button.h"

Button::Button()
{
  pin = 0;

  currentState = false;
  lastReading = false;
  stableState = false;

  pressedEvent = false;
  releasedEvent = false;

  lastDebounceTime = 0;
}

void Button::begin(uint8_t pin)
{
  this->pin = pin;

  pinMode(pin, INPUT_PULLUP);
}


void Button::update()
{
  currentState = digitalRead(pin) == LOW;

  pressedEvent = false;
  releasedEvent = false;

  if (currentState != lastReading)
  {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (currentState != stableState)
    {
      stableState = currentState;

      if(stableState)
      {
        pressedEvent = true;
      }
      else
      {
        releasedEvent = true;
      }
    }
  }

  lastReading = currentState;
}

bool Button::pressed()
{
  return pressedEvent;
}

bool Button::released()
{
  return releasedEvent;
}