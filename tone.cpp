/*
 * tone.cpp
 *
 * Created: 5/20/2021 12:32:36 AM
 *  Author: Shyamal
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

#define SPEAKER_PORT PORTB
#define SPEAKER_DDR DDRB
#define SPEAKER_PIN 2

void tone(float frequency, float duration)
{
	long int i,samples;
	float period;
	float half_period;
	
	period = (1/frequency)*1000;
	samples = duration/period;
	half_period = period/2;
	
	SPEAKER_DDR |= (1<<SPEAKER_PIN);
	
	for(i=0;i<samples;i++)
	{
		_delay_ms(half_period);
		SPEAKER_PORT ^= (1<<SPEAKER_PIN);
	}
	return;
}	

void noTone()
{
	SPEAKER_DDR |= (1<<SPEAKER_PIN);
	SPEAKER_PORT &= ~(1<<SPEAKER_PIN);
   return;
		
}


