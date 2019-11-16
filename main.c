# include<reg52.h>

sbit green_led = P1^2;
sbit red_led = P1^3;


void delay_ms(unsigned char ms);
void delay_us(unsigned char us);

extern void show_distance(double distance);
extern void init_timer0();
extern void show_left();
extern void show_right();


extern void init_ultrosonic_main();
extern double measure_distance_main();

extern void init_ultrosonic_left();
extern double measure_distance_left();

extern void init_ultrosonic_right();
extern double measure_distance_right();

extern void go_ahead();
extern void go_back();
extern void turn_right();
extern void turn_left();
extern void stop();


void main()
{
  int left_distance;
	int right_distance;
	while(1)
	{
		init_ultrosonic_main();
		init_timer0();
		show_distance(measure_distance_main());
		if(measure_distance_main() > 30)
		{
			go_ahead();
			delay_ms(700);
			stop();
		}
		else 
		{
			init_ultrosonic_right();
			init_ultrosonic_left();
			init_timer0();
			left_distance = measure_distance_left();
			init_timer0();
			right_distance = measure_distance_right();
			if(left_distance < 30 && right_distance >30)
			{
				green_led = 1;
				show_right();
				turn_right();
				delay_ms(1500);
				stop();
				green_led =0;
			}				
			else if(left_distance > 30 && right_distance < 30)
			{
				red_led= 1;
				show_left();
				turn_left();
				delay_ms(1500);
				red_led = 0;
				stop();
			}
			else if(left_distance < 30 && right_distance < 30)
			{
				green_led = red_led = 1;
				go_back();
				delay_ms(1000);
				stop();
				show_right();
				turn_right();
				delay_ms(1500);
				stop();
				green_led = red_led = 0;
			}
			else
			{
				green_led = 1;
				show_right();
				turn_right();
				delay_ms(1500);
				stop();
				green_led = 0;
			}	
 		}
	}
}

void timer0() interrupt 1
{
	TH0 = TL0 = 0;
}

void delay_ms(unsigned char ms)
{
	char j;
	while(ms--)
		for(j=0;j<120;j++);
}


void delay_us(unsigned char us)
{
	char j;
	for(j=0;j<us;j++);
}