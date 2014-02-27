#include "unity.h"
#include "Bytecode.h"
#include "LiteralOperations.h"

void setUp() {}
void tearDown() {}

void test_sublw_1_minus_1_equal_0(){
	Instruction inst = { .mnemonic = SUBLW, .name = "sublw" };
	Bytecode code = {.instruction = &inst, .operand1 = 1, .operand2 = -1, .operand3 = -1};
	
	FSR[WREG] = 1;
	
	sublw(&code);
	
	TEST_ASSERT_EQUAL(0, FSR[WREG]);
	TEST_ASSERT_EQUAL_HEX8(0, FSR[WREG]);

}




