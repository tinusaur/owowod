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
#include "owowod/debugging.h"
#include "tinyavrlib/cpufreq.h"

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
	
	// ---- Setup CPU Frequency ----
#if F_CPU == 1000000UL
#pragma message "F_CPU=1MHZ"
	CLKPR_SET(CLKPR_1MHZ);
	DEBUGGING_REINIT(OWOWOD_BITLEN_FCPU1MHZ_009600BPS);	// 009600BPS,115200BPS
#elif F_CPU == 8000000UL
#pragma message "F_CPU=8MHZ"
	CLKPR_SET(CLKPR_8MHZ);
	DEBUGGING_REINIT(OWOWOD_BITLEN_FCPU8MHZ_115200BPS);	// 009600BPS,115200BPS
#else
#pragma message "F_CPU=????"
#error "CPU frequency should be either 1 MHz or 8 MHz"
#endif

	DEBUGGING_CRLF(); DEBUGGING_STRINGLN("HELLO[OWOWOD]");	// Not really needed
	
	// ---- Main Loop ----
	uint8_t num = 0;
	for (;;) {
		DEBUGGING_NUMBINUPZ(num); DEBUGGING_STRING(": ");
		for (char ch = 'A'; ch <= 'Z'; ch++) {
			DEBUGGING_CHAR(ch);
		}
		DEBUGGING_CRLF();
		num++;
		_delay_ms(1000);
	}

	return 0;
}

// ============================================================================
