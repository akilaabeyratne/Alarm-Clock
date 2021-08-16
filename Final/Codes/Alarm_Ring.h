/*
 * Alarm_Ring.h
 *
 * Created: 8/14/2021 11:39:10 PM
 *  Author: ALPHAXANDER
 */ 


#ifndef ALARM_RING_H_
#define ALARM_RING_H_
#include "Alarm_Tone_Setting.h"
#include "String.h"
bool Alarm_status[5];



void Alarm_Ring(int Alarm_Tone,int hour, int minute, int second){          //Alarm Ringing condition
	for (int i=0;i<5;i++){
		if (Alarm_status[i]){
			if ((Alarm[i][0]==hour) && (Alarm[i][1]==minute) && (00==second)){
				menu_can_access = false;
				LCD_Clear();
				LCD_Ring_Print(Alarm[i][0],Alarm[i][1]);
				_delay_ms(1000);
				song(Alarm_Tone);
				LCD_Clear();
				menu_can_access = true;
			}
		}
	}
}



#endif /* ALARM_RING_H_ */