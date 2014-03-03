#include "unity.h"
#include "Bytecode.h"
#include "SWAPF.h"

void setUp() {}
void tearDown() {}

void test_swapf_should_swap_upper_nibble_with_lower_nibble_and_save_in_wreg_no_bsr(){
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};
	
	FSR[code.operand1] = 0x12;
	
	swapf(&code);
	
	TEST_ASSERT_EQUAL_HEX8(0x21, FSR[WREG]);
}

void test_swapf_should_swap_upper_nibble_with_lower_nibble_and_save_in_file_reg_no_bsr(){
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 0};
	
	FSR[code.operand1] = 0x12;
	
	swapf(&code);
	
	TEST_ASSERT_EQUAL_HEX8(0x21, code.operand1);

}

void test_swapf_should_swap_upper_nibble_with_lower_nibble_and_save_in_wreg_with_bsr(){
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 1};
	
	FSR[BSR] = 0x5;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x01;
	swapf(&code);
	
	TEST_ASSERT_EQUAL_HEX8(0x10, FSR[WREG]);
	
}

void test_swapf_should_swap_upper_nibble_with_lower_nibble_and_save_file_reg_with_bsr(){
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};
	
	FSR[BSR] = 0x5;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x01;
	
	swapf(&code);
	
	TEST_ASSERT_EQUAL_HEX8(0x10, FSR[code.operand1+(FSR[BSR]<<8)]);
	
}