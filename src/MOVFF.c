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
#include "MOVFF.h"

char FSR[0x1000];
int PC; 

/**
// move a value from a file address to another file address
// input: bytecode
// return: absoluteAddress +1
**/
void movff(Bytecode *code){

	if(code->operand1 > -1 && code->operand1 <= 0xFFF && code->operand2 > -1 && code->operand2 < 0xFFD && code->operand2 != 0xFF9 && code->operand3 == -1){
		FSR[code->operand2] = FSR[code->operand1];
		code->absoluteAddress += 1;
	}
	
	else 
		Throw(ERR_INVALID_OPERAND);
}