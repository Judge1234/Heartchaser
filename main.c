#include "config.h"
#include "hcISR.h"
#include "hc322.h"


void main(void) {
        
    
    setup_system(); 
    
    
    while(1) {
        system_run(mode);                
    }
}

