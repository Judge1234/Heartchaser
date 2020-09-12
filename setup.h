#ifndef SETUP_H
#define	SETUP_H

#include <xc.h>
#include "322_timer.h"


#define oscillator_16()     OSCCONbits.IRCF = 0b111;    // Set internal oscillator to 16Mhz


void setup_system(void);


#endif	

