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

// ============================================================================

#include <avr/io.h>

#include "owowod.h"

// ----------------------------------------------------------------------------

// Freq=1MHz, Rate=9600bps - delay = [22,23,24]
// IMPORTANT: For other frequencies this parameter must change.
#define OWOWOD_DELAY	23	// Delay for each bit

inline void owowod_delay(void) {
	for (uint8_t i = OWOWOD_DELAY; i != 0; i--) {
		asm volatile ("nop\n\t");
	}
}

// ----------------------------------------------------------------------------

void owowod_print_char(char c) {
	PORTB &= ~(1 << OWOWOD_PORT);	// Set to LO
	owowod_delay();
	for (uint8_t i = 0; i < 8; i++)
	{
		if (c & 1) {
			PORTB |= (1 << OWOWOD_PORT);	// Set to HI
		} else {
			PORTB &= ~(1 << OWOWOD_PORT);	// Set to LO
		}
		owowod_delay();
		c = (c >> 1);
	}
	PORTB |= (1 << OWOWOD_PORT);	// Set to HI
	owowod_delay();
}

void owowod_print_string(char *s) {
	while (*s) {
		owowod_print_char(*s++);
	}
}

// ----------------------------------------------------------------------------

void owowod_print_numdec(uint16_t num) {
	char buffer[USINT2DECASCII_MAX_DIGITS + 1];
	buffer[USINT2DECASCII_MAX_DIGITS] = '\0';   // Terminate the string.
	uint8_t digits = usint2decascii(num, buffer);
	owowod_print_string(buffer + digits);
}

// ----------------------------------------------------------------------------

void owowod_print_numdecp(uint16_t num) {
	char buffer[USINT2DECASCII_MAX_DIGITS + 1];
	buffer[USINT2DECASCII_MAX_DIGITS] = '\0';   // Terminate the string.
	usint2decascii(num, buffer);
	owowod_print_string(buffer);
}

// ============================================================================
