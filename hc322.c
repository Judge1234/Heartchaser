#include "shift_utils.h"


register_pins_t register_bank;
 
display_routine_t display_modes[MAX_MODES];  

uint8_t mode;


void write_register_pins(void) {
    for (uint8_t i = 0; i < MAX_OUTPUTS; i++) {
        uint16_t mask_value = 1 << i; 
        store_bit(mask_value, register_bank.all); 
    } 
} 


void publish_register_pins(void) {
    latch_out(); 
}


void write_display(uint16_t pattern) {
    register_bank.all = pattern; 
}


void clear_display(void) {
    register_bank.all = 0; 
}


void rotate_right(void) {
    uint8_t last = register_bank.PIN15; 
    register_bank.all >>= 1; 
    register_bank.PIN0 = last; 
}


void rotate_left(void) {
    uint8_t first = register_bank.PIN0; 
    register_bank.all <<= 1; 
    register_bank.PIN15 = first; 
}


 void system_run(uint8_t mode) {
    if (button_is_pressed()) {
        mode++;
        if (mode > MAX_MODES) {
            mode = 0; 
        } 
    }
    display_modes[mode](); 
}






