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

#ifndef DEBUGGING_H
#define DEBUGGING_H

// ----------------------------------------------------------------------------

#include "owowod.h"

// ----------------------------------------------------------------------------

#define DEBUGGING_INIT() owowod_init()
#define DEBUGGING_REINIT(delay_val) owowod_reinit(delay_val)

#define DEBUGGING_CHAR(chr) owowod_print_char(chr)
#define DEBUGGING_STRING(str) owowod_print_string(str)
#define DEBUGGING_STRINGLN(str) { owowod_print_string(str); DEBUGGING_CRLF(); }
#define DEBUGGING_CRLF() owowod_print_string("\r\n")

#define DEBUGGING_NUMDEC(num) owowod_print_numdec(num)
#define DEBUGGING_NUMDECP(num) owowod_print_numdecp(num)
#define DEBUGGING_NUMDECU(num) owowod_print_numdecu(num)
#define DEBUGGING_NUMDECUP(num) owowod_print_numdecup(num)

#define DEBUGGING_ERROR(num, msg) \
	{ owowod_print_string("ERR["); owowod_print_numdec(num); \
	owowod_print_string("]:"); owowod_print_string(msg); \
	DEBUGGING_CRLF(); }

#define DEBUGGING_VAR(name, val) { owowod_print_string(name); \
	owowod_print_string("="); owowod_print_numdec(val); \
	owowod_print_string("; "); }

#define DEBUGGING_VARU(name, val) { owowod_print_string(name); \
	owowod_print_string("="); owowod_print_numdecu(val); \
	owowod_print_string("; "); }

#define DEBUGGING_NUMHEXUPZ(num) owowod_print_numhexupz(num)
#define DEBUGGING_NUMHEXUWPZ(num) owowod_print_numhexuwpz(num)

#define DEBUGGING_VARHEXUPZ(name, val) { owowod_print_string(name); \
	owowod_print_string("="); owowod_print_numhexupz(val); \
	owowod_print_string("; "); }

#define DEBUGGING_VARHEXUWPZ(name, val) { owowod_print_string(name); \
	owowod_print_string("="); owowod_print_numhexuwpz(val); \
	owowod_print_string("; "); }

#define DEBUGGING_NUMBINU(num) owowod_print_numbinu(num)
#define DEBUGGING_NUMBINUPZ(num) owowod_print_numbinupz(num)
#define DEBUGGING_NUMBINUW(num) owowod_print_numbinuw(num)
#define DEBUGGING_NUMBINUWPZ(num) owowod_print_numbinuwpz(num)

#define DEBUGGING_VARBINUPZ(name, val) { owowod_print_string(name); \
	owowod_print_string("="); owowod_print_numbinupz(val); \
	owowod_print_string("; "); }

#define DEBUGGING_VARBINUWPZ(name, val) { owowod_print_string(name); \
	owowod_print_string("="); owowod_print_numbinuwpz(val); \
	owowod_print_string("; "); }

// ----------------------------------------------------------------------------

#endif

// ============================================================================
