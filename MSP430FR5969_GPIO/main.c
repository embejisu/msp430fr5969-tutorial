#include <msp430.h> 

#define LED_GRN 0
#define LED_RED 6

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	PM5CTL0 &= ~LOCKLPM5; // Unlock port... The FRAM devices lock port status at power-up until you unlock the ports.

    P1DIR |= (1<<LED_GRN); // P1.0 output setting.
    P1OUT |= (1<<LED_GRN); // Turn on the green led.

	P4DIR |= (1<<LED_RED); // P4.6 output setting.
	P4OUT |= (1<<LED_RED); // Turn on the red led.


	P1OUT &= ~(1<<LED_GRN); // Turn off the green led.
	P4OUT &= ~(1<<LED_RED); // Turn off the red led.

	return 0;
}
