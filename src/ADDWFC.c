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
#include "Execute.h"
#include "ADDWFC.h"

unsigned char FSR[0x1000];

/**
// add wreg to file with carry
// input: bytecode
// return: absoluteAddress +1
**/
int addwfc(Bytecode *code){

	unsigned int temp1, temp2, result, carry_bit;

	switch(check_valid_operands(code)){
	
		case 1: //access, store in wreg
			temp1 = FSR[code->operand1];
			temp2 = FSR[WREG];
			carry_bit = (FSR[STATUS]&0x1);
			FSR[WREG] = FSR[code->operand1] + FSR[WREG] + (FSR[STATUS]&0x1); //add file with wreg
			result = FSR[WREG] ;
			check_status(result, temp1, temp2, carry_bit);
			code->absoluteAddress += 1;
			break;
			
		case 2:	//access store in file reg
			temp1 = FSR[code->operand1];
			temp2 = FSR[WREG];
			carry_bit = (FSR[STATUS]&0x1);
			FSR[code->operand1] = FSR[code->operand1] + FSR[WREG] + (FSR[STATUS]&0x1); //add file with wreg
			result = FSR[code->operand1];
			check_status(result, temp1, temp2, carry_bit);
			code->absoluteAddress += 1;
			break;
			
		case 3:	//banked, store in wreg
			temp1 = FSR[code->operand1+(FSR[BSR]<<8)];
			temp2 = FSR[WREG];
			carry_bit = (FSR[STATUS]&0x1);
			FSR[WREG] = FSR[code->operand1+(FSR[BSR]<<8)] + FSR[WREG] + (FSR[STATUS]&0x1); //add file with wreg
			result = FSR[WREG];
			check_status(result, temp1, temp2, carry_bit);
			code->absoluteAddress += 1;
			break;
		
		case 4:	//banked, store in file
			temp1 = FSR[code->operand1+(FSR[BSR]<<8)];
			temp2 = FSR[WREG];
			carry_bit = (FSR[STATUS]&0x1);
			FSR[code->operand1+(FSR[BSR]<<8)] = FSR[code->operand1+(FSR[BSR]<<8)] + FSR[WREG] + (FSR[STATUS]&0x1); //add file with wreg
			result = FSR[code->operand1+(FSR[BSR]<<8)];
			check_status(result, temp1, temp2, carry_bit);
			code->absoluteAddress += 1;
			break;
		
	}

	return 0;
}



