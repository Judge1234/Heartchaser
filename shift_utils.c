#include "shift_utils.h"


void shift_one(void) {
    SER_DATA_IN = 1;
    SRCLK_CLOCK = 1;
    SRCLK_CLOCK = 0;
    SER_DATA_IN = 0;
}


void shift_zero(void) {
    SER_DATA_IN = 0;
    SRCLK_CLOCK = 1;
    SRCLK_CLOCK = 0;
}


void latch_out(void) {
    RCLK_LATCH = 1; 
    RCLK_LATCH = 0;
}