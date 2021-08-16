/*
 * Alarm_Tone_Setting.h
 *
 * Created: 8/15/2021 12:04:11 AM
 *  Author: ALPHAXANDER
 */ 


#ifndef ALARM_TONE_SETTING_H_
#define ALARM_TONE_SETTING_H_

#define F_CPU 16000000UL


#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include "tone.h"
#include "tone.cpp"
#include "note_freq.h"
#include "melodies.h"



#define SPEAKER PORTD7

//int Alarm_tone = 1;

void song(); //define a function to play song by song
void pirate_of(); //define a function to play pirates of the carebean sea
void play_melody(const int melody[],const int tempo, const int notes );//define a function to play any other melodies

//int Alarn_tone = 1;




void song(int Alarm_Tone){
	
	
	if (Alarm_Tone==1){pirate_of();}
	
	
	else if (Alarm_Tone==2){play_melody((got_melody), (got_tempo), (got_notes));}
	
	else if (Alarm_Tone==3){play_melody((fur_melody), (fur_tempo), (fur_notes));}
	
	else if (Alarm_Tone==4){play_melody((pink_melody), (pink_tempo), (pink_notes));}
	
	else if (Alarm_Tone==5){play_melody((turtis_melody), (turtis_tempo), (turtis_notes));}
	
}


void pirate_of()      // function to play the pirate of the Caribbean sea
{
	const int totalNotes = sizeof(pcs_notes) / sizeof(int);
	for (int i = 0; i < totalNotes; i++)
	{
		const int currentNote = pgm_read_word(&pcs_notes[i]);
		float wait = pgm_read_word(&pcs_durations[i]) / pcs_tempo;
		if ( !(~PINC &(1<<PINC3))) // checks the play pause switch
		{
			if (currentNote != 0)
			{
				PORTC |= (1<<PORTC2);
				tone(SPEAKER, pgm_read_word(&pcs_notes[i]), wait);
			}
			else
			{
				noTone(SPEAKER);
			}
			PORTC &= ~(1<<PORTC2);
			_delay_ms(wait);
			
			
		}
		else // Play tone if currentNote is not 0 frequency, otherwise pause (noTone)
		{
			
			break;
		}
		
	}
	
	return;
}



void play_melody(const int melody[],const int tempo,const int notes) // function to play any melody
{
	int wholenote = (60000 * 4) / tempo;
	int divider = 0, noteDuration = 0;
	
	// iterate over the notes of the melody.
	for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
		divider = (pgm_read_word(&melody[thisNote + 1]));
		if (divider > 0) {
			noteDuration = (wholenote) / divider;  // regular note, just proceed
		}
		else if (divider < 0) {
			noteDuration = (wholenote) / (-1*(divider));// dotted notes are represented with negative durations!!
			noteDuration *= 1.5; // increases the duration in half for dotted notes
		}
		
		
		
		if (!(~PINC &(1<<PINC3)))   // checks the play pause switch
		{
			PORTC |= (1<<PORTC2);
			tone(SPEAKER, (pgm_read_word(&melody[thisNote])), noteDuration * 0.9); //play the note for 90% of the duration, leaving 10% as a pause
			PORTC &= ~(1<<PORTC2);
			_delay_ms(noteDuration);
			
			noTone(SPEAKER);
			
		}
		else{
			
			break;
		}
		
		
		
		
		
		
		
		
	}
	return;
}






#endif /* ALARM_TONE_SETTING_H_ */