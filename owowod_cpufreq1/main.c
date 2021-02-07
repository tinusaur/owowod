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

// DO NOT DO THIS: #define F_CPU 1000000UL
// NOTE: The F_CPU (CPU freq) must not be set in the source code.
//       It must be set in either (1) Makefile; or (2) in the IDE. 

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

#include "tinyavrlib/cpufreq.h"
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

	// ---- Setup CPU Frequency ----
#if F_CPU == 1000000UL
#pragma message "F_CPU=1MHZ"
	CLKPR_SET(CLKPR_1MHZ);
	owowod_reinit(OWOWOD_BITLEN_FCPU1MHZ_009600BPS);	// 1MHZ & 115200BPS
#elif F_CPU == 8000000UL
#pragma message "F_CPU=8MHZ"
	CLKPR_SET(CLKPR_8MHZ);
	owowod_reinit(OWOWOD_BITLEN_FCPU8MHZ_115200BPS);	// 8MHZ & 115200BPS
#else
#pragma message "F_CPU=????"
#error "CPU frequency should be either 1 MHz or 8 MHz"
#endif
	
	// ---- Main Loop ----
	uint8_t num = 0;
	for (;;) {
		owowod_print_numbinupz(num); owowod_print_char(':');
		for (char ch = 'A'; ch <= 'Z'; ch++) owowod_print_char(ch);
		owowod_print_char('\r');
		owowod_print_char('\n');
		num++;
		_delay_ms(1000);
	}

	return 0; // Return the mandatory for the "main" function int value - "0" for success.
}

// ============================================================================
