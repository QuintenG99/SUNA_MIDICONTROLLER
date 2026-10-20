#pragma once

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class Lcd
{
  private:
    LiquidCrystal_I2C lcd;
    
    void showHeader(uint8_t bank);
  
  public:
    Lcd();

    void begin();

    void showWelcome();
    void showBank(uint8_t bank);
    void showEncoder(uint8_t bank, uint8_t encoder, uint8_t value);
    void showButton(uint8_t bank, uint8_t encoder);
    void showMasterReset(uint8_t bank);

    void clearEvent();
};