/*
 * OWOWOD - One Wire / One Way Output for Debugging
 *
 * @created: 2014-11-21
 * @author: Neven Boyanov
 *
 * Source code available at: https://bitbucket.org/tinusaur/owowod
 *
 */

#ifndef OWOWOD_H
#define OWOWOD_H

// ============================================================================

#include <stdint.h>

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
void owowod_print_numdec(uint16_t);
void owowod_print_numdecp(uint16_t);

// ============================================================================

#endif
