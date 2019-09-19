# include<reg52.h>

sbit h1 = P2^0;//???
sbit h2 = P2^1;
sbit h3 = P2^2;
sbit h4 = P2^3;
sbit dp = P2^4;

unsigned char num[]=
{
	0x03,0x9f,0x25,0x0d,
	0x99,0x49,0x41,0x11,
	0x01,0x19
};//8????????


void delay(unsigned char ms)
{
	char j;
	while(ms--)
		for(j=0;j<120;j++);
}

void show_distance(double distance)
{
	unsigned char num_1,num_2,num_3,num_4;
	h1=h2=h3=h4=0;
	dp=1;
	if(distance >= 100)
	{	
		distance = (int)(10*distance);
		num_1 = ((int)distance/1000) % 10;
		num_2 = ((int)distance/100) % 10;
		num_3 = ((int)distance/10) % 10;
		num_4 = (int)distance%10; 
		while(1)
		{
			h4=0;
			P0 = num[num_1];
			h1=1;
			delay(1);
			h1=0;
			P0 = num[num_2];
			h2=1;
			delay(1);
			h2=0;
			P0 = num[num_3];
			h3=1;dp = 0;
			delay(1);
			dp=1;h3=0;
			P0 = num[num_4];
			h4=1;
			delay(1);
		}
	}
	else if(distance < 100 && distance >=10)
	{
		distance = (int)(100*distance);
		num_1 = ((int)distance/1000) % 10;
		num_2 = ((int)distance/100) % 10;
		num_3 = ((int)distance/10) % 10;
		num_4 = (int)distance%10;
		while(1)
		{
			h4=0;
			P0 = num[num_1];
			h1=1;
			delay(1);
			h1=0;
			P0 = num[num_2];
			h2=1;dp=0;
			delay(1);
			dp=1;h2=0;
			P0 = num[num_3];
			h3=1;
			delay(1);
			h3=0;
			P0 = num[num_4];
			h4=1;
			delay(1);
		}
	}
	else if(distance < 10)
	{
		distance = (int)(1000*distance);
		num_1 = ((int)distance/1000) % 10;
		num_2 = ((int)distance/100) % 10;
		num_3 = ((int)distance/10) % 10;
		num_4 = (int)distance%10;
		while(1)
		{
			h4=0;P0 = num[num_1];
			h1=1;dp=0;
			delay(1);
			dp=1;h1=0;
			P0 = num[num_2];
			h2=1;
			delay(1);
			h2=0;
			P0 = num[num_3];
			h3=1;
			delay(1);
			h3=0;
			P0 = num[num_4];
			h4=1;
			delay(1);
		}
	}
}

void main()
{
	while(1)
		show_distance(7.897);
}
