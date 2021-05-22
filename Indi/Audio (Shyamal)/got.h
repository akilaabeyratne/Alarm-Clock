/*
 * got.h
 *
 * Created: 5/20/2021 9:36:03 AM
 *  Author: Shyamal
 */ 


#ifndef GOT_H_
#define GOT_H_

// change this to make the song slower or faster
int got_tempo = 150;

int got_melody[] = {

	// Game of Thrones
	// Score available at https://musescore.com/user/8407786/scores/2156716

	NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, //1
	NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16,
	NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16,
	NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16,
	NOTE_G4,-4, NOTE_C4,-4,//5

	NOTE_DS4,16, NOTE_F4,16, NOTE_G4,4, NOTE_C4,4, NOTE_DS4,16, NOTE_F4,16, //6
	NOTE_D4,-1, //7 and 8
	NOTE_F4,-4, NOTE_AS3,-4,
	NOTE_DS4,16, NOTE_D4,16, NOTE_F4,4, NOTE_AS3,-4,
	NOTE_DS4,16, NOTE_D4,16, NOTE_C4,-1, //11 and 12

	//repeats from 5
	NOTE_G4,-4, NOTE_C4,-4,//5

	NOTE_DS4,16, NOTE_F4,16, NOTE_G4,4, NOTE_C4,4, NOTE_DS4,16, NOTE_F4,16, //6
	NOTE_D4,-1, //7 and 8
	NOTE_F4,-4, NOTE_AS3,-4,
	NOTE_DS4,16, NOTE_D4,16, NOTE_F4,4, NOTE_AS3,-4,
	NOTE_DS4,16, NOTE_D4,16, NOTE_C4,-1, //11 and 12
	NOTE_G4,-4, NOTE_C4,-4,
	NOTE_DS4,16, NOTE_F4,16, NOTE_G4,4,  NOTE_C4,4, NOTE_DS4,16, NOTE_F4,16,

	NOTE_D4,-2,//15
	NOTE_F4,-4, NOTE_AS3,-4,
	NOTE_D4,-8, NOTE_DS4,-8, NOTE_D4,-8, NOTE_AS3,-8,
	NOTE_C4,-1,
	NOTE_C5,-2,
	NOTE_AS4,-2,
	NOTE_C4,-2,
	NOTE_G4,-2,
	NOTE_DS4,-2,
	NOTE_DS4,-4, NOTE_F4,-4,
	NOTE_G4,-1,
	
	NOTE_C5,-2,//28
	NOTE_AS4,-2,
	NOTE_C4,-2,
	NOTE_G4,-2,
	NOTE_DS4,-2,
	NOTE_DS4,-4, NOTE_D4,-4,
	NOTE_C5,8, NOTE_G4,8, NOTE_GS4,16, NOTE_AS4,16, NOTE_C5,8, NOTE_G4,8, NOTE_GS4,16, NOTE_AS4,16,
	NOTE_C5,8, NOTE_G4,8, NOTE_GS4,16, NOTE_AS4,16, NOTE_C5,8, NOTE_G4,8, NOTE_GS4,16, NOTE_AS4,16,
	
	0,4, NOTE_GS5,16, NOTE_AS5,16, NOTE_C6,8, NOTE_G5,8, NOTE_GS5,16, NOTE_AS5,16,
	NOTE_C6,8, NOTE_G5,16, NOTE_GS5,16, NOTE_AS5,16, NOTE_C6,8, NOTE_G5,8, NOTE_GS5,16, NOTE_AS5,16,
};

int got_notes = sizeof(got_melody) / sizeof(got_melody[0]) / 2;

int wholenote = (60000 * 4) / got_tempo;

int got_divider = 0, got_noteDuration = 0;




#endif /* GOT_H_ */