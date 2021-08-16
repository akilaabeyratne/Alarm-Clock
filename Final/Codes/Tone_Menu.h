/*
 * Tone_Menu.h
 *
 * Created: 8/12/2021 4:42:08 AM
 *  Author: ALPHAXANDER
 */ 


#ifndef TONE_MENU_H_
#define TONE_MENU_H_

int Tone_Menu=1;
int Alarm_tone =1;
//bool sub_menu_action = true;


void update_Tone_Menu(){
	switch(Tone_Menu){
		case 0:
		Tone_Menu = 1;
		break;
		case 1:							//initial display state
		LCD_Init();
		LCD_Clear();
		LCD_String(">> Pirates Theme");
		LCD_Command(0xC0);
		LCD_String("   Game Thrones");
		break;
		case 2:							//2nd display state
		LCD_Init();
		LCD_Clear();
		LCD_String("   Pirates Theme");
		LCD_Command(0xC0);
		LCD_String(">> Game Thrones");
		break;
		case 3:							//Third display state
		LCD_Init();
		LCD_Clear();
		LCD_String(">> Fur Elise");
		LCD_Command(0xC0);
		LCD_String("   P.Panther");
		break;
		case 4:							//fourth display state
		LCD_Init();
		LCD_Clear();
		LCD_String("   Fur Elise");
		LCD_Command(0xC0);
		LCD_String(">> P.Panther");
		break;
		case 5:
		LCD_Init();
		LCD_Clear();
		LCD_String("   P.Panther");
		LCD_Command(0xC0);                 //5th display
		LCD_String(">> Turtis");  
		break;
		case 6:
		Alarm_Menu = 4;
	}
}


void execute_Tone_Action(Tone_Menu)
{
	Alarm_tone=Tone_Menu;
	LCD_Clear;
	LCD_String("ALARM TONE SET");
	_delay_ms(1000);
	LCD_Clear;
	updateMenu();
	
}

void Tone_Menu_Buttons()
{
	
	while(1)
	{
		DDRD=0x0f;
		PORTD&=0xfe;
		
		if (~PINC & (1<<PINC0)){
			_delay_ms(1000);
			LCD_Clear();
			execute_Tone_Action(Tone_Menu);
			break;
		}
		else if (~PINC & (1<<PINC1)){
			updateMenu();
			_delay_ms(1000);
			break;
		}
		else if (~PIND & (1<<PIND4)){
			
			Tone_Menu--;
			update_Tone_Menu();
			_delay_ms(1000);
			
			
		}
		else if (~PIND & (1<<PIND6)){
			
			Tone_Menu++;
			update_Tone_Menu();
			_delay_ms(1000);
			
			
		}
		
		
		
	}


}







#endif /* TONE_MENU_H_ */