#include <stdio.h>
#include "CException.h"
#include "Bytecode.h"
#include "Execute.h"
#include "DECFSZ.h"

unsigned char FSR[0x1000];

int decfsz(Bytecode *code){
	
	switch(check_valid_operands(code)){
	
		case 1: //access, store in wreg
			FSR[code->operand1]--; //decrement operand1 value
			FSR[WREG] = FSR[code->operand1]; //store value in wreg

			if(FSR[code->operand1] == 0) //if skip
				return 1;
			else						 //if doesnt skip
				return 0;
			
			break;
			
		case 2:	//access store in file reg
			FSR[code->operand1]--; //decrement operand1 value
			FSR[code->operand1] = FSR[code->operand1]; //store value in file reg
			
			if(FSR[code->operand1] == 0) //if skip
				return 1;
			else						 //if doesnt skip
				return 0;
			
			break;
			
		case 3:	//banked, store in wreg
			FSR[code->operand1+(FSR[BSR]<<8)]--; //decrement operand1 value with bsr
			FSR[WREG] = FSR[code->operand1+(FSR[BSR]<<8)]; //store value in wreg
			
			if(FSR[code->operand1+(FSR[BSR]<<8)] == 0) //if skip
				return 1;
			else									   //if doesnt skip
				return 0;
			
			break;
		
		case 4:	//banked, store in file
			FSR[code->operand1+(FSR[BSR]<<8)]--; //decrement operand1 value with bsr
			FSR[code->operand1+(FSR[BSR]<<8)] = FSR[code->operand1+(FSR[BSR]<<8)]; //store value in file reg
			
			if(FSR[code->operand1+(FSR[BSR]<<8)] == 0) //if skip
				return 1;
			else									   //if doesnt skip
				return 0;
			
			break;	
		
	}
	
}








