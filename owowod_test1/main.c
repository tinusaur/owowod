/**
 * OWOWOD - One-Wire/One-Way Output for Debugging
 * @author Neven Boyanov
 * This is part of the Tinusaur/OWOWOD project.
 * ----------------------------------------------------------------------------
 *  Copyright (c) 2021 Tinusaur (https://tinusaur.com). All rights reserved.
 *  Distributed as open source under the MIT License (see the LICENSE.txt file)
 *  Please, retain in your work a link to the Tinusaur project website.
 * ----------------------------------------------------------------------------
 * Source code available at: https://gitlab.com/tinusaur/owowod
 */

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

#include "owowod/owowod.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                  ATtiny85
//                +----------+    (-)--GND--
//       (RST)--> + PB5  Vcc +----(+)--VCC--
//   [OWOWOD]--<--+ PB3  PB2 +--------------
//  --------------+ PB4  PB1 +--------------
//  --GND--(-)----+ GND  PB0 +--------------
//                +----------+
//                  Tinusaur
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(void) {
	// ---- Init ----
	owowod_init();

	// ---- Main Loop ----
	uint8_t num = 0;
	for (;;) { // The infinite main loop

		owowod_print_char('A');
		owowod_print_string("\r\n");
		// owowod_print_char(0x55);	// 0x55='U' 0xAA='ª'
		// owowod_print_char(0xAA);	// 0x55='U' 0xAA='ª'
		// owowod_print_string("\r\n");

		owowod_print_string("Hello!\r\n");

		owowod_print_numdec(1); owowod_print_string("\r\n");
		owowod_print_numdecp(2); owowod_print_string("\r\n");

		owowod_print_string("A="); owowod_print_numdec(123); owowod_print_string("\r\n");
		owowod_print_string("B="); owowod_print_numdec(45678); owowod_print_string("\r\n");
		owowod_print_string("C="); owowod_print_numdec(-901); owowod_print_string("\r\n");
		owowod_print_string("D="); owowod_print_numdec(-23456); owowod_print_string("\r\n");

		owowod_print_string("E="); owowod_print_numdecu(123); owowod_print_string("\r\n");
		owowod_print_string("F="); owowod_print_numdecu(45678); owowod_print_string("\r\n");
		owowod_print_string("G="); owowod_print_numdecu(-901); owowod_print_string("\r\n");
		owowod_print_string("H="); owowod_print_numdecu(-23456); owowod_print_string("\r\n");

		owowod_print_string("I="); owowod_print_numdecp(123); owowod_print_string("\r\n");
		owowod_print_string("J="); owowod_print_numdecp(45678); owowod_print_string("\r\n");
		owowod_print_string("K="); owowod_print_numdecp(-901); owowod_print_string("\r\n");
		owowod_print_string("L="); owowod_print_numdecp(-23456); owowod_print_string("\r\n");

		owowod_print_string("M="); owowod_print_numdecup(123); owowod_print_string("\r\n");
		owowod_print_string("N="); owowod_print_numdecup(45678); owowod_print_string("\r\n");
		owowod_print_string("O="); owowod_print_numdecup(-901); owowod_print_string("\r\n");
		owowod_print_string("P="); owowod_print_numdecup(-23456); owowod_print_string("\r\n");

		owowod_print_numdecu(num);
		owowod_print_string(":\r\n");

		for (uint8_t i = 0; i <= 255 - 32; i++) {	// number of iterations: 95, 127, 254
			owowod_print_char(' ' + i);	// prints character that is after ' ' (space) in the ASCII table.
			if ((i & 0x1f) == 0x1f) owowod_print_string("\r\n");
		}

		owowod_print_string("\r\n---- Good-bye ----\r\n\r\n");
		_delay_ms(2000);
		num++;
	}

	return 0; // Return the mandatory for the "main" function int value - "0" for success.
}

// ============================================================================
