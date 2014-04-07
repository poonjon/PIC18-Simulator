#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "PUSH.h"

void setUp(void){}
void tearDown(void){}

void test_push(void){
	int error;	
	
	Instruction inst = { .mnemonic = PUSH, .name = "push" };
	Bytecode code = {.instruction = &inst, .operand1 = -1, .operand2 = -1, .operand3 = -1, .absoluteAddress = 0};
	
	FSR[STKPTR] = 0;

	push(&code);
	TEST_ASSERT_EQUAL(0x1, FSR[STKPTR]);
	TEST_ASSERT_EQUAL_HEX16(0x1, PIC18Stack[FSR[STKPTR]]);
}