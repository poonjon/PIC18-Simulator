#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "PUSH.h"

void setUp(void){}
void tearDown(void){}

void test_push(void){
	int error;	
	
	Instruction inst = { .mnemonic = PUSH, .name = "push" };
	Bytecode code = {.instruction = &inst, .operand1 = -1, .operand2 = -1, .operand3 = -1};
	
	FSR[STKPTR] = 0;
	code.absoluteAddress = 0x0;
	PC = code.absoluteAddress;
	
	Try{
		push(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}

	TEST_ASSERT_EQUAL(0x1, FSR[STKPTR]);
	TEST_ASSERT_EQUAL_HEX16(0x2, PIC18Stack[FSR[STKPTR]]);
}
