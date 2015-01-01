/*
 * OWOWOD - One Wire / One Way Output for Debugging
 *
 * Debugging handy definitions
 *
 * @created: 2015-01-01
 * @author: Neven Boyanov
 *
 * Source code available at: https://bitbucket.org/tinusaur/owowod
 *
 */

#ifndef DEBUGGING_H
#define DEBUGGING_H

// ----------------------------------------------------------------------------

#include "owowod.h"

// ----------------------------------------------------------------------------

#define DEBUGGING_INIT() owowod_init()
#define DEBUGGING_NUMDECP(num) owowod_print_numdecp(num)
#define DEBUGGING_STRING(str) owowod_print_string(str)

// ----------------------------------------------------------------------------

#endif
