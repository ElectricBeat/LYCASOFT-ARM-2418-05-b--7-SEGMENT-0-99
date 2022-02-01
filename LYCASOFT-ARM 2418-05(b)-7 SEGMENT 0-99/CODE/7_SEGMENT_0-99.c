#include<lpc21xx.h>
#include "LPC2148_delay.h"

char Data[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};			//comman cathode type;
//char Data[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};			//comman anode type;

int Count;

int main()
{
	PINSEL2 = 0x00000000;
	IODIR1 = 0x03ff0000;

	while(1)
	{
		for(Count=0;Count<100;Count++)
		{
			int j;
			for(j=0;j<10;j++)
			{
				int Disp1_Data,Disp2_Data,Disp3_Data,Disp4_Data;
				int Temp_DATA;
			
				Temp_DATA  = Count;						//6789;
				Disp1_Data = Temp_DATA % 10;	//Disp1=9;
				Temp_DATA  = Temp_DATA / 10;	//678;
				Disp2_Data = Temp_DATA % 10;	//Disp2=8;

//				Temp_DATA  = Temp_DATA / 10;	//67;
//				Disp3_Data = Temp_DATA % 10;	//7;
//				Disp4_Data = Temp_DATA / 10;

				IOSET1 = 0x02000000; 
				IOSET1 = Data[Disp2_Data]<<16;
				delay(50);
				IOCLR1 = Data[Disp2_Data]<<16;
				IOCLR1 = 0x02000000;
				
				IOSET1 = 0x01000000; 
				IOSET1 = Data[Disp1_Data]<<16; 
				delay(50);
				IOCLR1 = Data[Disp1_Data]<<16; 
				IOCLR1 = 0x01000000;
			}
		}
	}
}