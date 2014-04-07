#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "Execute.h"
#include "SWAPF.h"

void setUp(){}
void tearDown(){}

void test_swapf_should_swap_0x12_into_0x21_save_in_wreg_access_bank_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = ACCESS, .absoluteAddress = 0};

	FSR[0x12] = 0x12;
	
	swapf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x21, FSR[WREG]);
}

void test_swapf_should_swap_0x12_into_0x21_save_in_file_reg_acess_bank_should_pass(){
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = ACCESS, .absoluteAddress = 0};
	
	FSR[0x12] = 0x12;	 
	
	swapf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x21, FSR[0x12]);
}

void test_swapf_should_swap_0x13_into_0x21_save_in_file_reg_acess_bank_should_pass(){
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xff0, .operand2 = 1, .operand3 = ACCESS, .absoluteAddress = 0};
	
	FSR[0xff0] = 0x13;
		
	swapf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x31, FSR[0xff0]);
}

void test_swapf_should_swap_0x12_into_0x21_default_operand2_operand3_should_pass(){
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = -1, .operand3 = -1, .absoluteAddress = 0};
	
	FSR[0x12] = 0x12;
	
	swapf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x21, FSR[0x12]);
}

void test_swapf_should_swap_0x12_into_0x21_default_operand3_file_reg_should_pass(){
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = -1, .absoluteAddress = 0};
	
	FSR[0x12] = 0x12;
	
	swapf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x21, FSR[0x12]);
}

void test_swapf_should_swap_0x12_into_0x21_default_operand2_acess_bank_should_pass(){
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x90, .operand2 = ACCESS, .operand3 = -1, .absoluteAddress = 0};
	
	FSR[0x90] = 0x12;
	
	swapf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x21, FSR[0xf90]);
}

void test_swapf_should_swap_0x51_into_0x15_default_operand2_acess_bank_should_pass(){
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xff3, .operand2 = ACCESS, .operand3 = -1, .absoluteAddress = 0};
	
	FSR[0xff3] = 0x51;
	
	swapf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x15, FSR[0xff3]);
}

void test_swapf_should_swap_0x01_into_0x10_save_in_wreg_with_bsr_5_should_pass(){
	
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = BANKED, .absoluteAddress = 0};
	
	FSR[BSR] = 0x5;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x01;
	
	swapf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x10, FSR[WREG]);
}

void test_swapf_should_swap_0x11_into_0x11_save_in_wreg_with_bsr_5_should_pass(){
	
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xfa3, .operand2 = 0, .operand3 = BANKED, .absoluteAddress = 0};
	
	FSR[BSR] = 0x5;
	FSR[0xfa3] = 0x11;

	swapf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x11, FSR[WREG]);
}

void test_swapf_should_swap_0x01_into_0x10_save_in_file_reg_with_bsr_5_should_pass(){
	
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = BANKED, .absoluteAddress = 0};
	
	FSR[BSR] = 0x5;
	FSR[0x512] = 0x01;
	
	swapf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x10, FSR[0x512]);
}

void test_swapf_should_swap_0x04_into_0x40_save_in_file_reg_with_bsr_5_should_pass(){
	
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xfa1, .operand2 = F, .operand3 = BANKED, .absoluteAddress = 0};
	
	FSR[BSR] = 0x5;
	FSR[0xfa1] = 0x04;
	
	swapf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x40, FSR[0x5a1]);	
}

void test_swapf_should_swap_0x01_into_0x10_default_operand2_with_bsr_5_should_pass(){
	
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = BANKED, .absoluteAddress = 0};
	
	FSR[BSR] = 0x5;
	FSR[0x512] = 0x01;
	
	swapf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x10, FSR[0x512]);
}

void test_swapf_should_swap_0x01_into_0x10_save_in_file_reg_with_bsr_15_should_throw_exception(){
	
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = BANKED};
	
	FSR[BSR] = 0x15;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x01;
	
	Try{
		swapf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_swapf_should_swap_0x01_into_0x10_invalid_operand1_should_throw_exception(){
	
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = -1, .operand2 = 2, .operand3 = BANKED};
	
	FSR[BSR] = 0x15;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x01;

	Try{
		swapf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_swapf_should_swap_0x01_into_0x10_invalid_operand2_should_throw_exception(){
	
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 2, .operand3 = BANKED};
	
	FSR[BSR] = 0x15;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x01;
	
	Try{
		swapf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_swapf_should_swap_0x01_into_0x10_invalid_operand3_should_throw_exception(){
	
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = 2};
	
	FSR[BSR] = 0x15;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x01;
	
	Try{
		swapf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_swapf_should_swap_0x01_into_0x10_default_operand2_invalid_operand3_should_throw_exception(){
	
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = ACCESS, .operand3 = 2};
	
	FSR[BSR] = 0x15;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x01;
	
	Try{
		swapf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_swapf_should_swap_0x01_into_0x10_default_operand3_invalid_operand2_should_throw_exception(){
	
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 4, .operand3 = -1};
	
	FSR[BSR] = 0x15;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x01;
	
	Try{
		swapf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_swapf_should_swap_0x12_into_0x21_should_change_operand1_0xa1_into_0xfa1_save_in_wreg_access_bank_should_pass(){
	
	int error;	
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xa1, .operand2 = W, .operand3 = ACCESS, .absoluteAddress = 0};
	
	FSR[0xa1] = 0x12;
	
	swapf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x21, FSR[WREG]);
}

void test_swapf_should_swap_0x12_into_0x21_should_change_operand1_0xa2_into_0xfa2_save_in_wreg_access_bank_should_pass(){
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xa2, .operand2 = ACCESS, .operand3 = -1, .absoluteAddress = 0};
	
	FSR[0xa2] = 0x12;
	
	swapf(&code);
	TEST_ASSERT_EQUAL_HEX8(0x21, FSR[0xfa2]);
}
