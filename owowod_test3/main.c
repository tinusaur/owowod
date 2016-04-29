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

#include <stdint.h>
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

#include <avr/io.h>

#include "../owowod/owowod.h"
#include "../owowod/serout.h"

// ============================================================================

int main(void) {

	// ---- Initialization ----
	SEROUT_INIT();
	SEROUT_STRINGLN("Testing");
		
	for (;;) {
		
		// ---- Strings ----
		
		SEROUT_STRING("Alphabet:");
		for (int i = 65; i < 91; i++) {
			SEROUT_CHAR(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();
		
		// ---- Decimal ----

		SEROUT_STRING("NUMDEC:");
		for (int i = -111; i < 120; i += 17) {
			SEROUT_NUMDEC(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();

		SEROUT_STRING("NUMDECP:");
		for (int i = -111; i < 120; i += 17) {
			SEROUT_NUMDECP(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();

		SEROUT_STRING("NUMDECU:");
		for (int i = -111; i < 120; i += 17) {
			SEROUT_NUMDECU(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();

		SEROUT_STRING("NUMDECUP:");
		for (int i = -111; i < 120; i += 17) {
			SEROUT_NUMDECUP(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();

		// ---- Binary ----
		
		SEROUT_STRING("NUMBINU:");
		for (uint16_t i = 2; i < 60000; i += 4999) {
			SEROUT_NUMBINU(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();

		SEROUT_STRING("NUMBINUPZ:");
		for (uint16_t i = 2; i < 60000; i += 4999) {
			SEROUT_NUMBINUPZ(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();

		SEROUT_STRING("NUMBINUW:");
		for (uint16_t i = 2; i < 60000; i += 4999) {
			SEROUT_NUMBINUW(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();

		SEROUT_STRING("NUMBINUWPZ:");
		for (uint16_t i = 2; i < 60000; i += 4999) {
			SEROUT_NUMBINUWPZ(i); SEROUT_STRING(",");
		}
		SEROUT_CRLF();

		SEROUT_CRLF();
		_delay_ms(4000);
	}

	SEROUT_CRLF();
	return 0;
}

// ============================================================================
