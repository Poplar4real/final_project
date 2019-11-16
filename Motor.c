#include<reg52.h>

sbit IN1=P2^4;
sbit IN2=P2^5;
sbit IN3=P2^6;
sbit IN4=P2^7;


void go_ahead()
{
		IN1=1;//Ç°½ø 
		IN2=0;
		IN3=1;
		IN4=0;
}

void turn_left()
{
		IN1=0;//×ó×ª90¡ã 
		IN2=0;
		IN3=1;
		IN4=0;
}

		
void turn_right()
{
		IN1=1; 
		IN2=0;
		IN3=0;
		IN4=0;
}	

		
void go_back()
{
	  IN1=0;
		IN2=1;
		IN3=0;
		IN4=1;
}

void stop()
{
	IN1 = IN2 = IN3 = IN4 =0;
}