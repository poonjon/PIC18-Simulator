#include <stdio.h>
#include "Bytecode.h"
#include "ByteOrientedOperations.h"


void setUp() {}
void tearDown() {}

void movff(Bytecode *code){

	
	FSR[code->operand2] = FSR[code->operand1];

}