/*
 * uart.h
 *
 * Created: 27/08/2021 4:34:48 PM
 *  Author: Team 18
 */ 


#ifndef UART_H_
#define UART_H_
#define F_CPU 2000000UL
#include <stdint.h>
#include <avr/io.h>
#include <string.h>
#include <util/delay.h>

void uart_init(uint32_t baud_rate);
void uart_transmit_byte(uint8_t byte);
void uart_transmit_array(char* msg);


void uart_transmit_calculate_peakvoltage(uint8_t PeakVoltage);
void uart_transmit_calculate_rmscurrent(uint8_t RMSCurrent);
void uart_transmit_calculate_power(uint8_t Power);

#endif /* UART_H_ */