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

#include "owowod.h"

#include <avr/interrupt.h>

// ----------------------------------------------------------------------------

#define OWOWOD_DELAY_DEFAULT OWOWOD_DELAY_FCPU1MHZ_009600BPS	// Delay for each bit

// ----------------------------------------------------------------------------

uint8_t owowod_delay_val = OWOWOD_DELAY_DEFAULT;

// ----------------------------------------------------------------------------

inline void owowod_delay(void) {
	for (uint8_t i = owowod_delay_val; i != 0; i--) {
		asm volatile ("nop\n\t");
	}
}

// ----------------------------------------------------------------------------

void owowod_print_char(char c) {
	cli(); // disable interrupts
	// TODO: make it optional, use define.

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

    sei(); // enable interrupts
	// TODO: make it optional, use define.
}

void owowod_print_string(char *s) {
	while (*s) {
		owowod_print_char(*s++);
	}
}

// ----------------------------------------------------------------------------

void owowod_print_numdec(int16_t num) {
	char buffer[USINT2DECASCII_MAX_DIGITS + 2];	// One more byte for the sign.
	buffer[0] = ' ';   // Init the string.
	buffer[USINT2DECASCII_MAX_DIGITS + 1] = '\0';   // Terminate the string.
	uint8_t digits = usint2decascii((num < 0 ? -num : num), buffer + 1);
	if (num < 0) buffer[digits] = '-';
	owowod_print_string(buffer + digits + (num < 0 ? 0 : 1));
}

// ----------------------------------------------------------------------------

void owowod_print_numdecp(int16_t num) {
	char buffer[USINT2DECASCII_MAX_DIGITS + 2];	// One more byte for the sign.
	buffer[0] = ' ';   // Init the string.
	buffer[USINT2DECASCII_MAX_DIGITS + 1] = '\0';   // Terminate the string.
	uint8_t digits = usint2decascii((num < 0 ? -num : num), buffer + 1);
	if (num < 0) buffer[digits] = '-';
	owowod_print_string(buffer);
}

// ----------------------------------------------------------------------------

void owowod_print_numdecu(uint16_t num) {
	char buffer[USINT2DECASCII_MAX_DIGITS + 1];
	buffer[USINT2DECASCII_MAX_DIGITS] = '\0';   // Terminate the string.
	uint8_t digits = usint2decascii(num, buffer);
	owowod_print_string(buffer + digits);
}

// ----------------------------------------------------------------------------

void owowod_print_numdecup(uint16_t num) {
	char buffer[USINT2DECASCII_MAX_DIGITS + 1];
	buffer[USINT2DECASCII_MAX_DIGITS] = '\0';   // Terminate the string.
	usint2decascii(num, buffer);
	owowod_print_string(buffer);
}

// ============================================================================

void owowod_print_numbinu(uint8_t num) {
	char buffer[USINT2BINASCII_MAX_DIGITS + 1];
	buffer[USINT2BINASCII_MAX_DIGITS] = '\0';   // Terminate the string.
	uint8_t digits = usint2binascii(num, buffer);
	owowod_print_string(buffer + digits);
}

// ----------------------------------------------------------------------------

void owowod_print_numbinupz(uint8_t num) {
	char buffer[USINT2BINASCII_MAX_DIGITS + 1];
	buffer[USINT2BINASCII_MAX_DIGITS] = '\0';   // Terminate the string.
	usint2binascii(num, buffer);
	owowod_print_string(buffer + USINT2BINASCII_MAX_DIGITS / 2);
}

// ----------------------------------------------------------------------------

void owowod_print_numbinuw(uint16_t num) {
	char buffer[USINT2BINASCII_MAX_DIGITS + 1];
	buffer[USINT2BINASCII_MAX_DIGITS] = '\0';   // Terminate the string.
	uint8_t digits = usint2binascii(num, buffer);
	owowod_print_string(buffer + digits);
}

// ----------------------------------------------------------------------------

void owowod_print_numbinuwpz(uint16_t num) {
	char buffer[USINT2BINASCII_MAX_DIGITS + 1];
	buffer[USINT2BINASCII_MAX_DIGITS] = '\0';   // Terminate the string.
	usint2binascii(num, buffer);
	owowod_print_string(buffer);
}

// ============================================================================
