#include "input.h"


uint8_t button_history; 


bool read_button(void) {
    return ~PORTAbits.RA3;  // Button is active low
}


void update_button(void) {
    button_history <<= 1; 
    button_history |= read_button(); 
}


bool button_is_pressed(void) {    
    if ((button_history & DEBOUNCE_MASK) == 00000111) { 
        button_history = 0b11111111; 
        return true;
    }
    return false; 
}

