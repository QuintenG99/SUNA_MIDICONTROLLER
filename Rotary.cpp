#include "Rotary.h"

#include <Encoder.h>

Rotary::Rotary()
{
  encoder = nullptr;

  value = 0;
  lastRaw = 0;
}

void Rotary::begin(uint8_t pinA, uint8_t pinB)
{
  this->pinA = pinA;
  this->pinB = pinB;

  encoder = new Encoder(pinA, pinB);

  value = 0;
  lastRaw = 0;
}

Rotary::~Rotary()
{
  delete encoder;
}

void Rotary::update()
{
  long raw = encoder->read();
  long delta = raw - lastRaw;

  // kijkt naar de clicks als je draait//
  if (abs(delta) >= encoderSteps)         
  {
    int clicks = delta / encoderSteps;

    lastRaw += clicks * encoderSteps;

    //acceleratie//
    int step = clicks;

    if (abs(clicks) >= 4)
    {
      step *= 2;
    }

   /* if (step > 6)
    {   
      step = 8;
    }
    else if (step < -6)
    {
      step = -8;
    }*/

    value += step;
    value = constrain(value, 0, 127);     // begrenst de waarde tussen 0-127
  }
}

int Rotary::getValue()
{
  return value; //encapsulatie naar public zodat andere objecten de value kunnen gebruiken
}

void Rotary::setValue(int value)
{
  this-> value = constrain(value, 0, 127);

  encoder->write(this->value * encoderSteps);
  lastRaw = this->value * encoderSteps;
}

void Rotary::reset()
{
  value = 0;
  encoder->write(0);
  lastRaw = 0;
}