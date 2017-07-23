#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "init.h"
#include "value.h"

void setScreen(uint min_1, uint min_2, uint sec_1, uint sec_2)
{
    tubeSwitch = swScreen[1];
	tubeNum = segCode[min_1];
	delay(2);
	tubeSwitch = swScreen[2];
	tubeNum = segCode[min_2];
	delay(2);
    tubeSwitch = swScreen[3];
	tubeNum = segCode[sec_1];
	delay(2);
    tubeSwitch = swScreen[4];
	tubeNum = segCode[sec_2];
	delay(2);
}

#endif