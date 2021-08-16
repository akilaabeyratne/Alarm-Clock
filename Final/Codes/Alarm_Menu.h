/*
 * Alarm_Menu.h
 *
 * Created: 8/12/2021 3:52:09 AM
 *  Author: ALPHAXANDER
 */ 


#ifndef ALARM_MENU_H_
#define ALARM_MENU_H_

#include "LCD.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include "Set_ALarm.h"

int Alarm_Menu=1;
int Alarm[5][2];

void update_Alarm_Menu(){
	switch(Alarm_Menu){
		case 0:
		Alarm_Menu = 1;
		break;
		case 1:							//initial display state
		LCD_Init();
		LCD_Clear();
		LCD_String("    Alarm 01  >>");
		LCD_Command(0xC0);
		LCD_Alarm_Print(Alarm[0][0],Alarm[0][1]);
		break;
		case 2:							//2nd display state
		LCD_Init();
		LCD_Clear();
		LCD_String("<<  Alarm 02  >>");
		LCD_Command(0xC0);
		LCD_Alarm_Print(Alarm[1][0],Alarm[1][1]);
		break;
		case 3:							//Third display state
		LCD_Init();
		LCD_Clear();
		LCD_String("<<  Alarm 03  >>");
		LCD_Command(0xC0);
		LCD_Alarm_Print(Alarm[2][0],Alarm[2][1]);
		break;
		case 4:							//fourth display state
		LCD_Init();
		LCD_Clear();
		LCD_String("<<  Alarm 04  >>");
		LCD_Command(0xC0);
		LCD_Alarm_Print(Alarm[3][0],Alarm[3][1]);
		break;
		case 5:
		LCD_Init();
		LCD_Clear();
		LCD_String("<<  Alarm 05    ");
		LCD_Command(0xC0);
		LCD_Alarm_Print(Alarm[4][0],Alarm[4][1]);
		break;
		case 6:
		Alarm_Menu = 4;
	}
}

void execute_alarmAction()
{
	switch (Alarm_Menu) {
		case 1:
		Alarm_01_Action();
		break;
		case 2:
		Alarm_02_Action();
		break;
		case 3:
		Alarm_03_Action();
		break;
		case 4:
		Alarm_04_Action();
		break;
		case 5:
		Alarm_05_Action();
		break;
	}
	
}

void Alarm_01_Action(){     // Setting Alarm 01
	LCD_Init();
	LCD_Clear();
	LCD_Alarm_Print(Alarm[0][0],Alarm[0][1]);
	Alarm_insert(0);
}

void Alarm_02_Action(){   // Setting Alarm 02
	LCD_Init();
	LCD_Clear();
	LCD_Alarm_Print(Alarm[1][0],Alarm[1][1]);
	Alarm_insert(1);
}

void Alarm_03_Action(){ // Setting Alarm 03
	LCD_Init();
	LCD_Clear();
	LCD_Alarm_Print(Alarm[2][0],Alarm[2][1]);
	Alarm_insert(2);
}

void Alarm_04_Action(){ // Setting Alarm 04
	LCD_Init();
	LCD_Clear();
	LCD_Alarm_Print(Alarm[3][0],Alarm[3][1]);
	Alarm_insert(3);
}

void Alarm_05_Action(){ // Setting Alarm 05
	LCD_Init();
	LCD_Clear();
	LCD_Alarm_Print(Alarm[4][0],Alarm[4][1]);
	Alarm_insert(4);
}







void Alarm_Menu_Buttons()    // Navigating through alarm Menu
{
	
	while(1)
	{   
		DDRD=0x0f;
		PORTD&=0xfe;
		
		if (~PINC & (1<<PINC0)){
			_delay_ms(1000);
			LCD_Clear();
			execute_alarmAction();
		}
		else if (~PINC & (1<<PINC1)){
            updateMenu();
            _delay_ms(1000);
			break;
		}
		else if (~PIND & (1<<PIND4)){
			
			Alarm_Menu--;
			update_Alarm_Menu();
			_delay_ms(1000);
			
			
		}
		else if (~PIND & (1<<PIND6)){
			
			Alarm_Menu++;
			update_Alarm_Menu();
			_delay_ms(1000);
			
			
		}
		
		
		
	}


}





#endif /* ALARM_MENU_H_ */