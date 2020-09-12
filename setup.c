#include "setup.h"


void setup_system(void) {
    
    oscillator_16(); 
    
    timer2_ISR_init(); 
    
    timer2_setup(timer2_prescale_16, timer2_postscale_5);   //  0.001024 seconds @ pre = 16 & post = 5

    set_period_register(1);         
    
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0; 
    TRISAbits.TRISA2 = 0; 
    

    //  Enable outputs by disabling all multiplexed peripherals
    
    //  Enable RA0
    CWG1CON0bits.G1EN = 0;  //  CWG module 1 disabled (CWG output A and B disabled)
    PWM1CONbits.PWM1EN = 0; //  PWM module 1 disabled
    
    //  Enable RA1 output
                            //  CWG output B already disabled
    PWM2CONbits.PWM2EN = 0; //  PWN module 2 disabled 
    CLC1CONbits.LC1EN = 0;  //  CLC module disabled
    
    //  Enable RA2 output
    NCO1CONbits.N1EN = 0;   //  NCO module disabled
    CLKRCONbits.CLKROE = 0; //  Reference Clock output disabled
    
}
