#include <stdio.h>
#include "CException.h"
#include "Bytecode.h"
#include "Execute.h"
#include "SWAPF.h"

unsigned char FSR[0x1000];

int swapf(Bytecode *code){
	int temp1, temp2;
	
	switch(check_valid_operands(code)){
	
		case 1: //normal, access, store in wreg
			temp1 = FSR[code->operand1]; //store fsr value in temp
			temp2 = temp1;
			FSR[WREG] = (temp1<<4)+(temp2>>4); //swap nibble and store in wreg
			break;
			
		case 2:	//normal, access store in file reg
			temp1 = FSR[code->operand1]; //store fsr value in temp
			temp2 = temp1;
			FSR[code->operand1] = (temp1<<4)+(temp2>>4); //swap nibble and store in operand1	
			break;
			
		case 3:	//normal, banked, store in wreg
			temp1 = FSR[code->operand1+(FSR[BSR]<<8)]; //store value into temp
			temp2 = temp1;
			FSR[WREG] = ((temp1<<4)+(temp2>>4)); //swap nibble and place to wreg
			break;
		
		case 4:	//normal, banked, store in file
			temp1 = FSR[code->operand1+(FSR[BSR]<<8)]; //store value into temp
			temp2 = temp1;
			FSR[code->operand1+(FSR[BSR]<<8)] = ((temp1<<4)+(temp2>>4)); //swap nibble and replace value
			break;		
		
	}
	
	return 0;
	
}
