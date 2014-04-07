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
#include "DECFSZ.h"

unsigned char FSR[0x1000];

/**
// decrement file skip next instruction if result is zero
// input: bytecode
// return: absoluteAddress +2 if result is zero
// return: absoluteAddress +1 if result is not zero
**/
int decfsz(Bytecode *code){
	
	switch(check_valid_operands(code)){
	
		case 1: //access, store in wreg
			FSR[code->operand1]--; //decrement operand1 value
			FSR[WREG] = FSR[code->operand1]; //store value in wreg

			if(FSR[code->operand1] == 0) //if skip
				return code->absoluteAddress += 2;
			else						 //if doesnt skip
				return code->absoluteAddress += 1;
			
			break;
			
		case 2:	//access store in file reg
			FSR[code->operand1]--; //decrement operand1 value
			FSR[code->operand1] = FSR[code->operand1]; //store value in file reg
			
			if(FSR[code->operand1] == 0) //if skip
				return code->absoluteAddress += 1;
			else						 //if doesnt skip
				return code->absoluteAddress += 2;
			
			break;
			
		case 3:	//banked, store in wreg
			FSR[code->operand1+(FSR[BSR]<<8)]--; //decrement operand1 value with bsr
			FSR[WREG] = FSR[code->operand1+(FSR[BSR]<<8)]; //store value in wreg
			
			if(FSR[code->operand1+(FSR[BSR]<<8)] == 0) //if skip
				return code->absoluteAddress += 2;
			else									   //if doesnt skip
				return code->absoluteAddress += 1;
			
			break;
		
		case 4:	//banked, store in file
			FSR[code->operand1+(FSR[BSR]<<8)]--; //decrement operand1 value with bsr
			FSR[code->operand1+(FSR[BSR]<<8)] = FSR[code->operand1+(FSR[BSR]<<8)]; //store value in file reg
			
			if(FSR[code->operand1+(FSR[BSR]<<8)] == 0) //if skip
				return code->absoluteAddress += 2;
			else									   //if doesnt skip
				return code->absoluteAddress += 1;
			
			break;	
		
	}
	
}








