#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "Rotary.h"
#include "Button.h"
#include "Ledring.h"

class Enc
{
  private:
    Rotary rotary;
    Button button;
    Ledring ledring;

    bool changed;
    bool buttonPressedEvent;
    bool buttonReleasedEvent;

  public:
    Enc();

    void begin(uint8_t pinA, uint8_t pinB, uint8_t buttonPin, Adafruit_NeoPixel* strip, uint8_t ledStart);

    void update();
    int getValue();
    bool hasChanged();
    bool buttonPressed();
    bool buttonReleased();

    void setValue(int value);
    void setColor(uint32_t color);

};