/*
 * Set_ALarm.h
 *
 * Created: 8/14/2021 6:13:19 PM
 *  Author: ALPHAXANDER
 */ 


#ifndef SET_ALARM_H_
#define SET_ALARM_H_

int Alarm[5][2];
bool Alarm_status[5];





void Alarm_insert(int index)
{
	DDRD = 0xf0;
	PORTD = 0x7f;
	unsigned char c,r;
	int pos = 0 ;
	unsigned char k[4][3]={{14,0,15},{7,8,9},{4,5,6},{1,2,3}};
	int input=0;
	LCD_Init();
	char fog[10]={0};
	int Alarm_Time[5];
	
	while(1)
	{
		if (pos<5 & pos!=2)    // key pad input loop
		{
			do
			{
				PORTD&=0x0f;
				r=PIND&0x0f;
			} while(r!=0x0f);
			
			do
			{
				r=PIND&0x0f;
			}	  while(r==0x0f);
			
			while(1)
			{
				PORTD=0xef;
				r=PIND&0x0f;
				if(r!=0x0f)
				{
					c=0;
					break;
				}
				PORTD=0xdf;
				r=PIND&0x0f;
				if(r!=0x0f)
				{
					c=1;
					break;
				}
				PORTD=0xbf;
				r=PIND&0x0f;
				if(r!=0x0f)
				{
					c=2;
					
					break;
				}
				
			}
			

			if(r==0x0e)
			{
				input=k[0][c];
				itoa(input,fog,10);
			}
			else if(r==0x0d)
			{
				input=k[1][c];
				itoa(input,fog,10);
			}
			else if(r==0x0b)
			{
				input=k[2][c];
				itoa(input,fog,10);
			}
			else {
				input=k[3][c];
				itoa(input,fog,10);
			}
			
			if ((input!=14) && (input !=15)){
				Alarm_Time[pos]=input;
				LCD_String_xy(0,pos,fog);
				LCD_Command(0xC0);
				LCD_String_xy(1,pos,"^");
				
				if (pos<5 & pos!=3)
				{
					LCD_String_xy(1,pos-1," ");
				}
				
				else if(pos==3)
				{
					LCD_String_xy(1,pos-2," ");
				}
				
			pos++;}
			
			} else if (pos==2){
			pos++;
		}
		else
		{
			pos=0;
			
		}
		
		
		
		
		
		if(input==14)
		{
			if ((Alarm_Time[0]*10+Alarm_Time[1]<24)&&(Alarm_Time[3]*10+Alarm_Time[4]<60)){    // Checking valid iNPUTS FOR TIME SETTING
				
				Alarm[index][0]=Alarm_Time[0]*10+Alarm_Time[1];
				Alarm[index][1]=Alarm_Time[3]*10+Alarm_Time[4];
				Alarm_status[index]=true;
				LCD_Clear();
				LCD_String("ALARM SET DONE");
				_delay_ms(500);
				update_Alarm_Menu();
				_delay_ms(1000);
				break;
				}else{
				LCD_Clear();
				LCD_String("INVALID INPUT");
				_delay_ms(1000);
				LCD_Clear();
				LCD_Alarm_Print(Alarm[index][0],Alarm[index][1]);
				
			}
			
		}
		else if (input==15)
		{
			DDRD=0x0f;
			PORTD&=0xfe;
			update_Alarm_Menu();
			_delay_ms(1000);
			break;
			
		}
	}
	
}




#endif /* SET_ALARM_H_ */