#include <stdio.h>
#include "CException.h"
#include "Bytecode.h"
#include "Execute.h"
#include "ADDWFC.h"

unsigned char FSR[0x1000];

int addwfc(Bytecode *code){

	unsigned int temp1, temp2, temp3, temp4;

	switch(check_valid_operands(code)){
	
		case 1: //access, store in wreg
			temp1 = FSR[code->operand1];
			temp2 = FSR[WREG];
			temp4 = (FSR[STATUS]&0x1);
			FSR[WREG] = FSR[code->operand1] + FSR[WREG] + (FSR[STATUS]&0x1); //add file with wreg
			temp3 = FSR[WREG] ;
			check_status(temp3, temp1, temp2, temp4);
			return 0;
			
			break;
			
		case 2:	//access store in file reg
			temp1 = FSR[code->operand1];
			temp2 = FSR[WREG];
			temp4 = (FSR[STATUS]&0x1);
			FSR[code->operand1] = FSR[code->operand1] + FSR[WREG] + (FSR[STATUS]&0x1); //add file with wreg
			temp3 = FSR[code->operand1];
			check_status(temp3, temp1, temp2, temp4);
			return 0;
			break;
			
		case 3:	//banked, store in wreg
			temp1 = FSR[code->operand1+(FSR[BSR]<<8)];
			temp2 = FSR[WREG];
			temp4 = (FSR[STATUS]&0x1);
			FSR[WREG] = FSR[code->operand1+(FSR[BSR]<<8)] + FSR[WREG] + (FSR[STATUS]&0x1); //add file with wreg
			temp3 = FSR[WREG];
			check_status(temp3, temp1, temp2, temp4);
			return 0;
			break;
		
		case 4:	//banked, store in file
			temp1 = FSR[code->operand1+(FSR[BSR]<<8)];
			temp2 = FSR[WREG];
			temp4 = (FSR[STATUS]&0x1);
			FSR[code->operand1+(FSR[BSR]<<8)] = FSR[code->operand1+(FSR[BSR]<<8)] + FSR[WREG] + (FSR[STATUS]& 0x1); //add file with wreg
			temp3 = FSR[code->operand1+(FSR[BSR]<<8)];
			check_status(temp3, temp1, temp2, temp4);
			return 0;
			break;
		
	}

	return 0;
}



