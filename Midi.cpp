#include "Midi.h"
#include "Macro.h"


Midi::Midi()
{

}

void Midi::begin()
{
  usbMIDI.begin();
  MIDI_DIN_SERIAL.begin(31250);
}

void Midi::sendCC(uint8_t cc, uint8_t value)
{
  usbMIDI.sendControlChange(cc, value, MIDI_CHANNEL);

  MIDI_DIN_SERIAL.write(0xB0 | (MIDI_CHANNEL - 1));
  MIDI_DIN_SERIAL.write(cc);
  MIDI_DIN_SERIAL.write(value);
}

void Midi::sendProgramChange(uint8_t program)
{
  usbMIDI.sendProgramChange(program, MIDI_CHANNEL);

  MIDI_DIN_SERIAL.write(0xC0 | (MIDI_CHANNEL - 1));
  MIDI_DIN_SERIAL.write(program);
}

void Midi::sendEncoderCC(uint8_t bank, uint8_t encoder, uint8_t value)
{
  uint8_t cc = MIDI_CC_START + (bank * NUM_ENCODERS) + encoder;

  sendCC(cc, value);
}

void Midi::sendButtonCC(uint8_t bank, uint8_t button, uint8_t value)
{
  uint8_t cc = MIDI_CC_START + (bank * NUM_ENCODERS * 2) + NUM_ENCODERS + button;

  sendCC(cc, value);
}