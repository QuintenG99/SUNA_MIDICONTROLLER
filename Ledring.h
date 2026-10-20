#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class Ledring
{
  private:
    uint8_t startLed;
    uint8_t numLeds;
    uint32_t color;

    Adafruit_NeoPixel* strip;

  public:
    Ledring();

    void begin(Adafruit_NeoPixel* strip, uint8_t startLed, uint8_t numLeds);

    void setValue(int value);
    void setColor(uint32_t color);
    void clear();
};