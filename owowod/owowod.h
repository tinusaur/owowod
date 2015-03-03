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
 * Please, as a favour, retain the link http://tinusaur.org to The Tinusaur Project.
 *
 * Source code available at: https://bitbucket.org/tinusaur/owowod
 *
 */

// ----------------------------------------------------------------------------

#ifndef OWOWOD_H
#define OWOWOD_H

// ============================================================================

#include <stdint.h>
#include <avr/io.h>

#include "num2str.h"

// ----------------------------------------------------------------------------

#ifndef OWOWOD_PORT
#define OWOWOD_PORT		PB3	// OWOWOD Port
#endif

// ----------------------------------------------------------------------------

inline void owowod_init(void) {
	DDRB |= (1 << OWOWOD_PORT);		// Set port as output
	PORTB |= (1 << OWOWOD_PORT);	// Set to HI
	// NOTE: Level HI is the default when the serial is inactive
}

// ----------------------------------------------------------------------------

void owowod_print_char(char);
void owowod_print_string(char *);
void owowod_print_numdec(int16_t);
void owowod_print_numdecp(int16_t);
void owowod_print_numdecu(uint16_t);
void owowod_print_numdecup(uint16_t);

// ============================================================================

#endif

// ----------------------------------------------------------------------------
