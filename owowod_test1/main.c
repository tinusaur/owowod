/**
 * OWOWOD - One Wire / One Way Output for Debugging
 *
 * @created: 2014-11-21
 * @author: Neven Boyanov
 *
 * This is part of the Tinusaur/OWOWOD project.
 *
 * Copyright (c) 2016 Neven Boyanov, Tinusaur Team. All Rights Reserved.
 * Distributed as open source software under MIT License, see LICENSE.txt file.
 * Please, as a favor, retain the link http://tinusaur.org to The Tinusaur Project.
 *
 * Source code available at: https://bitbucket.org/tinusaur/owowod
 *
 */

// ============================================================================

#define F_CPU 1000000UL

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                ATtiny
//               25/45/85
//              +----------+
//        RST --+ PB5  Vcc +---(+)-------
// ----OWOWOD---+ PB3  PB2 +--
//            --+ PB4  PB1 +--
// -------(-)---+ GND  PB0 +--
//              +----------+
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#define OWOWOD_PORT	PB3	// OWOWOD Port

// ----------------------------------------------------------------------------

#include "../owowod/owowod.h"

// ============================================================================

int main(void) {

	// ---- Initialization ----
	owowod_init();

	// ---- Main Loop ----
	uint8_t num = 0;
	for (;;) {

		owowod_print_char('A');
		owowod_print_char('\n');
		// owowod_print_char(0x55);	// 0x55='U' 0xAA='ª'
		// owowod_print_char(0xAA);	// 0x55='U' 0xAA='ª'
		// owowod_print_char('\n');

		owowod_print_string("Hello!\n");

		owowod_print_numdec(1); owowod_print_char('\n');
		owowod_print_numdecp(2); owowod_print_char('\n');

		owowod_print_string("A="); owowod_print_numdec(123); owowod_print_char('\n');
		owowod_print_string("B="); owowod_print_numdec(45678); owowod_print_char('\n');
		owowod_print_string("A="); owowod_print_numdec(-678); owowod_print_char('\n');
		owowod_print_string("B="); owowod_print_numdec(-12345); owowod_print_char('\n');

		owowod_print_string("A="); owowod_print_numdecu(123); owowod_print_char('\n');
		owowod_print_string("B="); owowod_print_numdecu(45678); owowod_print_char('\n');
		owowod_print_string("A="); owowod_print_numdecu(-678); owowod_print_char('\n');
		owowod_print_string("B="); owowod_print_numdecu(-12345); owowod_print_char('\n');

		owowod_print_string("X="); owowod_print_numdecp(1); owowod_print_char('\n');
		owowod_print_string("Y="); owowod_print_numdecp(23); owowod_print_char('\n');
		owowod_print_string("Z="); owowod_print_numdecp(45678); owowod_print_char('\n');
		owowod_print_string("X="); owowod_print_numdecp(-9); owowod_print_char('\n');
		owowod_print_string("Y="); owowod_print_numdecp(-78); owowod_print_char('\n');
		owowod_print_string("Z="); owowod_print_numdecp(-23456); owowod_print_char('\n');

		owowod_print_string("X="); owowod_print_numdecup(1); owowod_print_char('\n');
		owowod_print_string("Y="); owowod_print_numdecup(23); owowod_print_char('\n');
		owowod_print_string("Z="); owowod_print_numdecup(45678); owowod_print_char('\n');
		owowod_print_string("X="); owowod_print_numdecup(-9); owowod_print_char('\n');
		owowod_print_string("Y="); owowod_print_numdecup(-78); owowod_print_char('\n');
		owowod_print_string("Z="); owowod_print_numdecup(-23456); owowod_print_char('\n');

		owowod_print_char('\n');

		owowod_print_numdecup(num);
		owowod_print_string(": ");

		for (uint8_t i = 0; i < 95; i++) {	// number of iterations: 95, 127, 254
			owowod_print_char(' ' + i);	// prints character that is after ' ' (space) in the ASCII table.
			owowod_print_char(' ');
		}
		owowod_print_string("\n");

		owowod_print_string("Good-bye.\n");

		owowod_print_string("----------------\n\n");
		_delay_ms(2000);
		num++;
	}

	return 0;
}

// ============================================================================
