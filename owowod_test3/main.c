/**
 * OWOWOD - One Wire / One Way Output for Debugging
 *
 * @author Neven Boyanov
 *
 * This is part of the Tinusaur/OWOWOD project.
 *
 * Copyright (c) 2018 Neven Boyanov, Tinusaur Team. All Rights Reserved.
 * Distributed as open source software under MIT License, see LICENSE.txt file.
 * Retain in your source code the link http://tinusaur.org to the Tinusaur project.
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
#include "owowod/serout.h"

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
	SEROUT_INIT();

	SEROUT_CRLF(); SEROUT_STRINGLN("HELLO[OWOWOD]");	// Not really needed

	// ---- Main Loop ----
	for (;;) {
		
		// ---- Char and Strings ----
		
		SEROUT_STRING("Alphabet:");
		for (int i = 'A'; i <= 'Z'; i++) {
			SEROUT_CHAR(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();
		
		// ---- Numbers, Decimal ----

		SEROUT_STRING("NUMDEC:");
		for (int i = -123; i < 220; i += 57) {
			SEROUT_NUMDEC(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();

		SEROUT_STRING("NUMDECP:");
		for (int i = -123; i < 220; i += 57) {
			SEROUT_NUMDECP(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();

		SEROUT_STRING("NUMDECU:");
		for (int i = -123; i < 220; i += 57) {
			SEROUT_NUMDECU(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();

		SEROUT_STRING("NUMDECUP:");
		for (int i = -123; i < 220; i += 57) {
			SEROUT_NUMDECUP(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();

		// ---- Numbers, Binary ----
		
		SEROUT_STRING("NUMBINU:");
		for (uint16_t i = 0; i < 41*6+1; i += 41) {
			SEROUT_NUMBINU(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();

		SEROUT_STRING("NUMBINUPZ:");
		for (uint16_t i = 0; i < 41*6+1; i += 41) {
			SEROUT_NUMBINUPZ(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();

		SEROUT_STRING("NUMBINUW:");
		for (uint16_t i = 0; i < 15123*3+1; i += 15123) {
			SEROUT_NUMBINUW(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();

		SEROUT_STRING("NUMBINUWPZ:");
		for (uint16_t i = 0; i < 15123*3+1; i += 15123) {
			SEROUT_NUMBINUWPZ(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();

		SEROUT_CRLF();
		_delay_ms(4000);
	}

	return 0;
}

// ============================================================================
