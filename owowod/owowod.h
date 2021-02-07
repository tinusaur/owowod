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

// ============================================================================

#ifndef OWOWOD_H
#define OWOWOD_H

// ----------------------------------------------------------------------------

#include <stdint.h>
#include <avr/io.h>

#include "tinyavrlib/num2str.h"

// ----------------------------------------------------------------------------

#ifndef OWOWOD_PORT
#define OWOWOD_PORT		PB3	// OWOWOD Port
#endif

// ----------------------------------------------------------------------------

#define OWOWOD_BITLEN_FCPU1MHZ_004800BPS	32	// 31-34: OK, 35: Errors
#define OWOWOD_BITLEN_FCPU1MHZ_009600BPS	15	// 15-16: OK, 17: Errors
#define OWOWOD_BITLEN_FCPU1MHZ_019200BPS	6	// Errors
#define OWOWOD_BITLEN_FCPU1MHZ_038400BPS	2	// OK
#define OWOWOD_BITLEN_FCPU1MHZ_057600BPS	0	// Failure

#define OWOWOD_BITLEN_FCPU8MHZ_009600BPS	136	// 132-143: OK, 144-145: Errors
#define OWOWOD_BITLEN_FCPU8MHZ_019200BPS	67	// 65-70: OK
#define OWOWOD_BITLEN_FCPU8MHZ_038400BPS	33	// 32-34: OK
#define OWOWOD_BITLEN_FCPU8MHZ_057600BPS	21	// 20-22: OK
#define OWOWOD_BITLEN_FCPU8MHZ_115200BPS	10	// 9-10: OK (but not always)

// NOTE: In some cased the numbers above may need to be adjusted by +/- 1 or 2
//       if the CPU clock is not calibrated to exactly 1 MHz or 8 MHz.

// ----------------------------------------------------------------------------

inline void owowod_init(void) {
	DDRB |= (1 << OWOWOD_PORT);		// Set port as output
	PORTB |= (1 << OWOWOD_PORT);	// Set to HI
	// NOTE: Level HI is the default when the serial is inactive
	// TODO: Adjust owowod_bitlen_val during init. Necessary for some USB-to-Serial adapters.
}

void owowod_reinit(uint8_t);

// ----------------------------------------------------------------------------

void owowod_print_char(char);
void owowod_print_string(char *);
void owowod_print_numdec(int16_t);
void owowod_print_numdecp(int16_t);
void owowod_print_numdecu(uint16_t);
void owowod_print_numdecup(uint16_t);

// ----------------------------------------------------------------------------

void owowod_print_numhexupz(uint8_t);
void owowod_print_numhexuwpz(uint16_t);

// ----------------------------------------------------------------------------

void owowod_print_numbinu(uint8_t);
void owowod_print_numbinupz(uint8_t);
void owowod_print_numbinuw(uint16_t);
void owowod_print_numbinuwpz(uint16_t);

// ----------------------------------------------------------------------------

#endif

// ============================================================================
