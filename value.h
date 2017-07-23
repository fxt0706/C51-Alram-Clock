#ifndef _VALUE_H_
#define _VALUE_H_


#include <stdio.h>

#include "init.h"

uchar segCode[]={ 						//段码表 Segment code
						0xc0,0xf9,0xa4,0xb0,  	//	0-0		1-1		2-2		3-3
						0x99,0x92,0x82,0xf8,	//	4-4		5-5		6-6		7-7
						0x80,0x90,0xff,0xa0,	//	8-8		9-9		10-空	11-a
						0x83,0xc6,0xa1,0x8b,	//	12-b	13-C	14-D	15-h
						0x8e,0xc2,0xc1,0x89,	//	16-F	17-G	18-U	19-H
						0xc7,0xbf,0x91,0x92,	//	20-L	21--	22-y	23-S
						0xc0,0x8c,0x86,0xc8		//	24-0	25-p	26-E	27-n
					    };

uchar swScreen[] = {0x00, 0x01, 0x02, 0x04, 0x08};

#endif