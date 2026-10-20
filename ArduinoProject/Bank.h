#pragma once

#include <Arduino.h>

#include "Macro.h"
#include "Button.h"

class Bank
{
  private:
    int values[NUM_ENCODERS];

    Button masterReset;

    uint32_t color;
    uint8_t program;

  public:
    Bank();

    void begin(uint8_t resetPin, uint32_t color, uint8_t program);

    int getValue(int encoder);
    void setValue(int encoder, int value);

    void resetEncoder(int encoder);
    void resetAll();

    bool update();

    uint32_t getColor();
    uint8_t getProgram();
};
