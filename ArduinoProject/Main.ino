#include "Controller.h"
#include "Startup.h"
#include "Logger.h"

Logger logger;
Controller midicontroller(&logger);
Startup startup;

enum State
{
  STARTUP,
  NORMAL
};

State state = STARTUP;


void setup() 
{
  logger.begin();
  logger.info("Controller", "Controller gestart");

  startup.begin(midicontroller.getStrip());

}

void loop() 
{
  midicontroller.update();
  switch(state)
  {
    case STARTUP:
    {
      startup.welcomeLed();

      if(startup.finished())
      {
        startup.end();
        midicontroller.setBank(0);
        state = NORMAL;
      }

      break;
    }

    case NORMAL:
    {
      midicontroller.update();

      break;
    }
  }
}