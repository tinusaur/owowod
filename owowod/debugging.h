/*
 * OWOWOD - One Wire / One Way Output for Debugging
 *
 * @created: 2015-01-01
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

#ifndef DEBUGGING_H
#define DEBUGGING_H

// ============================================================================

#include "owowod.h"

// ----------------------------------------------------------------------------

#define DEBUGGING_INIT() owowod_init()
#define DEBUGGING_NUMDEC(num) owowod_print_numdec(num)
#define DEBUGGING_NUMDECP(num) owowod_print_numdecp(num)
#define DEBUGGING_NUMDECU(num) owowod_print_numdecu(num)
#define DEBUGGING_NUMDECUP(num) owowod_print_numdecup(num)
#define DEBUGGING_CHAR(chr) owowod_print_char(chr)
#define DEBUGGING_STRING(str) owowod_print_string(str)
#define DEBUGGING_STRINGLN(str) { owowod_print_string(str); DEBUGGING_CRLF(); }
#define DEBUGGING_CRLF() owowod_print_string("\r\n")

#define DEBUGGING_ERROR(num, msg) \
	{ owowod_print_string("err["); owowod_print_numdec(num); \
	owowod_print_string("]:"); owowod_print_string(msg); \
	DEBUGGING_CRLF(); }
#define DEBUGGING_VAR(name, val) { owowod_print_string(name); \
	owowod_print_string("="); owowod_print_numdec(val); \
	owowod_print_string("; "); }

#define DEBUGGING_VARU(name, val) { owowod_print_string(name); \
	owowod_print_string("="); owowod_print_numdecu(val); \
	owowod_print_string("; "); }

// ============================================================================

#endif

// ----------------------------------------------------------------------------
