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
#include "owowod/serout.h"

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
	SEROUT_INIT();

	// ---- Main Loop ----
	for (;;) {
		SEROUT_CHAR(':');
		SEROUT_CHAR(')');
		SEROUT_CHAR(0x20);
		SEROUT_STRING("HELLO!");
		SEROUT_CRLF();

		for (char ch = 'A'; ch <= 'Z'; ch++) SEROUT_CHAR(ch);
		SEROUT_CRLF();

		SEROUT_STRINGLN("----NUMDEC----");
		SEROUT_NUMDEC(123); SEROUT_CRLF();
		SEROUT_NUMDEC(-123); SEROUT_CRLF();
		SEROUT_NUMDECP(4567); SEROUT_CRLF();
		SEROUT_NUMDECP(-4567); SEROUT_CRLF();
		SEROUT_NUMDECU(123); SEROUT_CRLF();
		SEROUT_NUMDECUP(4567); SEROUT_CRLF();

		SEROUT_STRINGLN("----NUMBIN----");
		SEROUT_NUMBINU(0x12); SEROUT_CRLF();
		SEROUT_NUMBINUPZ(0x34); SEROUT_CRLF();
		SEROUT_NUMBINUW(0x1234); SEROUT_CRLF();
		SEROUT_NUMBINUWPZ(0x5678); SEROUT_CRLF();

		SEROUT_STRINGLN("--------[Good-bye!]--------");
		SEROUT_CRLF();
		_delay_ms(2000);
	}

	return 0;
}

// ============================================================================
