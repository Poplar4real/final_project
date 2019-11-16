#include<reg52.h>
#include<intrins.h>

double distance;

sbit echo = P1^7;
sbit trig = P1^6;


extern void delay_us(unsigned char us); // delay(us)us.The function is in the main.c.

//<summary>
//initialize the ultrosonic
//</summary>
void init_ultrosonic_main()
{	
	trig = 0; 
}

//<summary>
//the trig seg send a 10us high voltage
//</summary>
void active_ultrosonic_main()
{
	trig = 1;
	delay_us(10);
	trig = 0;
	delay_us(2);
}

//<summary>
//intialize the timer_0.
//</summary>
void init_timer0()
{
	EA = 1; 
	ET0 = 1; 
	TR0 = 0;
	TMOD = 0x01;
	TH0 = 0;
	TL0 = 0; 
}


double measure_distance_main()
{
	unsigned char low_di; //store TL0
	unsigned char high_di; //store TH0
	unsigned int time; //total time
	active_ultrosonic_main(); // activate the ultrosonic
	while(echo == 0);
	TR0 = 1;
	while(echo == 1);
	TR0 = 0;
	low_di = TL0; high_di = TH0;
	time = (high_di << 8) | low_di;
	distance = 0.017 * time;
	TH0 = TL0 = 0;
	return distance;
}



