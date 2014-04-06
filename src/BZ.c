#include <stdio.h>
#include "CException.h"
#include "Bytecode.h"
#include "BZ.h"

unsigned char FSR[0x1000];

int bz(Bytecode *code){
	
	if(code->operand1 > -1 && code->operand1 <= 0xfff){
		if(FSR[code->operand1] != 0)
			return code->absoluteAddress =+ 1;
		else
			return code->operand1;
	}	
	
	else
		Throw(ERR_INVALID_OPERAND);
}