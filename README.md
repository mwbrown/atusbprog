# atusbprog

This project is intended as an exercise in learning about the following:

- Silicon Labs EFM8UB1 USB-enabled 8051 microcontroller
- Simplicity Studio for programming the EFM8UB1
- LibUSB on Linux (and possibly Windows?)
- USB in general i.e. for interacting with a microcontroller
- KiCAD design of a daughter card for the EFM8UB1 SLSTK2000A 

# Status

Currently, this project is in the very early stages where only experimentation between Linux and the SLSTK2000A have been done to toggle some LEDs, etc.

This will eventually be used as the foundation of a command/response type device that can be used to program Atmel microcontrollers. In order to accomplish this, a daughter card with one of these microcontrollers will be designed to be plugged into the side of an SLSTK2000A as an exercise in PCB design. This is not strictly required, per-se as the micros can be wired over to a breadboard, but the PCB design will prove to be a useful learning experience.

# Planned Device Support

Current plans for device support are AT89S series C51-based microcontrollers, due to their simple SPI-based programming protocol. If flash space allows, a potential addition would be supporting AVR serial programming.

A preliminary list of devices is:

* AT89S52
  - This will require some level-shifting due to the required 5V supply.
* AT89S8253
  - This can interface directly with the EFM8UB1 due to both being 3.3V chips.