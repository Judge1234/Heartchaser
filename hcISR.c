#include "hcISR.h"
#include "hc322.h" 
#include "input.h"


void __interrupt() ISR_handler(void) {
    if (timer2_interrupt_flag == 1) {
        update_button();          
        timer2_IF_clear();
    }
    timer2_IF_clear();    
    global_interrupt_enable(); 
}


