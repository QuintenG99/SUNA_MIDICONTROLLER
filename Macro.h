#pragma once

#include <Arduino.h>

// ========================
// ALGEMENE CONFIGURATIE
// ========================

//KLEUREN//
#define BANK1_COLOR 255, 0, 0       // rood
#define BANK2_COLOR 0, 255, 0       // groen
#define BANK3_COLOR 0, 0, 255       // blauw
#define BANK4_COLOR 255, 255, 0     // geel
#define BANK5_COLOR 255, 0, 255     // magenta
#define BANK6_COLOR 0, 255, 255     // cyaan
#define BANK7_COLOR 255, 128, 0     // oranje
#define BANK8_COLOR 128, 0, 255     // paars

//AANTAL ENCODERS//
#define NUM_ENCODERS 8

//AANTAL BANKS//
#define NUM_BANKS 8

//ENCODER 1//
#define ENC1_PIN_A 2
#define ENC1_BUTTON 3
#define ENC1_PIN_B 4

//ENCODER 2//
#define ENC2_PIN_A 5
#define ENC2_BUTTON 6
#define ENC2_PIN_B 7

//ENCODER 3//
#define ENC3_PIN_A 8
#define ENC3_BUTTON 9
#define ENC3_PIN_B 10

//ENCODER 4//
#define ENC4_PIN_A 11
#define ENC4_BUTTON 12
#define ENC4_PIN_B 13

//ENCODER 5//
#define ENC5_PIN_A 21
#define ENC5_BUTTON 22
#define ENC5_PIN_B 23

//ENCODER 6//
#define ENC6_PIN_A 24
#define ENC6_BUTTON 25
#define ENC6_PIN_B 26

//ENCODER 7//
#define ENC7_PIN_A 27
#define ENC7_BUTTON 28
#define ENC7_PIN_B 29

//ENCODER 8//
#define ENC8_PIN_A 30
#define ENC8_BUTTON 31
#define ENC8_PIN_B 32

//MASTER RESET//
#define MASTER_RESET 41

//LEDRING//
#define LEDRING_PIN 20
#define NUM_LEDS 96
#define LEDS_PER_ENCODER 12

//BANK BUTTONS//
#define BANK1_BUTTON 33
#define BANK2_BUTTON 34
#define BANK3_BUTTON 35
#define BANK4_BUTTON 36
#define BANK5_BUTTON 37
#define BANK6_BUTTON 38
#define BANK7_BUTTON 39
#define BANK8_BUTTON 40

//LCD//
#define LCD_SDA 18
#define LCD_SCL 19

//MIDI//
#define MIDI_RX 0
#define MIDI_TX 1
#define MIDI_CHANNEL 1
#define MIDI_DIN_SERIAL Serial1
#define MIDI_CC_START 0

//BANK PROGRAM CHANGES
#define BANK1_PROGRAM 0
#define BANK2_PROGRAM 1
#define BANK3_PROGRAM 2
#define BANK4_PROGRAM 3
#define BANK5_PROGRAM 4
#define BANK6_PROGRAM 5
#define BANK7_PROGRAM 6
#define BANK8_PROGRAM 7


//CONFIG//
//===============================================================//
struct BankConfig                                    //BANK/MIDI
{
  uint8_t buttonPin;
  uint8_t program;
};

const BankConfig bankConfigs[NUM_BANKS] =
{
  {BANK1_BUTTON, BANK1_PROGRAM},
  {BANK2_BUTTON, BANK2_PROGRAM},
  {BANK3_BUTTON, BANK3_PROGRAM},
  {BANK4_BUTTON, BANK4_PROGRAM},
  {BANK5_BUTTON, BANK5_PROGRAM},
  {BANK6_BUTTON, BANK6_PROGRAM},
  {BANK7_BUTTON, BANK7_PROGRAM},
  {BANK8_BUTTON, BANK8_PROGRAM}
};

//===============================================================//
struct EncoderConfig                                    //ENCODER
{
  uint8_t pinA;
  uint8_t pinB;
  uint8_t buttonPin;
};

const EncoderConfig encoderConfigs[NUM_ENCODERS] =
{
    {ENC1_PIN_A, ENC1_PIN_B, ENC1_BUTTON},
    {ENC2_PIN_A, ENC2_PIN_B, ENC2_BUTTON},
    {ENC3_PIN_A, ENC3_PIN_B, ENC3_BUTTON},
    {ENC4_PIN_A, ENC4_PIN_B, ENC4_BUTTON},
    {ENC5_PIN_A, ENC5_PIN_B, ENC5_BUTTON},
    {ENC6_PIN_A, ENC6_PIN_B, ENC6_BUTTON},
    {ENC7_PIN_A, ENC7_PIN_B, ENC7_BUTTON},
    {ENC8_PIN_A, ENC8_PIN_B, ENC8_BUTTON}
};