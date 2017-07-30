OWOWOD - One Wire / One Way Output for Debugging

-----------------------------------------------------------------------------------
 Copyright (c) 2017 Neven Boyanov, The Tinusaur Team. All Rights Reserved.
 Distributed as open source software under MIT License, see LICENSE.txt file.
 Retain in your source code the link http://tinusaur.org to the Tinusaur project.
-----------------------------------------------------------------------------------

This is a small library that allows you to create one-wire, one-way debugging/printing connection from ATtiny85 to another device, such as computer, using serial protocol.

One example would be printing debugging information from a microcontroller to a developer machine. The will work like this:
- The library will output the debugging text using just one wire, let's say through PB3 pin.
- Using USB-to-Serial (TTL) converter that goes to the computer as if it comes from a COM port.
- Using COM port monitoring program or terminal will show the debugging text on the screen of the computer.

This library has support for and tested work with the 8 MHz CPU clock mode.

Folders and modules:
- owowod            - The library source code
- owowod_test1      - Testing scripts for the library
- owowod_test2      - Testing scripts for the "debugging" functions.
- owowod_test3      - Testing scripts for the "serout" functions.
- owowod_test4      - Testing scripts for different CPU frequencies and baud rates.

This was developed with and tested on the following microcontrollers: ATtiny85, ATtiny45, ATtiny25.

This was tested to work with following USB-to-Serial chips: PL2303, CH340G.

This library is written in plain C.

==== Links ====

Official Tinusaur Project website: http://tinusaur.org
Project OWOWOD page: http://tinusaur.org/projects/owowod/
Project OWOWOD source code: https://bitbucket.org/tinusaur/owowod

Twitter: https://twitter.com/tinusaur
Facebook: https://www.facebook.com/tinusaur

