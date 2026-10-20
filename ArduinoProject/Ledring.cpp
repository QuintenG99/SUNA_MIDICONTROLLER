#include "Ledring.h"

Ledring::Ledring()
{
  strip = nullptr;
  startLed = 0;
  numLeds = 0;
  color = 0;
}

void Ledring::begin(Adafruit_NeoPixel* strip, uint8_t startLed, uint8_t numLeds)
{
  this->strip = strip;
  this->startLed = startLed;
  this->numLeds = numLeds;
}

void Ledring::setValue(int value)
{
  int level = map(value, 30, 127, 0, numLeds);

  level = constrain(level, 0, numLeds);


  //debug//
  Serial.print("LED VALUE: ");
  Serial.println(value);      //test

  Serial.print(" LEVEL: ");
  Serial.println(level);    //test

  Serial.print("COLOR: ");
  Serial.println(color); //test
  
  Serial.print(" NUM: ");
  Serial.println(numLeds); //test

  Serial.print("START: ");
  Serial.println(startLed); //test



  // Eigen leds eerst uitzetten
  for(int i = 0; i < numLeds; i++)
  {
    strip->setPixelColor(startLed + i, 0); 
  }

  //nieuwe waarde erin steken
  for(int i = 0; i < level; i++)
  {
    strip->setPixelColor(startLed + i, color); 
  }

  strip->show();      //test
}


void Ledring::setColor(uint32_t color)
{
  this->color = color;
}

void Ledring::clear()
{
  for(int i = 0; i < numLeds; i++)
  {
    strip->setPixelColor(startLed + i, 0);
  }
}
