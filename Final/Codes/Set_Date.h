/*
 * Set_Date.h
 *
 * Created: 8/10/2021 9:33:10 PM
 *  Author: ALPHAXANDER
 */ 


#ifndef Set_Date_H_
#define Set_Date_H_





void Date_insert()
{
	unsigned char c,r;
	int pos = 0 ;
	unsigned char k[4][3]={{14,0,15},{7,8,9},{4,5,6},{1,2,3}};
	int input=0;
	LCD_Init();
	char fog[10]={0};
	int Set_Date[10];
	int rtc_year=0;
	
	while(1)
	{
		DDRD = 0xf0;
		PORTD = 0x7f;
		if (pos<10 & pos!=4 & pos!=7){   // key pad input loop
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
				PORTD=0x6f;
				r=PIND&0x0f;
				if(r!=0x0f)
				{
					c=0;
					break;
				}
				PORTD=0x5f;
				r=PIND&0x0f;
				if(r!=0x0f)
				{
					c=1;
					break;
				}
				PORTD=0x3f;
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
				Set_Date[pos]=input;
			LCD_String_xy(0,pos,fog);
			LCD_Command(0xC0);
			LCD_String_xy(1,pos,"^");
			if (pos<10 & pos!=5 & pos!=8){
				LCD_String_xy(1,pos-1," ");
			}
			
			else if(pos==5 | pos ==8){
				LCD_String_xy(1,pos-2," ");
			}
			pos++;}
			
		} else if (pos==4 | pos==7){
			pos++;
		}
		else
		{
			pos=0;
			
		}
		
		if(input==14)  // Checking valid inputs for date setting
		{
			if ((2000<(Set_Date[0]*1000+Set_Date[1]*100+Set_Date[2]*10+Set_Date[3])<2099)&&(Set_Date[5]*10+Set_Date[6]<13) && (Set_Date[8]*10+Set_Date[9]<32)){
				
				Current_Time[0]=Set_Date[2]*10+Set_Date[3];
				Current_Time[1]=Set_Date[5]*10+Set_Date[6];  
				Current_Time[2]=Set_Date[8]*10+Set_Date[9];
				rtc_year=Set_Date[2]*10+Set_Date[3];
				Setdate(rtc_year,Current_Time[1],Current_Time[2],Current_Time[3],Current_Time[4],Current_Time[5]);
				LCD_Clear();
				LCD_String("DATE SET DONE");
				_delay_ms(500);
				update_Clock_Menu();
				_delay_ms(1000);
				break;
				}else{
				LCD_Clear();
				LCD_String("INVALID INPUT");
				_delay_ms(1000);
				LCD_Clear();
				LCD_Date_Print(Current_Time[0],Current_Time[1],Current_Time[2]);
				
			}
			
		}
		else if (input==15)
		{   //h=0;
			DDRD=0x0f;
			PORTD&=0x7e;
			update_Clock_Menu();
			_delay_ms(1000);
			break;
			
		}
	}
}







#endif /* SET_DATE._H_ */