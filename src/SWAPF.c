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
#include "SWAPF.h"

unsigned char FSR[0x1000];

/**
// swap upper nibble with lower nibble
// input: bytecode
// return: absoluteAddress +1
**/
int swapf(Bytecode *code){
	int temp1, temp2;
	
	switch(check_valid_operands(code)){
	
		case 1: //normal, access, store in wreg
			temp1 = FSR[code->operand1]; //store fsr value in temp
			temp2 = temp1;
			FSR[WREG] = (temp1<<4)+(temp2>>4); //swap nibble and store in wreg
			code->absoluteAddress += 1;
			break;
			
		case 2:	//normal, access store in file reg
			temp1 = FSR[code->operand1]; //store fsr value in temp
			temp2 = temp1;
			FSR[code->operand1] = (temp1<<4)+(temp2>>4); //swap nibble and store in operand1	
			code->absoluteAddress += 1;
			break;
			
		case 3:	//normal, banked, store in wreg
			temp1 = FSR[code->operand1+(FSR[BSR]<<8)]; //store value into temp
			temp2 = temp1;
			FSR[WREG] = ((temp1<<4)+(temp2>>4)); //swap nibble and place to wreg
			code->absoluteAddress += 1;
			break;
		
		case 4:	//normal, banked, store in file
			temp1 = FSR[code->operand1+(FSR[BSR]<<8)]; //store value into temp
			temp2 = temp1;
			FSR[code->operand1+(FSR[BSR]<<8)] = ((temp1<<4)+(temp2>>4)); //swap nibble and replace value
			code->absoluteAddress += 1;
			break;		
	}
	
	return 0;
	
}
