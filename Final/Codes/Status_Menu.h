/*
 * Delete_Menu.h
 *
 * Created: 8/12/2021 4:28:01 AM
 *  Author: ALPHAXANDER
 */ 


#ifndef DELETE_MENU_H_
#define DELETE_MENU_H_

#include "LCD.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>



int Status_Menu=1;
int Status_subMenu=1;
int Alarm[5][2];
int alarmNum=1;
bool Alarm_status[5];
void update_Status_Menu(){
	switch(Status_Menu){
		case 0:
		Status_Menu = 1;
		break;
		case 1:							//initial display state
		LCD_Init();
		LCD_Clear();
		LCD_Initial_Print(Status_Menu,Alarm[0][0],Alarm[0][1]);
		LCD_Command(0xC0);
		LCD_Condition_Print(Alarm_status[0],Alarm[0][0],Alarm[0][1]);
		break;
		case 2:							//2nd display state
		LCD_Init();
		LCD_Clear();
		LCD_Initial_Print(Status_Menu,Alarm[1][0],Alarm[1][1]);
		LCD_Command(0xC0);
		LCD_Condition_Print(Alarm_status[1],Alarm[1][0],Alarm[1][1]);
		break;
		case 3:							//Third display state
		LCD_Init();
		LCD_Clear();
		LCD_Initial_Print(Status_Menu,Alarm[2][0],Alarm[2][1]);
		LCD_Command(0xC0);
		LCD_Condition_Print(Alarm_status[2],Alarm[2][0],Alarm[2][1]);
		break;
		case 4:							//fourth display state
		LCD_Init();
		LCD_Clear();
		LCD_Initial_Print(Status_Menu,Alarm[3][0],Alarm[3][1]);
		LCD_Command(0xC0);
		LCD_Condition_Print(Alarm_status[3],Alarm[3][0],Alarm[3][1]);
		break;
		case 5:
		LCD_Init();
		LCD_Clear();
		LCD_Initial_Print(Status_Menu,Alarm[4][0],Alarm[4][1]);
		LCD_Command(0xC0);
		LCD_Condition_Print(Alarm_status[4],Alarm[4][0],Alarm[4][1]);
		break;
		case 6:
		Status_Menu = 4;
	}
}
void Delete_Action1(){
	Status_subMenu = 1;
	update_Status_subMenu(1);
	Status_subMenu_Buttons();
	//lcd_statusPrint(1,D_alarm[0][0],D_alarm[0][1]);
}

void Delete_Action2(){
	Status_subMenu = 1;
	update_Status_subMenu(2);
	Status_subMenu_Buttons();
	//lcd_statusPrint(2,12,45);
}

void Delete_Action3(){
	Status_subMenu = 1;
	update_Status_subMenu(3);
	Status_subMenu_Buttons();
	//lcd_statusPrint(3,12,45);
}

void Delete_Action4(){
	Status_subMenu = 1;
	update_Status_subMenu(4);
	Status_subMenu_Buttons();
	//lcd_statusPrint(4,13,45);
}

void Delete_Action5(){
	Status_subMenu = 1;
	update_Status_subMenu(5);
	Status_subMenu_Buttons();
	//lcd_statusPrint(5,14,45);
}

void update_Status_subMenu(int alarmNum){
	switch(Status_subMenu){
		case 0:
		Status_subMenu = 1;
		break;
		case 1:							//initial display state
		LCD_Init();
		LCD_Clear();
		LCD_Status_Print(alarmNum,Alarm[alarmNum][0],Alarm[alarmNum][1]);
		//LCD_String(">>Alarm01: 11:45");
		LCD_Command(0xC0);
		LCD_String(" <ON> OFF DEL   ");
		break;
		case 2:							//2nd display state
		LCD_Init();
		LCD_Clear();
		LCD_Status_Print(alarmNum,Alarm[alarmNum][0],Alarm[alarmNum][1]);
		LCD_Command(0xC0);
		LCD_String(" ON <OFF> DEL   ");
		break;
		case 3:							//3rd display state
		LCD_Init();
		LCD_Clear();
		LCD_Status_Print(alarmNum,Alarm[alarmNum][0],Alarm[alarmNum][1]);
		LCD_Command(0xC0);
		LCD_String(" ON OFF <DEL>   ");
		break;
		case 4:
		Status_subMenu = 1;
		break;
	}
}

void execute_StatusAction()
{
	switch (Status_Menu) {
		case 1:
		Delete_Action1();
		break;
		case 2:
		Delete_Action2();
		break;
		case 3:
		Delete_Action3();
		break;
		case 4:
		Delete_Action4();
		break;
		case 5:
		Delete_Action5();
		break;
	}
	
}


void Status_Menu_Buttons()   //Navigating through Alarm Statuses
{
	
	while(1)
	{
		DDRD=0x0f;
		PORTD&=0xfe;
		
		if (~PINC & (1<<PINC0)){
			_delay_ms(1000);
			LCD_Clear();
			execute_StatusAction();
		}
		else if (~PINC & (1<<PINC1)){
			updateMenu();
			_delay_ms(1000);
			break;
		}
		else if (~PIND & (1<<PIND4)){
			
			Status_Menu--;
			update_Status_Menu();
			_delay_ms(1000);
			
			
		}
		else if (~PIND & (1<<PIND6)){
			
			Status_Menu++;
			update_Status_Menu();
			_delay_ms(1000);
			
			
		}
		
		
		
	}


}

void Status_subMenu_Buttons()
{
	
	while(1)
	{
		DDRD=0x0f;
		PORTD&=0xfe;
		
		if (~PINC & (1<<PINC0)){
			_delay_ms(1000);
			LCD_Clear();
			execute_Status_sub_Action();
			break;
	
		}
		else if (~PINC & (1<<PINC1)){
			update_Status_Menu();
			_delay_ms(1000);
			break;
		}
		else if (~PIND & (1<<PIND4)){
			
			Status_subMenu--;
			update_Status_subMenu(Status_Menu);
			_delay_ms(1000);
			
			
		}
		else if (~PIND & (1<<PIND6)){
			
			Status_subMenu++;
			update_Status_subMenu(Status_Menu);
			_delay_ms(1000);
			
			
		}
	}
}



void execute_Status_sub_Action()
{
	switch (Status_subMenu) {
		case 1:
		ON_Action();
		break;
		case 2:
		OFF_Action();
		break;
		case 3:
		Del_Action();
		break;
	}
	
}



void ON_Action(){
	Alarm_status[Status_Menu-1]=true;
	LCD_Clear();
	LCD_String("ALARM IS ON");
	_delay_ms(1000);
	update_Status_Menu();
}


void OFF_Action(){
	Alarm_status[Status_Menu-1]=false;
	LCD_Clear();
	LCD_String("ALARM IS OFF");
	_delay_ms(1000);
	update_Status_Menu();
}

void Del_Action(){
	Alarm[Status_Menu-1][0]=00;
	Alarm[Status_Menu-1][1]=00;
	Alarm_status[Status_Menu-1]=false;
	LCD_Clear();
	LCD_String("ALARM IS DELETED");
	_delay_ms(1000);
	update_Status_Menu();
}

#endif /* DELETE_MENU_H_ */