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
#include "owowod/debugging.h"

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
	DEBUGGING_INIT();

	// ---- Main Loop ----
	for (;;) {
		DEBUGGING_CHAR(':');
		DEBUGGING_CHAR(')');
		DEBUGGING_CHAR(0x20);
		DEBUGGING_STRING("HELLO!");
		DEBUGGING_CRLF();

		for (char ch = 'A'; ch <= 'Z'; ch++) DEBUGGING_CHAR(ch);
		DEBUGGING_CRLF();

		DEBUGGING_STRINGLN("----NUMDEC----");
		DEBUGGING_NUMDEC(123); DEBUGGING_CRLF();
		DEBUGGING_NUMDEC(-123); DEBUGGING_CRLF();
		DEBUGGING_NUMDECP(4567); DEBUGGING_CRLF();
		DEBUGGING_NUMDECP(-4567); DEBUGGING_CRLF();
		DEBUGGING_NUMDECU(123); DEBUGGING_CRLF();
		DEBUGGING_NUMDECUP(4567); DEBUGGING_CRLF();

		DEBUGGING_STRINGLN("----ERROR----");
		DEBUGGING_ERROR(123, "CHK");

		DEBUGGING_STRINGLN("----VAR----");
		DEBUGGING_VAR("A", 123);
		DEBUGGING_VAR("B", 45678);
		DEBUGGING_VAR("C", -901);
		DEBUGGING_VAR("D", -23456);
		DEBUGGING_VARU("E", 123);
		DEBUGGING_VARU("F", 45678);
		DEBUGGING_VARU("G", -901);
		DEBUGGING_VARU("H", -23456);
		DEBUGGING_CRLF();

		DEBUGGING_STRINGLN("----NUMHEX----");
		DEBUGGING_NUMHEXUPZ(1); DEBUGGING_CRLF();
		DEBUGGING_NUMHEXUPZ(234); DEBUGGING_CRLF();
		DEBUGGING_NUMHEXUPZ(-123); DEBUGGING_CRLF();
		DEBUGGING_NUMHEXUWPZ(1234); DEBUGGING_CRLF();
		DEBUGGING_NUMHEXUWPZ(56789); DEBUGGING_CRLF();
		DEBUGGING_NUMHEXUWPZ(-23456); DEBUGGING_CRLF();

		DEBUGGING_STRINGLN("----VARHEX----");
		DEBUGGING_VARHEXUPZ("A", 1);
		DEBUGGING_VARHEXUPZ("B", 123);
		DEBUGGING_VARHEXUPZ("C", -123);
		DEBUGGING_VARHEXUWPZ("D", 1234);
		DEBUGGING_VARHEXUWPZ("E", 56789);
		DEBUGGING_VARHEXUWPZ("F", -23456);
		DEBUGGING_CRLF();

		DEBUGGING_STRINGLN("----NUMBIN----");
		DEBUGGING_NUMBINU(0x12); DEBUGGING_CRLF();
		DEBUGGING_NUMBINUPZ(0x34); DEBUGGING_CRLF();
		DEBUGGING_NUMBINUW(0x1234); DEBUGGING_CRLF();
		DEBUGGING_NUMBINUWPZ(0x5678); DEBUGGING_CRLF();

		DEBUGGING_STRINGLN("----VARBIN----");
		for (uint16_t n = 0; n < 0xff; n += 0x34) DEBUGGING_VARBINUPZ("X", n);
		DEBUGGING_CRLF();
		for (uint16_t n = 0; n < 0x2fff; n += 0x1234) DEBUGGING_VARBINUWPZ("Y", n);
		DEBUGGING_CRLF();

		DEBUGGING_STRINGLN("--------[Good-bye!]--------");
		DEBUGGING_CRLF();
		_delay_ms(2000);
	}

	return 0;
}

// ============================================================================
