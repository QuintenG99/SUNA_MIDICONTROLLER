#pragma once

#include <Arduino.h>

class Button
{
  private:
    uint8_t pin;

    bool currentState;
    bool lastReading;
    bool stableState;

    bool pressedEvent;
    bool releasedEvent;

    unsigned long lastDebounceTime;
    const unsigned long debounceDelay = 50;

  public:
    Button();

    void begin(uint8_t pin);
    void update();

    bool pressed();
    bool released();
};