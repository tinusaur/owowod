OWOWOD - One Wire / One Way Output for Debugging

This is a small library that allows you to create one-wire, one-way debugging/printing connection from ATtiny85 to another device, such as computer, using serial protocol.

One example would be printing debugging information from a microcontroller to a developer machine. The will work like this:
- The library will output the debugging text using just one wire, let's say through PB3 pin.
- Using USB-to-Serial (TTL) converter that goes to the computer as if it comes from a COM port.
- Using COM port monitoring program or terminal will show the debugging text on the screen of the computer.

This was developed and test with the following microcontrollers: ATtiny85, ATtiny45, ATtiny25.

This was tested to work with following USB-to-Serial chips: PL2303; CH340G.

Project page: http://tinusaur.org/projects/owowod/
Source code: https://bitbucket.org/tinusaur/owowod

