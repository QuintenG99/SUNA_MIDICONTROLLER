#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class Startup
{
  private:
    Adafruit_NeoPixel* strip;

    unsigned long flashTime;
    bool flashState;

    unsigned long startTime;

  public:
    Startup();

    void begin(Adafruit_NeoPixel* strip);
    void welcomeLed();

    bool finished();
    void end();
};