#include "Startup.h"
#include "Macro.h"

Startup::Startup()
{
  flashTime = 0;
  flashState = false;
  startTime = 0;
}

void Startup::begin(Adafruit_NeoPixel* strip)
{
  this->strip = strip;
  startTime = millis();
}

void Startup::welcomeLed()
{
  if(millis() - flashTime >= 500)
  {
    flashTime = millis();
    flashState = !flashState;
  }

  uint32_t colors[NUM_BANKS] =
  {
    strip->Color(BANK1_COLOR),
    strip->Color(BANK2_COLOR),
    strip->Color(BANK3_COLOR),
    strip->Color(BANK4_COLOR),
    strip->Color(BANK5_COLOR),
    strip->Color(BANK6_COLOR),
    strip->Color(BANK7_COLOR),
    strip->Color(BANK8_COLOR)
  };

  for(int i = 0; i < NUM_ENCODERS; i++)
  {
    for(int j = 0; j < LEDS_PER_ENCODER; j++)
    {
      if(flashState)
      {
        strip->setPixelColor(
          i * LEDS_PER_ENCODER + j,
          colors[i]
        );
      }
      else
      {
        strip->setPixelColor(
          i * LEDS_PER_ENCODER + j,
          0
        );
      }
    }
  }

  strip->show();
}

bool Startup::finished()
{
  return millis() - startTime >= 5000;
}

void Startup::end()
{
  for(int i = 0; i < NUM_LEDS; i++)
  {
    strip->setPixelColor(i, 0);
  }

  strip->show();
}