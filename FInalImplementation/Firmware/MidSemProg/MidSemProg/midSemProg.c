/*
 * MidSemProg.c
 *
 * Created: 26/08/2021 9:17:51 PM
 * Author : Team 18
 */ 

#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "uart.h"

int main(void)
{
    /* Replace with your application code */
	uart_init(9600);
		
    while (1) 
    {			//Write a function to extract the individual digits of a 3 digit number (Lab 3 Q4.6) this for loop
		
						float PeakVoltage = 14.6; //14.6
						uint8_t RMSCurrent = 125; //125
						float Power = 1.60; //1.60
						
						uint8_t intPeakVoltage = PeakVoltage *10;
						uint8_t intPower = Power*100;

				uart_transmit_calculate_peakvoltage(intPeakVoltage);
				uart_transmit_calculate_rmscurrent(RMSCurrent);
				uart_transmit_calculate_power(intPower);
							
				
    }
}

