#include <stdio.h>
#include "Bytecode.h"
#include "SWAPF.h"

char FSR[0x1000];

void swapf(Bytecode *code){

int temp1, temp2;

if(code->operand3 == 0){
	if(code->operand2 == 0){
		
		temp1 = FSR[code->operand1]; //store fsr value in temp
		temp2 = temp1;

		FSR[WREG] = (temp1<<4)+(temp2>>4); //swap nibble and store in wreg
		}

	else if(code->operand2 == 1){
	
		temp1 = FSR[code->operand1]; //store fsr value in temp
		temp2 = temp1;

		code->operand1 = (temp1<<4)+(temp2>>4); //swap nibble and store in operand1
	}

	else
		printf("error operand 2, destination\n");
	}


else if(code->operand3 == 1){
	if(code->operand2 == 0){
	
		temp1 = FSR[code->operand1+(FSR[BSR]<<8)]; //store value into temp
		temp2 = temp1;
		
		FSR[WREG] = ((temp1<<4)+(temp2>>4)); //swap nibble and place to wreg
		}

	else if(code->operand2 == 1){
		
		temp1 = FSR[code->operand1+(FSR[BSR]<<8)]; //store value into temp
		temp2 = temp1;
		
		FSR[code->operand1+(FSR[BSR]<<8)] = ((temp1<<4)+(temp2>>4)); //swap nibble and replace value
	}

	else
		printf("operand error, destination\n");
	}

else
	printf("operand 3 error, bsr\n");
}