#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "Macro.h"
#include "Ledring.h"
#include "Enc.h"
#include "Bank.h"
#include "Button.h"
#include "Midi.h"
#include "Lcd.h"

#include "Logger.h"

class Controller
{
  private:
  
    //members
    Adafruit_NeoPixel strip;
    Enc encoders[NUM_ENCODERS];
    Bank banks[NUM_BANKS];
    Button bankButtons[NUM_BANKS];
    Midi midi;
    Lcd lcd;
    Logger* logger;

    int activeBank;

    unsigned long lcdEventTime;
    bool lcdEventActive;

  public:
    Controller(Logger* logger);

    void update();
    void setBank(int bank);
    void showWelcome();

    Adafruit_NeoPixel* getStrip();
};