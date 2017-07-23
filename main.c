/* Main.c file generated by New Project wizard
 *
 * Created:   ?? 7? 20 2017
 * Processor: 80C51
 * Compiler:  Keil for 8051
 */

#include <reg51.h>
#include <stdio.h>

#include "init.h"
#include "time.h"
#include "value.h"
#include "screen.h"

uint min_1 = 0;
uint min_2 = 0;
uint sec_1 = 0;
uint sec_2 = 1;
uint ifstart = 0;
uint state = 0;        //开关闭合为0（接地）
sbit buzz = P0^1;
uint place = 0;      


void cgTime()
{
	ifstart = 0;
	if(place == 0)
	{
		if(sec_2 != 9)
			sec_2++;
		else
			sec_2 = 0;
	}
	else if(place == 1)
	{
		if(sec_1 != 9)
			sec_1++;
		else
			sec_1 = 0;
	}
	else if(place == 2)
	{
		if(min_2 != 9)
			min_2++;
		else
			min_2 = 0;
	}
	else if(place == 3)
	{
		if(min_1 != 9)
			min_1++;
		else
			min_1 = 0;
	}
}

void swTime()
{
	if(place != 3)
		place++;
	else
		place = 0;
}

void decTime()
{
	if (sec_2 != 0)
	{
		sec_2--;
	}else
	{
		if(sec_1 !=0)
		{
			sec_1--;
			sec_2 = 9;
		}else
		{
			if(min_2 != 0)
			{
				min_2--;
				sec_1 = 5;
				sec_2 = 9;
			}else
            {
                if(min_1 != 0)
                {
                    min_1--;
                    min_2 = 9;
                    sec_1 = 5;
                    sec_2 = 9;
                }else{
                }
            }
		}
	}
}

void main(void)
{
	uint i;
	init();
	buzz = 1;

	while(1)
	{
		if(ifstart == 0)
			setScreen(min_1,min_2,sec_1,sec_2);
		else
		{
			for(i = 1; i<=125; i++)
			{
				setScreen(min_1,min_2,sec_1,sec_2);
			}
			decTime();
			if(min_1 == 0 && min_2 == 0 && sec_1 == 0 && sec_2==0)
			{
				ifstart = 0;
				buzz = 0;
				delay(2000);
				buzz = 1;
			}
		}
	}
}

void interrupt_cg_start() interrupt 0
{
    cg_start = 0;
	ifstart = 0;
	state = statePin;
	if(state == 0)
		cgTime();
	else
		ifstart = 1;
    cg_start = 1;
}

void interrupt_sw_cls() interrupt 2
{
	sw_cls = 0;
	ifstart = 0;
	state = statePin;
	if(state == 0)
		swTime();
	else
	{
		min_1 = 0;
		min_2 = 0;
		sec_1 = 0;
		sec_2 = 0;
	}
	sw_cls = 1;
}