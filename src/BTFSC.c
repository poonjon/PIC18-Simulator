#include <stdio.h>
#include "CException.h"
#include "Bytecode.h"
#include "ExecuteBit.h"
#include "BTFSC.h"

unsigned char FSR[0x1000];


int btfsc(Bytecode *code){
	int value;
	
	switch(check_valid_operands(code)){
		
		case 1: //access
			value = FSR[code->operand1];
			return code->absoluteAddress =+ check_operand2(code, value);
			break;
			
		case 2:	//bank
			value = FSR[code->operand1+(FSR[BSR]<<8)];
			return code->absoluteAddress =+ check_operand2(code, value);
			break;
		
	}
}

