# atusbprog

This project is intended as an exercise in learning about the following:

- Silicon Labs EFM8UB1 USB-enabled 8051 microcontroller
- Simplicity Studio for programming the EFM8UB1
- LibUSB on Linux (and possibly Windows?)
- USB in general i.e. for interacting with a microcontroller
- KiCAD design of a daughter card for the EFM8UB1 SLSTK2000A 

# Status

Currently, this project is in the very early stages where only experimentation between Linux and the SLSTK2000A have been done to toggle some LEDs, etc.

This will eventually be used as the foundation of a command/response type device that can be used to program Atmel microcontrollers (currently looking at supporting the AT89S52 and/or some simple AVR micros). In order to accomplish this, a daughter card with one of these microcontrollers will be designed to be plugged into the side of an SLSTK2000A as an exercise in PCB design. This is not strictly required, per-se as the micros can be wired over to a breadboard, but the PCB design will prove to be a useful learning experience.
