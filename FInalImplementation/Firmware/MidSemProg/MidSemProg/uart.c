/*
 * uart.c
 *
 * Created: 27/08/2021 4:34:26 PM
 *  Author: Team 18
 */ 

#include "uart.h"

// Write an initialization function to setup the UART peripheral as per project specifications (Lab 3 Q4.3)

void uart_init(uint32_t baud_rate){ //Copied from lecture notes
	UCSR0A = 0b00000000;    //None of the settings here are used
	UCSR0B = 0b00001000;    //Set TXEN0 bit to 1 (enable transmit) and UCSZ02 bit to 0 (8 data bits)
	//To improve readability we should aim to write this in the form "UCSR0B = (1<<TXEN0);
	UCSR0C = 0b00000110;    //UMSEL0[1..0]=00 (UART mode), UPM0[1..0]=00 (no parity)
	//USBS0=0 (1 stop-bit), UCSZ0[1..0]=11 (8 data bits)
	UBRR0 = 2000000 / (16 * baud_rate) - 1;
	//Set UBRR0 as per baud rate formula
}


//Write a function to transmit a byte of data through the UART (Lab 3 Q4.4)
// This function transmits a single byte via the UART
void uart_transmit_byte(uint8_t byte){ // Copied from lecture notes
	while ((UCSR0A & 0b00100000) == 0){       //UDRE0 bit is checked to see if it is 0
		;                                         //If UDRE0 bit is not 0, wait until it becomes 0
	}
	//Put the byte to be sent into the UDR0 register
	UDR0 = byte;
}

void uart_transmit_array(char* msg){ // Copied from lecture notes

	for(uint8_t i=0; i<strlen(msg);i++){
		uart_transmit_byte(msg[i]);
	}
}


void uart_transmit_calculate_peakvoltage(uint8_t PeakVoltage){

//By multiplying it by 10, will convert from float to integer, we can now use % operator
//PeakVoltage = PeakVoltage*10;
	
	uint8_t PeakVoltageInt = PeakVoltage;


	uint8_t VolThirdNum = ((PeakVoltageInt)) % 10;
	uint8_t VolSecondNum = (( PeakVoltageInt) / 10) % 10;
	uint8_t VolFirstNum = (( PeakVoltageInt) / 100) %10;

	//Write a function to convert a digit between 0-9 to its ASCII value (Lab 3 Q4.6)
	uart_transmit_array("Peak Voltage is: ");

	uart_transmit_byte(VolFirstNum + 48);
	uart_transmit_byte(VolSecondNum + 48);
	uart_transmit_byte(46);
	uart_transmit_byte(VolThirdNum + 48);

}


void uart_transmit_calculate_rmscurrent(uint8_t RMSCurrent){

	uint8_t CurThirdNum = RMSCurrent % 10;
	uint8_t CurSecondNum = (RMSCurrent / 10) % 10;
	uint8_t CurFirstNum = (RMSCurrent / 100) %10;

	uart_transmit_array("\n\r");
	uart_transmit_array("RMS Current is: ");

	uart_transmit_byte(CurFirstNum + 48);
	uart_transmit_byte(CurSecondNum + 48);
	uart_transmit_byte(CurThirdNum + 48);

}

void uart_transmit_calculate_power(uint8_t Power){

	
	uint8_t PowerInt = Power;
	uint8_t PowThirdNum = (PowerInt) % 10;
	uint8_t PowSecondNum = ((PowerInt) / 10) % 10;
	uint8_t PowFirstNum = ((PowerInt) / 100) %10;
	uart_transmit_array("\n\r");
	uart_transmit_array("Power is: ");
	uart_transmit_byte(PowFirstNum + 48);
	uart_transmit_byte(46);
	uart_transmit_byte(PowSecondNum + 48);
	uart_transmit_byte(PowThirdNum + 48);
	uart_transmit_array("\n\r");
	uart_transmit_array("\n\r");
	_delay_ms(1000);

}