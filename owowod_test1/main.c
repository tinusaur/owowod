/**
 * OWOWOD - One-Wire/One-Way Output for Debugging
 * @author Neven Boyanov
 * This is part of the Tinusaur/OWOWOD project.
 * ----------------------------------------------------------------------------
 *  Copyright (c) 2022 Tinusaur (https://tinusaur.com). All rights reserved.
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
		owowod_print_char('#');
		owowod_print_char('>');
		owowod_print_char(' ');
		owowod_print_string("Hello, World!");
		owowod_print_char(0x20);	// 0x20=' '
		owowod_print_char(0x55);	// 0x55='U'
		owowod_print_char(0xAA);	// 0xAA='ª'
		owowod_print_string("\r\n");
		for (uint8_t i = 32; i <= 32 + 26; i++) {
			owowod_print_char(' ' + i);	// prints character that is after ' ' (space) in the ASCII table.
		}
		owowod_print_string("\r\n");
		owowod_print_string("Good-bye!\r\n\r\n");
		_delay_ms(2000);
	}

	return 0; // Return the mandatory for the "main" function int value - "0" for success.
}

// ============================================================================
