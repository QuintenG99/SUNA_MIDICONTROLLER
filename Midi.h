#pragma once

#include <Arduino.h>

class Midi
{
  private:

  public:
    Midi();

    void begin();
  
    void sendCC(uint8_t cc, uint8_t value);
    void sendProgramChange(uint8_t program);
    void sendEncoderCC(uint8_t bank, uint8_t encoder, uint8_t value);
    void sendButtonCC(uint8_t bank, uint8_t button, uint8_t value);

};