/*
 * tone.h
 *
 * Created: 5/20/2021 12:58:18 AM
 *  Author: Shyamal
 */ 


#ifndef TONE_H_
#define TONE_H_

/* use portB for the audio output */ 

void tone(int SPEAKER_PIN, float frequency, float duration);
void noTone(int SPEAKER_PIN);




#endif /* TONE_H_ */