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
/**
 * Author: Poon Jon
 * Email: poonjon93@gmail.com
 * Date: 29/3/2014
 * Project name: PIC18 simulator
 * Programme: Microelectronics with Embedded Technology
 * Institution: Tunku Abdul Rahman University College
 * Copyright: GPLv3
 */

#include "CException.h"
#include "Bytecode.h"
#include "Execute.h"
#include "RLCF.h"

unsigned char FSR[0x1000];

/**
// rotate left with carry
// input: bytecode
// return: absoluteAddress +1
**/
int rlcf(Bytecode *code){
	int status;
	int temp1, temp2;

	switch(check_valid_operands(code)){
	
		case 1: //access, store in wreg
			FSR[WREG] = (FSR[code->operand1]<<1)|(FSR[STATUS]&0x01);
			temp1 = FSR[WREG];
			FSR[STATUS] = (FSR[code->operand1]>>7)|check_negative(temp1)|check_zero(temp1);
			code->absoluteAddress += 1;
			break;
			
		case 2:	//access store in file reg
			temp1 = FSR[code->operand1];
			FSR[code->operand1] = (FSR[code->operand1]<<1)|(FSR[STATUS]&0x01);
			temp2 = FSR[code->operand1];
			FSR[STATUS] = (temp1>>7)|check_negative(temp2)|check_zero(temp2);
			code->absoluteAddress += 1;
			break;
			
		case 3:	//banked, store in wreg
			FSR[WREG] = (FSR[code->operand1+(FSR[BSR]<<8)]<<1)|(FSR[STATUS]&0x01);
			temp1 = FSR[WREG];
			FSR[STATUS] = (FSR[code->operand1+(FSR[BSR]<<8)]>>7)|check_negative(temp1)|check_zero(temp1);
			code->absoluteAddress += 1;
			break;
		
		case 4:	//banked, store in file
			temp1 = FSR[code->operand1+(FSR[BSR]<<8)];
			FSR[code->operand1+(FSR[BSR]<<8)] = (FSR[code->operand1+(FSR[BSR]<<8)]<<1)|(FSR[STATUS]&0x01);
			temp2 = FSR[code->operand1+(FSR[BSR]<<8)];
			FSR[STATUS] = (temp1>>7)|check_negative(temp2)|check_zero(temp2);
			code->absoluteAddress += 1;
			break;
		
	}
	
}








