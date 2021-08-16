/*
 * String.h
 *
 * Created: 8/13/2021 7:37:01 PM
 *  Author: ALPHAXANDER
 */ 


#ifndef STRING_H_
#define STRING_H_

void LCD_Print(int year,int month, int day , int hour ,int minute ,int second){
int year1 = 2000 + year ;
char A[20];
char B[20];
char C[20];

if (minute<10 && second <10 && hour<10){
	sprintf(A,"TIME: 0%d:0%d:0%d  ",hour,minute,second);
}else if (hour<10 && minute<10){	sprintf(A,"TIME: 0%d:0%d:%d  ",hour,minute,second);}else if (hour<10 && second<10){	sprintf(A,"TIME: 0%d:%d:0%d  ",hour,minute,second);}else if (minute<10 && second<10){	sprintf(A,"TIME: %d:0%d:0%d  ",hour,minute,second);}else if (minute<10){
    sprintf(A,"TIME: %d:0%d:%d  ",hour,minute,second);
}else if (second<10){
    sprintf(A,"TIME: %d:%d:0%d  ",hour,minute,second);
}else if (hour<10){
    sprintf(A,"TIME: 0%d:%d:%d  ",hour,minute,second);}else{
    sprintf(A,"TIME: %d:%d:%d  ",hour,minute,second);
}


if (month<10 && day <10){
	sprintf(B,"DATE: %d/0%d/0%d ",year1,month,day);
	}else if (month<10){
	sprintf(B,"DATE: %d/0%d/%d ",year1,month,day);
	}else if (day<10){
	sprintf(B,"DATE: %d/%d/0%d ",year1,month,day);
	}else{
	sprintf(B,"DATE: %d/%d/%d ",year1,month,day);
}

LCD_String(A);
LCD_Command(0xC0);
LCD_String(B);
LCD_Command(0x80);
}



void LCD_Time_Print(int hour ,int minute ,int second){
	char A[20];
	if (minute<10 && second <10 && hour<10){
		sprintf(A,"0%d:0%d:0%d  ",hour,minute,second);
		}else if (hour<10 && minute<10){		sprintf(A,"0%d:0%d:%d  ",hour,minute,second);		}else if (hour<10 && second<10){		sprintf(A,"0%d:%d:0%d  ",hour,minute,second);		}else if (minute<10 && second<10){		sprintf(A,"%d:0%d:0%d  ",hour,minute,second);		}else if (minute<10){
		sprintf(A,"%d:0%d:%d  ",hour,minute,second);
		}else if (second<10){
		sprintf(A,"%d:%d:0%d  ",hour,minute,second);
		}else if (hour<10){
		sprintf(A,"0%d:%d:%d  ",hour,minute,second);		}else{
		sprintf(A,"%d:%d:%d        ",hour,minute,second);
	}
	LCD_String(A);
}


void LCD_Date_Print(int year ,int month ,int day){
	char B[20];
	int year1=2000+year;
	if (month<10 && day <10){
		sprintf(B,"%d/0%d/0%d      ",year1,month,day);
		}else if (month<10){
		sprintf(B,"%d/0%d/%d      ",year1,month,day);
		}else if (day<10){
		sprintf(B,"%d/%d/0%d      ",year1,month,day);
		}else{
		sprintf(B,"%d/%d/%d      ",year1,month,day);
	}
	LCD_String(B);
}


void LCD_Alarm_Print(int hour ,int minute){
	char C[20];
	   if (hour<10 && minute<10){		sprintf(C,"0%d:0%d           ",hour,minute);		}else if (minute<10){
		sprintf(C,"%d:0%d           ",hour,minute);
		}else if (hour<10){
		sprintf(C,"0%d:%d           ",hour,minute);		}else{
		sprintf(C,"%d:%d           ",hour,minute);
	}
	LCD_String(C);
}




void LCD_Status_Print(int num,int hour, int minute){
	char D[20];
	if (hour<10 && minute<10){
		sprintf(D,">>Alarm0%d= 0%d:0%d",num,hour,minute);
		}else if (minute<10){
		sprintf(D,">>Alarm0%d= %d:0%d",num,hour,minute);
		
		}else if (hour<10){
		sprintf(D,">>Alarm0%d= 0%d:%d",num,hour,minute);
		}else{
		sprintf(D,">>Alarm0%d= %d:%d",num,hour,minute);
	}
	LCD_String(D);

}


void LCD_Initial_Print(int num,int hour, int minute){
	char E[20];
	if (hour<10 && minute<10){
		sprintf(E,"Alarm0%d= 0%d:0%d  ",num,hour,minute);
		}else if (minute<10){
		sprintf(E,"Alarm0%d= %d:0%d  ",num,hour,minute);
		
		}else if (hour<10){
		sprintf(E,"Alarm0%d= 0%d:%d  ",num,hour,minute);
		}else{
		sprintf(E,"Alarm0%d= %d:%d  ",num,hour,minute);
	}
	LCD_String(E);

}

void LCD_Condition_Print(bool status,int hour, int minute){
	if ((status==false)&&(hour==00)&&(minute==00)){
		LCD_String("STATUS:NOT SET  ");
	}else if (status==false){
	LCD_String("STATUS:OFF       ");
	}else if (status==true){
	LCD_String("STATUS:ON        ");
	}

}

void LCD_Ring_Print(int hour, int minute){
	char F[20];
	if (hour<10 && minute<10){
		sprintf(F,"IT'S 0%d:0%d      ",hour,minute);
		}else if (minute<10){
		sprintf(F,"IT'S %d:0%d      ",hour,minute);
		
		}else if (hour<10){
		sprintf(F,"IT'S 0%d:%d      ",hour,minute);
		}else{
		sprintf(F,"IT'S %d:%d      ",hour,minute);
	}
	LCD_String(F);
	LCD_Command(0xC0);
	LCD_String("ALARM TIME");

}


#endif /* STRING_H_ */