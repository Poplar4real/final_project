#include<reg52.h>
#include<intrins.h>

double distance_left;

sbit echo = P1^1;
sbit trig = P1^0;

extern void delay_us(unsigned char us); // delay(us)us.The function is in the main.c.
extern void init_timer0();


//<summary>
//initialize the ultrosonic
//</summary>
void init_ultrosonic_left()
{	
	trig = 0; 
}

//<summary>
//the trig seg send a 10us high voltage
//</summary>
void active_ultrosonic_left()
{
	trig = 1;
	delay_us(10);
	trig = 0;
	delay_us(2);
}


double measure_distance_left()
{
	unsigned char low_di; //store TL0
	unsigned char high_di; //store TH0
	unsigned int time; //total time
	active_ultrosonic_left(); // activate the ultrosonic
	while(echo == 0);
	TR0 = 1;
	while(echo == 1);
	TR0 = 0;
	low_di = TL0; high_di = TH0;
	time = (high_di << 8) | low_di;
	distance_left = 0.017 * time;
	TH0 = TL0 = 0;
	return distance_left;
}