# OWOWOD

OWOWOD - One-Wire/One-Way Output for Debugging

OWOWOD is a small library that allows you to create a one-wire, one-way debugging/printing connection from ATtiny85 to another device, such as a computer, using standard serial protocol. This library is written in plain C.

    Copyright (c) 2021 Tinusaur (https://tinusaur.com). All rights reserved.
    Distributed as open source under the MIT License (see the LICENSE.txt file).
    Please, retain in your work a link to the Tinusaur project website.

- OWOWOD source code:   https://gitlab.com/tinusaur/owowod
- OWOWOD project page:  https://tinusaur.org/projects/owowod/

NOTE: This project was developed and tested the ATtiny85 microcontrollers. It might or might not work in other environments.

- Tinusaur website: https://tinusaur.org
- Tinusaur on Twitter: https://twitter.com/tinusaur
- Tinusaur on Facebook: https://www.facebook.com/tinusaur

-------------------------------------------------------------------------------

Folders and modules:

- owowod			- The library source code files.
- owowod_cpufreq1	- Testing scripts for different CPU frequencies and baud rates.
- owowod_debug1		- Testing scripts for the "debugging" functions.
- owowod_legacy		- Some legacy files, wil be removed.
- owowod_numbin1	- Testing scripts for the library - Binary numers
- owowod_numdec1	- Testing scripts for the library - Decimal numbers
- owowod_numhex1	- Testing scripts for the library - Hexadecimal numbers
- owowod_serout1	- Testing scripts for the "serout" functions.
- owowod_test1		- Testing scripts for the library.

-------------------------------------------------------------------------------

## How does it works?

One example would be printing debugging information from a microcontroller to a developer machine, i.e. your laptop. That will work like this:
- The library will output the debugging text using just one wire, let's say via PB3 pin.
- A USB-to-Serial (TTL) converter receives that signal via its RX pin and passes this to the computer.
- A COM port monitoring program or terminal (such as RealTerm) will show the debugging text on the screen of the computer.

![Tinusaur OWOWOD Library Diagram](/media/Tinusaur-OWOWOD-Diagram.png "Tinusaur OWOWOD Library Diagram")*Tinusaur OWOWOD Library Diagram*


-------------------------------------------------------------------------------

## Compatibility

- MCU: This library was developed and tested with the following microcontrollers: ATtiny85, ATtiny45, ATtiny25.
- CPU FREQUENCY: This library has support and was tested work at 1 MHz and 8 MHz CPU clock mode.
- SERIAL: This library was tested to work with following USB-to-Serial chips: CH340G, PL2303.

-------------------------------------------------------------------------------

