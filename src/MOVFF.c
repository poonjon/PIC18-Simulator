#include <stdio.h>
#include "Bytecode.h"
#include "MOVFF.h"

char FSR[0x1000];

void movff(Bytecode *code){

	
	FSR[code->operand2] = FSR[code->operand1];

}