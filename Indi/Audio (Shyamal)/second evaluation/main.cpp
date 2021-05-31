/*
 * att03.cpp
 *
 * Created: 5/20/2021 12:31:14 AM
 * Author : Shyamal
 */ 

#define F_CPU 16000000UL


#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include "tone.h"
#include "note_freq.h"
#include "got.h"
#include "pirate_of_caribian.h"
#include "pinkpanther.h"
#include "turtis.h"


#define SPEAKER PORTB2

void song();
void pirate_of();


void play_melody(int melody[],int tempo, int notes );

int temp = 1;


int main(void)
{
	DDRB =0x05;
	DDRD =0x00;
	
	PORTD |= (1<<PORTD3);
	PORTD |= (1<<PORTD4);
	PORTD |= (1<<PORTD5);
	/* Replace with your application code */
    while (1) 
    {
		if (~PIND&(1<<PIND4))
		{
			//PORTB |= (1<<PORTB0);
			song();
			
		}
		else{
			PORTB &= ~(1<<PORTB0);
			noTone(SPEAKER);
		}
	}
}
	
void song(){
	if (temp>3){temp = 1;}
	if (temp<1){temp = 3;}
	if (temp==1){
		pirate_of();
		
	}
	else if (temp==2){
		play_melody(got_melody, got_tempo, got_notes);
		
		
	}
	else if (temp==3){
		play_melody(turtis_melody, turtis_tempo, turtis_notes);
	}
	//else if (temp==4){
		//play_melody(pink_melody, pink_tempo, pink_notes);
	//}
	//else{
		//play_melody(pink_melody, pink_tempo, pink_notes);
	//}
}


void pirate_of()      // function to play the pirate of the Caribbean sea
{
	const int totalNotes = sizeof(pcs_notes) / sizeof(int);
	for (int i = 0; i < totalNotes; i++)
	{
		const int currentNote = pcs_notes[i];
		float wait = pcs_durations[i] / songSpeed;
		
		if ((~PIND &(1<<PIND4)) && !((~PIND &(1<<PIND5))|(~PIND &(1<<PIND3)))) // checks the play pause switch
		{
			if (currentNote != 0)
			{
				PORTB |= (1<<PORTB0);
				tone(SPEAKER, pcs_notes[i], wait);
			}
			else
			{
				noTone(SPEAKER);
			}
			PORTB &= ~(1<<PORTB0);
			_delay_ms(wait);
			
			
		}
		else // Play tone if currentNote is not 0 frequency, otherwise pause (noTone)
		{
			noTone(SPEAKER);
			if (~PIND &(1<<PIND5)){
				_delay_ms(1000);
				temp++;
			}
			else if (~PIND &(1<<PIND3)){
				_delay_ms(1000);
				temp--;
			}
			break;
		}
	}
	return;
}



void play_melody(int melody[],int tempo, int notes) // function to play any melody
{
	
	

	int wholenote = (60000 * 4) / tempo;

	int divider = 0, noteDuration = 0;
	// iterate over the notes of the melody.
	for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
		divider = melody[thisNote + 1];
		if (divider > 0) {
			noteDuration = (wholenote) / divider;  // regular note, just proceed
		}
		else if (divider < 0) {
			noteDuration = (wholenote) / (-1*(divider));// dotted notes are represented with negative durations!!
			noteDuration *= 1.5; // increases the duration in half for dotted notes
		}
		
		if ((~PIND &(1<<PIND4)) && !((~PIND&(1<<PIND5))|(~PIND&(1<<PIND3))))  // checks the play pause switch
		{
			PORTB |= (1<<PORTB0);
			tone(SPEAKER, melody[thisNote], noteDuration * 0.9); //play the note for 90% of the duration, leaving 10% as a pause
			PORTB &= ~(1<<PORTB0);
			_delay_ms(noteDuration);
			
			noTone(SPEAKER);
			
		}
		else{
			noTone(SPEAKER);
			if (~PIND&(1<<PIND5)){
				_delay_ms(1000);
				temp++;
			}
			else if (~PIND&(1<<PIND3)){
				_delay_ms(1000);
				temp--;
			}
			break;
		}
		
	}
	return;
}