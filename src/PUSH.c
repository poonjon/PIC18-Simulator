#include <stdio.h>
#include "CException.h"
#include "Bytecode.h"
#include "PUSH.h"

unsigned char FSR[0x1000];
unsigned int PIC18Stack[32];
int PC; 

void push(Bytecode *code){
	FSR[STKPTR]++;
	code->absoluteAddress += 1;
	PIC18Stack[FSR[STKPTR]] = code->absoluteAddress;
	
	return code->absoluteAddress;
}