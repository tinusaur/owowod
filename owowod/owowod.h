/*
 * OWOWOD - One Wire / One Way Output for Debugging
 *
 * @created: 2014-11-21
 * @author: Neven Boyanov
 *
 * This is part of the Tinusaur/OWOWOD project.
 *
 * Copyright (c) 2015 Neven Boyanov, Tinusaur Team. All Rights Reserved.
 * Distributed as open source software under MIT License, see LICENSE.txt file.
 * Please, as a favor, retain the link http://tinusaur.org to The Tinusaur Project.
 *
 * Source code available at: https://bitbucket.org/tinusaur/owowod
 *
 */

// ============================================================================

#ifndef OWOWOD_H
#define OWOWOD_H

// ----------------------------------------------------------------------------

#include <stdint.h>
#include <avr/io.h>

#include "num2str.h"

// ----------------------------------------------------------------------------

#ifndef OWOWOD_PORT
#define OWOWOD_PORT		PB3	// OWOWOD Port
#endif

// ----------------------------------------------------------------------------

#define OWOWOD_DELAY_FCPU1MHZ_004800BPS	31	// 31-34:OK, 35:Errors
#define OWOWOD_DELAY_FCPU1MHZ_009600BPS	15	// 15:OK, 16:Errors
#define OWOWOD_DELAY_FCPU1MHZ_019200BPS	6	// Errors
#define OWOWOD_DELAY_FCPU1MHZ_038400BPS	2	// OK
#define OWOWOD_DELAY_FCPU1MHZ_057600BPS	0	// Failure

#define OWOWOD_DELAY_FCPU8MHZ_009600BPS	132	// 132-143: OK, 144-145: Errors
#define OWOWOD_DELAY_FCPU8MHZ_019200BPS	65	// 65-70: OK
#define OWOWOD_DELAY_FCPU8MHZ_038400BPS	32	// 32-34: OK
#define OWOWOD_DELAY_FCPU8MHZ_057600BPS	20	// 20-22: OK
#define OWOWOD_DELAY_FCPU8MHZ_115200BPS	9	// 9: OK

// ----------------------------------------------------------------------------

uint8_t owowod_delay_val;

// ----------------------------------------------------------------------------

inline void owowod_init(void) {
	DDRB |= (1 << OWOWOD_PORT);		// Set port as output
	PORTB |= (1 << OWOWOD_PORT);	// Set to HI
	// NOTE: Level HI is the default when the serial is inactive
	// TODO: Adjust OWOWOD_DELAY during init. Necessary for some USB-to-Serial adapters.
}

inline void owowod_delay_set(uint8_t);inline void owowod_delay_set(uint8_t val) { owowod_delay_val = val; }

// ----------------------------------------------------------------------------

void owowod_print_char(char);
void owowod_print_string(char *);
void owowod_print_numdec(int16_t);
void owowod_print_numdecp(int16_t);
void owowod_print_numdecu(uint16_t);
void owowod_print_numdecup(uint16_t);

// ----------------------------------------------------------------------------

void owowod_print_numbinu(uint8_t);
void owowod_print_numbinupz(uint8_t);
void owowod_print_numbinuw(uint16_t);
void owowod_print_numbinuwpz(uint16_t);

// ----------------------------------------------------------------------------

#endif

// ============================================================================
