#ifndef _TIME_H_
#define _TIME_H_

#include "init.h"

void delay(uint n)
{
 	uchar j;
	while(n--)
	{
		for(j=0;j<113;j++);			//11.0592MHz时延时常数为113		  	
	}	
}

#endif