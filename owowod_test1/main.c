/*
 * The Tinusaur Project
 *
 * OWOWOD - One Wire / One Way Output for Debugging
 *
 * @created: 2014-11-21
 * @author: Neven Boyanov
 *
 * Source code available at: https://bitbucket.org/tinusaur/owowod
 *
 */

// ============================================================================

#define F_CPU 1000000UL

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

// ======================================
//                ATtiny
//               25/45/85
//              +----------+
//        RST --+ PB5  Vcc +---(+)-------
// ----OWOWOD---+ PB3  PB2 +--
//            --+ PB4  PB1 +-- 
// -------(-)---+ GND  PB0 +-- 
//              +----------+
// ======================================

#define OWOWOD_PORT	PB3	// OWOWOD Port

// ----------------------------------------------------------------------------

#include "../owowod/owowod.h"

// ============================================================================

int main(void) {

	// ---- Initialization ----
	
	owowod_init();

	// ---- Main Loop ----

	uint8_t num = 0;
	while (1) {
	
		// owowod_print_numdecp(num);
		owowod_print_numdecp(num);
		owowod_print_char('\n');
		owowod_print_char('\r');
		// owowod_print_char(0x55);	// 0x55='U' 0xAA='ª'
		// owowod_print_char(0xAA);	// 0x55='U' 0xAA='ª'
		// owowod_print_char('X');
		
		for (uint8_t i = 0; i < 95; i++) {	// 95, 127, 254
			owowod_print_char(' ' + i);
			owowod_print_char(' ');
		}
		owowod_print_string("\n\r");
		
		owowod_print_string("Hello! How are you? Good-bye. :)\n\r");
	
		owowod_print_string("\n\r");
		_delay_ms(2000);
		num++;
	}
	
	return (0);
}

// ============================================================================

