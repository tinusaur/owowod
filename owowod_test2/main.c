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

#define F_CPU 1000000UL

#include <stdint.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                ATtiny
//               25/45/85
//              +----------+
//        RST --+ PB5  Vcc +---(+)-------
// ----OWOWOD---+ PB3  PB2 +--
//            --+ PB4  PB1 +--
// -------(-)---+ GND  PB0 +--
//              +----------+
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#define OWOWOD_PORT	PB3	// OWOWOD Port

// ----------------------------------------------------------------------------

#include <avr/io.h>

#include "../owowod/owowod.h"
#include "../owowod/debugging.h"

// ============================================================================

int main(void) {

	// ---- Initialization ----
	DEBUGGING_INIT();

	DEBUGGING_STRING("Hello!\n");

	DEBUGGING_NUMDEC(-123); DEBUGGING_STRING(",");
	DEBUGGING_NUMDECP(-4567); DEBUGGING_STRING(",");
	DEBUGGING_NUMDECU(123); DEBUGGING_STRING(",");
	DEBUGGING_NUMDECUP(4567); DEBUGGING_STRING(",");

	DEBUGGING_STRING("\n");

	DEBUGGING_VAR("X", 1);
	DEBUGGING_VAR("Y", 23);
	DEBUGGING_VAR("Z", 45678);
	DEBUGGING_VAR("X", -90);
	DEBUGGING_VAR("Y", -678);
	DEBUGGING_VAR("Z", -12345);

	DEBUGGING_VARU("X", 1);
	DEBUGGING_VARU("Y", 23);
	DEBUGGING_VARU("Z", 45678);
	DEBUGGING_VARU("X", -90);
	DEBUGGING_VARU("Y", -678);
	DEBUGGING_VARU("Z", -12345);

	DEBUGGING_ERROR(3, "Connect");

	return 0;
}

// ============================================================================
