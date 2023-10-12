
# RC Transmitter Receiver System

## Overview

This project has the design files for a custom Remote Control (RC) system that you can use to control different models. The design files include:

- Schematics and PCB design for the transmitter and receiver boards.
- The source code for the microcontrollers on the transmitter and receiver boards.
- A sample 3D printable model for an RC car.

Please note that this is just the initial proof of concept, and more updates are on the way to make it even better.

## Project organization

- **hardware/** - In this folder, you'll find the circuit schematics and PCB design files for both the receiver and transmitter boards.
- **software/attiny824-transmiter** - This contains the source code for the ATTiny824 chip on the transmitter board.
- **software/attiny824-receiver** - Here, you'll find the source code for the ATTiny824 chip on the receiver board.
- **rc-car-frame.FCStd** - This file holds a 3D model of an RC car frame that we used for testing in this project.

## Development tools

- **[Microchip Studio 7.0](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio)**: The IDE for writing and building source code for the ATTiny chip. We also use this tool to flash the chips.
- **[ATMEL-ICE](https://www.microchip.com/en-us/development-tool/ATATMEL-ICE)**: Hardware tool for flashing ATTiny chips.
- **[KiCad EDA](https://www.kicad.org/)**: The application for schematic and PCB design.
- **[FreeCAD](https://www.freecad.org/)**: The application for parametric desing used to desing the model.

To build the ATTiny824 firmware, open the project in Microchip Studio. Build the solution to generate the `*.HEX` file. Next, use the appropriate tool available to flash the chip.

## BOM
| # | Components | Recommended models | Footprint | Quantity |
| --- | --- | --- | --- | --- |
| 1 | PCB | Recommended two-layer PCB board of 1.6 mm thickness | | 1 |
| 2 | U1, U2 | ATtiny824 | SOIC-14 | 2 |
| 3 | C1, C2 | 100nF | 0603 (1608 metric) | 2 |
| 4 | D1, D3 | SMD LED | 0603 (1608 metric) | 2 |
| 5 | D2, D4 | SMD Generic diode | MicroMELF | 2 |
| 6 | Q1-Q6 | 2N7002 | SOT-23 | 6 |
| 7 | R1, R2, R4, R5, R6, R7, R9, R12, R13, R18, R19, R20  | 10K | 0603 (1608 metric) | 12 |
| 8 | R3, R14  | 470 | 0603 (1608 metric) | 2 |
| 9 | R8, R10, R11, R15, R16, R17  | 100 | 0603 (1608 metric) | 6 |
| 10 | RV1 | 10K Slide Potentiometer | PTA1543 | 1 |
| 11 | RV2 | 10K Potentiometer | T-16H Single Horizontal | 1 |
| 12 | SW1, SW2, SW3, SW4, SW5, SW6 | SPDT Slide Switch | P2.54mm | 6 |
| 13 | J1 | Male Header Connector, 1x3, pitch 2.54mm | 	1x3 - P2.54mm | 1 |
| 14 | J2, J5, J6, J7, J9, J10, J11, J12, J13, J14, J15, J17, J18, J19 | Male Header Connector, 1x2, pitch 2.54mm | 	1x2 - P2.54mm | 14 |
| 15 | J3, J16 | Male Header Connector, 2x3, pitch 2.54mm | 	2x3 - P2.54mm | 2 |
| 16 | J8 | Male Header Connector, 1x4, pitch 2.54mm | 	1x4 - P2.54mm | 1 |


## Documentation

For more detailed information about the board and the I2C protocol, please visit the [project page](https://fibstack.com/projects/rc-model-controller/).

## License Information
This product is open source!

Please review the LICENSE.md file for license information. Distributed as-is; no warranty is given.