#ifndef HC322_H
#define	HC322_H


#include "includes.h"
#include "input.h"

#define SER_DATA_IN     LATAbits.LATA0
#define SRCLK_CLOCK     LATAbits.LATA1
#define RCLK_LATCH      LATAbits.LATA2

#define MAX_OUTPUTS     16

#define MAX_MODES       4

#define store_bit(bit, storage_values) (storage_values & bit) ? shift_one() : shift_zero()


extern uint8_t mode;


typedef union {
    struct {
        unsigned PIN0   : 1;
        unsigned PIN1   : 1;
        unsigned PIN2   : 1;
        unsigned PIN3   : 1;
        unsigned PIN4   : 1;
        unsigned PIN5   : 1;
        unsigned PIN6   : 1;
        unsigned PIN7   : 1;
        unsigned PIN8   : 1;
        unsigned PIN9   : 1;
        unsigned PIN10  : 1;
        unsigned PIN11  : 1;
        unsigned PIN12  : 1;
        unsigned PIN13  : 1;
        unsigned PIN14  : 1;
        unsigned PIN15  : 1;       
    };
    uint16_t all;
} register_pins_t;


typedef void (*display_routine_t)(void);

extern void system_run(uint8_t mode);  


#endif

