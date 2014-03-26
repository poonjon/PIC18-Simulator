#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "SUBLW.h"

void setUp() {}
void tearDown() {}

void test_sublw_1_subtract_1_equal_0_carry_and_zero_should_set_to_1_should_pass(){
	int error;
	Instruction inst = { .mnemonic = SUBLW, .name = "sublw" };
	Bytecode code = {.instruction = &inst, .operand1 = 1, .operand2 = -1, .operand3 = -1};
	
	FSR[WREG] = 1;
	code.absoluteAddress = 0x00;
	
	Try{
		sublw(&code);	
		TEST_ASSERT_EQUAL_HEX8(0x00, FSR[WREG]);
		TEST_ASSERT_EQUAL_HEX8(0x05, FSR[STATUS]);
		TEST_ASSERT_EQUAL_HEX8(0x01, code.absoluteAddress);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}

}

void test_sublw_2_subtract_1_equal_1_carry_should_set_to_1_should_pass(){
	int error;
	Instruction inst = { .mnemonic = SUBLW, .name = "sublw" };
	Bytecode code = {.instruction = &inst, .operand1 = 2, .operand2 = -1, .operand3 = -1};
	
	FSR[WREG] = 1;
	code.absoluteAddress = 0x00;
	
	Try{
		sublw(&code);
		TEST_ASSERT_EQUAL_HEX8(0x01, FSR[WREG]);
		TEST_ASSERT_EQUAL_HEX8(0x01, FSR[STATUS]);
		TEST_ASSERT_EQUAL_HEX8(0x01, code.absoluteAddress);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}

}

void test_sublw_1_subtract_2_equal_FF_negative_flag_should_set_to_1_should_pass(){
	int error;
	Instruction inst = { .mnemonic = SUBLW, .name = "sublw" };
	Bytecode code = {.instruction = &inst, .operand1 = 1, .operand2 = -1, .operand3 = -1};
	
	FSR[WREG] = 2;
	code.absoluteAddress = 0x00;
	
	Try{
		sublw(&code);
		TEST_ASSERT_EQUAL_HEX8(0xFF, FSR[WREG]);
		TEST_ASSERT_EQUAL_HEX8(0x10, FSR[STATUS]);
		TEST_ASSERT_EQUAL_HEX8(0x01, code.absoluteAddress);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
		
}

void test_sublw_1_subtract_3_equal_FE_negative_flag_should_set_to_1_should_pass(){
	int error;
	Instruction inst = { .mnemonic = SUBLW, .name = "sublw" };
	Bytecode code = {.instruction = &inst, .operand1 = 1, .operand2 = -1, .operand3 = -1};
	
	FSR[WREG] = 3;
	code.absoluteAddress = 0x00;
	
	Try{
		sublw(&code);
		TEST_ASSERT_EQUAL_HEX8(0xFE, FSR[WREG]);
		TEST_ASSERT_EQUAL_HEX8(0x10, FSR[STATUS]);
		TEST_ASSERT_EQUAL_HEX8(0x01, code.absoluteAddress);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}

}

void test_sublw_invalid_operand2_should_throw_exception_pass(){
	int error;
	Instruction inst = { .mnemonic = SUBLW, .name = "sublw" };
	Bytecode code = {.instruction = &inst, .operand1 = 1, .operand2 = 2, .operand3 = -1};
	
	FSR[WREG] = 1;
	
	Try{
		sublw(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_sublw_invalid_operand3_should_throw_exception_pass(){
	int error;
	Instruction inst = { .mnemonic = SUBLW, .name = "sublw" };
	Bytecode code = {.instruction = &inst, .operand1 = 1, .operand2 = -1, .operand3 = -5};
	
	FSR[WREG] = 1;
	
	Try{
		sublw(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}





