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
	for (;;) { // The infinite main loop
		owowod_print_string("Hello!\r\n");

		owowod_print_string("A="); owowod_print_numhexupz(1); owowod_print_string("\r\n");
		owowod_print_string("B="); owowod_print_numhexupz(234); owowod_print_string("\r\n");
		owowod_print_string("C="); owowod_print_numhexupz(-56); owowod_print_string("\r\n");

		owowod_print_string("D="); owowod_print_numhexuwpz(1234); owowod_print_string("\r\n");
		owowod_print_string("E="); owowod_print_numhexuwpz(56789); owowod_print_string("\r\n");
		owowod_print_string("F="); owowod_print_numhexuwpz(-12345); owowod_print_string("\r\n");

		owowod_print_string("\r\n--------[Good-bye!]--------\r\n\r\n");
		_delay_ms(2000);
	}

	return 0; // Return the mandatory for the "main" function int value - "0" for success.
}

// ============================================================================
