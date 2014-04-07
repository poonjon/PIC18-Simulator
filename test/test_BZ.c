#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "BZ.h"

void setUp(void){}
void tearDown(void){}

void test_bz_should_return_1(void){
	int error;	
	
	Instruction inst = { .mnemonic = BZ, .name = "bz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xf12, .operand2 = -1, .operand3 = -1, .absoluteAddress = 0};
	
	FSR[code.operand1] = 1;
	
	bz(&code);
	TEST_ASSERT_EQUAL(1, bz(&code));
}

void test_bz_should_return_operand1(void){
	int error;	
	
	Instruction inst = { .mnemonic = BZ, .name = "bz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xf12, .operand2 = -1, .operand3 = -1, .absoluteAddress = 0};
	
	FSR[code.operand1] = 0;
	
	Try{
		bz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}

	TEST_ASSERT_EQUAL(code.operand1, bz(&code));
}

void test_bz_should_throw_exception(void){
	int error;	
	
	Instruction inst = { .mnemonic = BZ, .name = "bz" };
	Bytecode code = {.instruction = &inst, .operand1 = -1, .operand2 = -1, .operand3 = -1, .absoluteAddress = 0};
	
	FSR[code.operand1] = 0;
	
	Try{
		bz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	Try{
		bz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
}
