/**
 * Author: Poon Jon
 * Email: poonjon93@gmail.com
 * Date: 29/3/2014
 * Project name: PIC18 simulator
 * Programme: Microelectronics with Embedded Technology
 * Institution: Tunku Abdul Rahman University College
 * Copyright: GPLv3
 */

#include <stdio.h>
#include "CException.h"
#include "Bytecode.h"
#include "PUSH.h"

unsigned char FSR[0x1000];
unsigned int PIC18Stack[32];

/**
// increment stack pointer and increment absoluteAddress 
// input: bytecode
// return: temp
**/
int push(Bytecode *code){
	int temp;
	FSR[STKPTR]++;
	temp = ++FSR[code->absoluteAddress];
	PIC18Stack[FSR[STKPTR]] = temp;
	return temp;
}