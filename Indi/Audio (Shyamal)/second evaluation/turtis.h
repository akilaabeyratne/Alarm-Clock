/*
 * turtis.h
 *
 * Created: 5/23/2021 12:02:23 PM
 *  Author: Shyamal
 */ 


#ifndef TURTIS_H_
#define TURTIS_H_

int turtis_tempo=144; 

int turtis_melody[] = {

	//Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192
	
	NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
	NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
	NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
	NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

	NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
	NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
	NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
	NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,

	NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
	NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
	NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
	NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

	NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
	NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
	NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
	NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,
	

	NOTE_E5,2,  NOTE_C5,2,
	NOTE_D5,2,   NOTE_B4,2,
	NOTE_C5,2,   NOTE_A4,2,
	NOTE_GS4,2,  NOTE_B4,4,  REST,8,
	NOTE_E5,2,   NOTE_C5,2,
	NOTE_D5,2,   NOTE_B4,2,
	NOTE_C5,4,   NOTE_E5,4,  NOTE_A5,2,
	NOTE_GS5,2,

};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int turtis_notes=sizeof(turtis_melody)/sizeof(turtis_melody[0])/2;




#endif /* TURTIS_H_ */