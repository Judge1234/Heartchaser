#include "includes.h"


#define timer2_on()     T2CONbits.TMR2ON = 1
#define timer2_off()    T2CONbits.TMR2ON = 0

#define global_interrupt_enable()       INTCONbits.GIE = 1          // Global interrupt enable
#define timer2_interrupt_enable()       PIE1bits.TMR2IE = 1         // Timer 2 to PR2 match interrupt enable
#define peripheral_interrupt_enable()   INTCONbits.PEIE = 1         // Enable peripheral interrupts 
#define timer2_IF_clear()               PIR1bits.TMR2IF = 0         // Timer 2 clear interrupt flag

#define timer2_prescale(value)          T2CONbits.T2CKPS = value    // Set timer 2 clock prescaler
#define timer2_postscale(value)         T2CONbits.TOUTPS = value    // Set timer 2 output postscaler

#define timer2_interrupt_flag           PIR1bits.TMR2IF

#define set_period_register(value)      PR2 = value                 // Set period register for comparison

//  timer 2 prescaler values
#define timer2_prescale_1               0b00
#define timer2_prescale_4               0b01
#define timer2_prescale_16              0b10
#define timer2_prescale_64              0b11

//  timer 2 postscaler values
#define timer2_postscale_1              0b0000
#define timer2_postscale_2              0b0001
#define timer2_postscale_3              0b0010
#define timer2_postscale_4              0b0011
#define timer2_postscale_5              0b0100
#define timer2_postscale_6              0b0101
#define timer2_postscale_7              0b0110
#define timer2_postscale_8              0b0111
#define timer2_postscale_9              0b1000
#define timer2_postscale_10             0b1001
#define timer2_postscale_11             0b1010
#define timer2_postscale_12             0b1011
#define timer2_postscale_13             0b1100
#define timer2_postscale_14             0b1101
#define timer2_postscale_15             0b1110
#define timer2_postscale_16             0b1111



void timer2_ISR_init(void);


void timer2_setup(uint8_t prescale, uint8_t postscale);


/*

 The firmware within the Interrupt Service Routine (ISR)
should determine the source of the interrupt by polling
the interrupt flag bits. The interrupt flag bits must be
cleared before exiting the ISR to avoid repeated
interrupts. Because the GIE bit is cleared, any interrupt
that occurs while executing the ISR will be recorded
through its interrupt flag, but will not cause the
processor to redirect to the interrupt vector. 
 */