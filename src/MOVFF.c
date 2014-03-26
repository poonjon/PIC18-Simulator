#include <stdio.h>
#include "CException.h"
#include "Bytecode.h"
#include "MOVFF.h"

char FSR[0x1000];

void movff(Bytecode *code){

	if(code->operand1 > -1 && code->operand1 <= 0xFFF && code->operand2 > -1 && code->operand2 < 0xFFD && code->operand2 != 0xFF9 && code->operand3 == -1){
		FSR[code->operand2] = FSR[code->operand1];
	}
	
	else 
		Throw(ERR_INVALID_OPERAND);
}