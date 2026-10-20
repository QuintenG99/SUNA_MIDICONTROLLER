# SUNA MIDI Controller

A custom-built Arduino-based USB MIDI controller for hands-on control of music production software. Created for the Music band SUNA 

https://vi.be/platform/SUNA

---
## About

SUNA MIDI Controller is a DIY hardware project focused on combining embedded C++, physical controls and visual feedback in a modular MIDI control surface.

The firmware is organized into reusable C++ classes, separating controller logic, MIDI communication, encoder input, bank management and display feedback.

## Features

- 8 banks with 8 rotary encoders each
    
- 64 controllable parameters
    
- Encoder buttons for additional controls
    
- Dedicated bank-selection buttons
    
- Master-reset controls
    
- WS2812 LED rings for visual feedback
    
- LCD display
    
- MIDI values from 0 to 127
    
- Modular, object-oriented C++ firmware
    

## Hardware

The controller combines an Arduino-compatible microcontroller, rotary encoders, addressable LEDs, buttons, toggle switches and an LCD.

The hardware front panel was designed in Autodesk Fusion 360.

Detailed hardware specifications, wiring diagrams, pin assignments, and Fusion 360 design files will be added to the repository as the project develops.

## Software architecture

The firmware is divided into separate modules:

- `Controller` — overall controller logic
    
- `Midi` — MIDI communication
    
- `Bank` — bank management
    
- `Enc` and `Rotary` — encoder handling
    
- `Button` — button input
    
- `Ledring` — LED feedback
    
- `Lcd` — display output
    
- `Logger` — debugging and logging
    
- `Startup` — startup behaviour
    

## Repository structure

```
SUNA_MIDICONTROLLER/
├── README.md
└── ArduinoProject/
    ├── Main.ino
    ├── Bank.cpp
    ├── Bank.h
    ├── Button.cpp
    ├── Button.h
    ├── Controller.cpp
    ├── Controller.h
    ├── Enc.cpp
    ├── Enc.h
    ├── Lcd.cpp
    ├── Lcd.h
    ├── Ledring.cpp
    ├── Ledring.h
    ├── Logger.cpp
    ├── Logger.h
    ├── Macro.h
    ├── Midi.cpp
    ├── Midi.h
    ├── Rotary.cpp
    ├── Rotary.h
    ├── Startup.cpp
    └── Startup.h
```

## Getting started

1. Clone this repository.
    
2. Open the Arduino project in the Arduino IDE.
    
3. Install the required libraries.
    
4. Select the appropriate board and USB MIDI configuration.
    
5. Connect the hardware and upload the firmware.
    

The exact board configuration, dependencies and wiring instructions still need to be documented.

## Project status

Work in progress.

## License

No license has been selected yet.