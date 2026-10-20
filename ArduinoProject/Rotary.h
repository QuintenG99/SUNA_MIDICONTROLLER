#pragma once

#include <Arduino.h>
#include <Encoder.h>

class Rotary
{
  private:
    uint8_t pinA;
    uint8_t pinB;

    long lastRaw;
    int value;

    const int encoderSteps = 2;

    Encoder* encoder;

  public:
    Rotary();

    void begin(uint8_t pinA, uint8_t pinB);

    void update();
    int getValue();
    void setValue(int value);
    void reset();

    ~Rotary();
};

