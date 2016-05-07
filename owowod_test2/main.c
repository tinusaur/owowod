/**
 * OWOWOD - One Wire / One Way Output for Debugging
 *
 * @created 2014-11-21
 * @author Neven Boyanov
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

// #define F_CPU 1000000UL
// NOTE: The F_CPU (CPU frequency) should not be defined in the source code.
//       It should be defined in either (1) Makefile; or (2) in the IDE. 

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

// Change the OWOWOD port, if necessary.
// #define OWOWOD_PORT	PB3	// OWOWOD port

#include "owowod/owowod.h"
#include "owowod/debugging.h"

//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                ATtiny
//               25/45/85
//              +----------+
//      (RST)---+ PB5  Vcc +---(+)-------
// --[OWOWOD]---+ PB3  PB2 +---
//           ---+ PB4  PB1 +---
// -------(-)---+ GND  PB0 +---
//              +----------+
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

// ----------------------------------------------------------------------------

int main(void) {

	// ---- Initialization ----
	DEBUGGING_INIT();

	DEBUGGING_CRLF(); DEBUGGING_STRINGLN("HELLO[OWOWOD]");	// Not really needed
	
	DEBUGGING_STRING("Some testing here ...");
	DEBUGGING_CRLF();

	// ---- Main Loop ----
	uint8_t num = 0;
	for (;;) {
		for (char ch = 'A'; ch <= 'Z'; ch++) DEBUGGING_CHAR(ch);
		DEBUGGING_CRLF();

		DEBUGGING_NUMDEC(-123); DEBUGGING_CRLF();
		DEBUGGING_NUMDECP(-4567); DEBUGGING_CRLF();
		DEBUGGING_NUMDECU(123); DEBUGGING_CRLF();
		DEBUGGING_NUMDECUP(4567); DEBUGGING_CRLF();

		DEBUGGING_CRLF();

		DEBUGGING_VAR("A", 123);
		DEBUGGING_VAR("B", 45678);
		DEBUGGING_VAR("C", -901);
		DEBUGGING_VAR("D", -23456);

		DEBUGGING_VARU("E", 123);
		DEBUGGING_VARU("F", 45678);
		DEBUGGING_VARU("G", -901);
		DEBUGGING_VARU("H", -23456);

		DEBUGGING_CRLF();

		DEBUGGING_NUMBINU(0x12); DEBUGGING_CRLF();
		DEBUGGING_NUMBINUPZ(0x34); DEBUGGING_CRLF();
		DEBUGGING_NUMBINUW(0x1234); DEBUGGING_CRLF();
		DEBUGGING_NUMBINUWPZ(0x5678); DEBUGGING_CRLF();

		DEBUGGING_CRLF();
		
		for (uint16_t n = 0; n < 0xff; n += 0x34) DEBUGGING_VARBINUPZ("X", n);

		DEBUGGING_CRLF();

		for (uint16_t n = 0; n < 0x2fff; n += 0x1234) DEBUGGING_VARBINUWPZ("Y", n);

		DEBUGGING_CRLF();

		DEBUGGING_ERROR(123, "Hardware");

		DEBUGGING_CRLF();

		_delay_ms(2000);
		num++;
	}

	return 0;
}

// ============================================================================
