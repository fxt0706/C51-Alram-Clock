#ifndef _INIT_H_
#define _INIT_H_

#define uchar unsigned char
#define uint unsigned int
#define tubeNum P1 
#define tubeSwitch P2 
#define cg_start EX0
#define sw_cls EX1
#define statePin P0^0


void init()
{						
	EA=1;							//开总中断
	EX0=1;                          //增加分  INT0
	IT0=1;
	EX1=1;                          //增加秒  INT1
	IT1=1;
}

#endif
