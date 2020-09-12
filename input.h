#ifndef INPUT_H
#define	INPUT_H

#include "includes.h"

#define BUTTON          PORTAbits.RA3

#define ON              0
#define OFF             1

#define DEBOUNCE_MASK   0b11000111


extern void update_button(void); 

extern bool button_is_pressed(void); 


#endif	

