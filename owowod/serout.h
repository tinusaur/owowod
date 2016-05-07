/**
 * OWOWOD - One Wire / One Way Output for Debugging
 *
 * @created 2016-04-17
 * @author Neven Boyanov
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

// ----------------------------------------------------------------------------

#ifndef SEROUT_H
#define SEROUT_H

// ============================================================================

#include "owowod.h"

// ----------------------------------------------------------------------------

#define SEROUT_INIT() owowod_init()
#define SEROUT_REINIT(delay_val) owowod_reinit(delay_val)

#define SEROUT_CHAR(chr) owowod_print_char(chr)
#define SEROUT_STRING(str) owowod_print_string(str)
#define SEROUT_STRINGLN(str) { owowod_print_string(str); SEROUT_CRLF(); }
#define SEROUT_CRLF() owowod_print_string("\r\n")

#define SEROUT_NUMDEC(num) owowod_print_numdec(num)
#define SEROUT_NUMDECP(num) owowod_print_numdecp(num)
#define SEROUT_NUMDECU(num) owowod_print_numdecu(num)
#define SEROUT_NUMDECUP(num) owowod_print_numdecup(num)

#define SEROUT_NUMBINU(num) owowod_print_numbinu(num)
#define SEROUT_NUMBINUPZ(num) owowod_print_numbinupz(num)
#define SEROUT_NUMBINUW(num) owowod_print_numbinuw(num)
#define SEROUT_NUMBINUWPZ(num) owowod_print_numbinuwpz(num)

// ============================================================================

#endif
