#include <stdio.h>
#include "CException.h"
#include "Bytecode.h"
#include "Execute.h"
#include "RLCF.h"

unsigned char FSR[0x1000];

int rlcf(Bytecode *code){
	int status;
	int temp1, temp2, temp3, temp4;

	switch(check_valid_operands(code)){
	
		case 1: //access, store in wreg
			FSR[WREG] = (FSR[code->operand1]<<1)|(FSR[STATUS]&0x01);
			temp1 = FSR[WREG];
			FSR[STATUS] = (FSR[code->operand1]>>7)|check_negative(temp1)|check_zero(temp1);
			return 0;
			break;
			
		case 2:	//access store in file reg
			temp1 = FSR[code->operand1];
			FSR[code->operand1] = (FSR[code->operand1]<<1)|(FSR[STATUS]&0x01);
			temp2 = FSR[code->operand1];
			FSR[STATUS] = (temp1>>7)|check_negative(temp2)|check_zero(temp2);
			return 0;
			break;
			
		case 3:	//banked, store in wreg
			FSR[WREG] = (FSR[code->operand1+(FSR[BSR]<<8)]<<1)|(FSR[STATUS]&0x01);
			temp1 = FSR[WREG];
			FSR[STATUS] = (FSR[code->operand1+(FSR[BSR]<<8)]>>7)|check_negative(temp1)|check_zero(temp1);
			
			return 0;
			break;
		
		case 4:	//banked, store in file
			temp1 = FSR[code->operand1+(FSR[BSR]<<8)];
			FSR[code->operand1+(FSR[BSR]<<8)] = (FSR[code->operand1+(FSR[BSR]<<8)]<<1)|(FSR[STATUS]&0x01);
			temp2 = FSR[code->operand1+(FSR[BSR]<<8)];
			FSR[STATUS] = (temp1>>7)|check_negative(temp2)|check_zero(temp2);
			return 0;
			break;
		
	}
	
}








