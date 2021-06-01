/*
 * GccApplication8.c
 *
 * Created: 5/27/2021 10:14:37 PM
 * Author : ALPHAXANDER
 */ 

#define F_CPU	16000000UL
#define AlarmLED	PORTB0
#define STOP_BUTTON	PINB1


#include <avr/io.h>
#include "rtc.h"        // RTC library
#include <stdbool.h>   //to use boolean operators


int main(void)
{
	DDRB = (1<<AlarmLED);	// PB0 is output
	PORTB |= (1<<PORTB1);	// enable the internal pull ups for PB1 the stop pin
	bool Alarm = true; //this condition is created to stop the alarm while its ringing
	bool Alarm_ring =false; //this condition is created to stop the alarm while its ringing
	
	
	// Setting time to the RTC
	// Defining (year,month,date,hr,min,sec) as unsigned integer of length 8 bits
	
	uint8_t year = 0;
	uint8_t month = 0;
	uint8_t day = 0;
	uint8_t hour = 0;
	uint8_t minute = 0;
	uint8_t second = 0;

	//Date setter for the alarm clock
	Setdate(21, 06, 01, 11, 30, 55);
	
	// Set the alarm
	int alarm_hr = 11;
	int alarm_min = 31;
	
	
	while (1)
	{
		Getdate(&year,&month,&day,&hour,&minute,&second); //Getting Date and Time from RTC
		
		//Alarm ringing condition
		// if the current time and alarm time gets equal then the alarm rings
		if ((minute == alarm_min)  & (hour == alarm_hr) & Alarm){  
			PORTB |= (1<<AlarmLED);  // turning the LED ON
			Alarm_ring = true;  //alarm is ringing
		}
		
		else{
			// Turning the Alarm OFF after one whole minute
			PORTB &= (0<<AlarmLED);
		}
		
		
		//Stopping the Alarm while its ringing
		// when push button is pressed and alarm is still ringing
		if (!(PINB & (1<<STOP_BUTTON)) & Alarm_ring){ 
			PORTB &= (0<<AlarmLED);
			PORTB |= (1<<PORTB1) ;
			Alarm = false ; 
			Alarm_ring = false; 
		}
	}
}
