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
#include "BZ.h"

unsigned char FSR[0x1000];

/**
// branch if zero
// input: bytecode
// return: absoluteAddress +1 if not zero, if zero return operand1
**/
int bz(Bytecode *code){
	
	if(code->operand1 > -1 && code->operand1 <= 0xfff){
		if(FSR[code->operand1] != 0)
			return code->absoluteAddress =+ 1;
		else
			return code->operand1;
	}	
	
	else
		Throw(ERR_INVALID_OPERAND);
}