#include <stdio.h>
#include "CException.h"
#include "Bytecode.h"
#include "BZ.h"

unsigned char FSR[0x1000];

int bz(Bytecode *code){

	if(FSR[code->operand1] != 0)
		return 0;
	else
		return 1;
		
}