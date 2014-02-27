#include <stdio.h>
#include "Bytecode.h"
#include "LiteralOperations.h"

char FSR[0x1000];

void sublw(Bytecode *code){
	
	FSR[WREG] = code->operand1 - FSR[WREG];
	
}