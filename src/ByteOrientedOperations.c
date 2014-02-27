#include <stdio.h>
#include "Bytecode.h"
#include "ByteOrientedOperations.h"


void setUp() {}
void tearDown() {}

void movff(Bytecode *code){
	int temp;
	
	FSR[code->operand1] = FSR[code->operand2];

}