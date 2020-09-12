#include "322_timer.h"


void timer2_ISR_init(void) {
    timer2_IF_clear();          
    global_interrupt_enable();  
    peripheral_interrupt_enable(); 
    timer2_interrupt_enable();        
}


void timer2_setup(uint8_t prescale, uint8_t postscale) {
    timer2_prescale(prescale);      
    timer2_postscale(postscale);   
    timer2_on();                
}


