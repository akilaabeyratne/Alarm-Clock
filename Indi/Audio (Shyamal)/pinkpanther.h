/*
 * pinkpanther.h
 *
 * Created: 5/22/2021 9:10:31 AM
 *  Author: Shyamal
 */ 


#ifndef PINKPANTHER_H_
#define PINKPANTHER_H_
#define REST      0

int pink_tempo = 120;

int pink_melody[] = {

	// Pink Panther theme
	// Score available at https://musescore.com/benedictsong/the-pink-panther
	// Theme by Masato Nakamura, arranged by Teddy Mason

	REST,2, REST,4, REST,8, NOTE_DS4,8,
	NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
	NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,
	NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16,
	NOTE_E4,2, REST,4, REST,8, NOTE_DS4,4,

	NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
	NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_G4,8, NOTE_B4,-8, NOTE_E5,8,
	NOTE_DS5,1,
	NOTE_D5,2, REST,4, REST,8, NOTE_DS4,8,
	NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
	NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,
	
	NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16,
	NOTE_E4,-4, REST,4,
	REST,4, NOTE_E5,-8, NOTE_D5,8, NOTE_B4,-8, NOTE_A4,8, NOTE_G4,-8, NOTE_E4,-8,
	NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8,
	NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, NOTE_E4,16, NOTE_E4,16, NOTE_E4,2,
	
};

int pink_notes = sizeof(pink_melody) / sizeof(pink_melody[0]) / 2;


#endif /* PINKPANTHER_H_ */