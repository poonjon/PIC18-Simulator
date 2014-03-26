#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "SWAPF.h"

void setUp() {}
void tearDown() {}

void test_swapf_should_swap_0x12_into_0x21_save_in_wreg_access_bank_should_pass(){
	int error;	
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = ACCESS};

	FSR[code.operand1] = 0x12;
	code.absoluteAddress = 0x00;
	Try{
		swapf(&code);
		TEST_ASSERT_EQUAL_HEX8(0x21, FSR[WREG]);
		TEST_ASSERT_EQUAL_HEX8(0x01, code.absoluteAddress);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}

}

void test_swapf_should_swap_0x12_into_0x21_save_in_file_reg_acess_bank_should_pass(){
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = ACCESS};
	
	FSR[code.operand1] = 0x12;
	code.absoluteAddress = 0xFF;
	
	Try{
		swapf(&code);
		TEST_ASSERT_EQUAL_HEX8(0x21, FSR[code.operand1]);
		TEST_ASSERT_EQUAL_HEX16(0x100, code.absoluteAddress);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}

}

void test_swapf_should_swap_0x12_into_0x21_default_operand2_acess_bank_should_pass(){
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = ACCESS, .operand3 = -1};
	
	FSR[code.operand1] = 0x12;
	code.absoluteAddress = 0x00;
	
	Try{
		swapf(&code);
		TEST_ASSERT_EQUAL_HEX8(0x21, FSR[code.operand1]);
		TEST_ASSERT_EQUAL_HEX8(0x01, code.absoluteAddress);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}

}

void test_swapf_should_swap_0x01_into_0x10_save_in_wreg_with_bsr_5_should_pass(){
	
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = BANKED};
	
	FSR[BSR] = 0x5;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x01;
	code.absoluteAddress = 0x00;
	
	Try{
		swapf(&code);
		TEST_ASSERT_EQUAL_HEX8(0x10, FSR[WREG]);
		TEST_ASSERT_EQUAL_HEX8(0x01, code.absoluteAddress);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
}

void test_swapf_should_swap_0x01_into_0x10_save_in_file_reg_with_bsr_5_should_pass(){
	
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = BANKED};
	
	FSR[BSR] = 0x5;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x01;
	code.absoluteAddress = 0x00;
	
	Try{
		swapf(&code);
		TEST_ASSERT_EQUAL_HEX8(0x10, FSR[code.operand1+(FSR[BSR]<<8)]);
		TEST_ASSERT_EQUAL_HEX8(0x01, code.absoluteAddress);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
}

void test_swapf_should_swap_0x01_into_0x10_default_operand2_with_bsr_5_should_pass(){
	
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = BANKED};
	
	FSR[BSR] = 0x5;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x01;
	code.absoluteAddress = 0x00;
	
	Try{
		swapf(&code);
		TEST_ASSERT_EQUAL_HEX8(0x10, FSR[code.operand1+(FSR[BSR]<<8)]);
		TEST_ASSERT_EQUAL_HEX8(0x01, code.absoluteAddress);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
}

void test_swapf_should_swap_0x01_into_0x10_save_in_file_reg_with_bsr_15_should_throw_exception(){
	
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = BANKED};
	
	FSR[BSR] = 0x15;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x01;
	code.absoluteAddress = 0x00;
	
	Try{
		swapf(&code);
		TEST_ASSERT_EQUAL_HEX8(0x10, FSR[code.operand1+(FSR[BSR]<<8)]);
		TEST_ASSERT_EQUAL_HEX8(0x01, code.absoluteAddress);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
}

void test_swapf_should_swap_0x01_into_0x10_invalid_operand1_should_throw_exception(){
	
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x112, .operand2 = 2, .operand3 = BANKED};
	
	FSR[BSR] = 0x15;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x01;
	code.absoluteAddress = 0x00;
	
	Try{
		swapf(&code);
		TEST_ASSERT_EQUAL_HEX8(0x10, FSR[code.operand1+(FSR[BSR]<<8)]);
		TEST_ASSERT_EQUAL_HEX8(0x01, code.absoluteAddress);
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
	code.absoluteAddress = 0x00;
	
	Try{
		swapf(&code);
		TEST_ASSERT_EQUAL_HEX8(0x10, FSR[code.operand1+(FSR[BSR]<<8)]);
		TEST_ASSERT_EQUAL_HEX8(0x01, code.absoluteAddress);
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
	code.absoluteAddress = 0x00;
	
	Try{
		swapf(&code);
		TEST_ASSERT_EQUAL_HEX8(0x10, FSR[code.operand1+(FSR[BSR]<<8)]);
		TEST_ASSERT_EQUAL_HEX8(0x01, code.absoluteAddress);
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
	code.absoluteAddress = 0x00;
	
	Try{
		swapf(&code);
		TEST_ASSERT_EQUAL_HEX8(0x10, FSR[code.operand1+(FSR[BSR]<<8)]);
		TEST_ASSERT_EQUAL_HEX8(0x01, code.absoluteAddress);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
}

void test_swapf_should_swap_0x01_into_0x10_default_operand3_invalid_operand2_should_throw_exception(){
	
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = -1};
	
	FSR[BSR] = 0x15;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x01;
	code.absoluteAddress = 0x00;
	
	Try{
		swapf(&code);
		TEST_ASSERT_EQUAL_HEX8(0x10, FSR[code.operand1+(FSR[BSR]<<8)]);
		TEST_ASSERT_EQUAL_HEX8(0x01, code.absoluteAddress);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
}

void test_swapf_should_swap_0x12_into_0x21_should_change_operand1_0xa1_into_0xfa1_save_in_wreg_access_bank_should_pass(){
	
	int error;	
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xa1, .operand2 = W, .operand3 = ACCESS};
	
	FSR[code.operand1] = 0x12;
	code.absoluteAddress = 0x00;
	
	Try{
		swapf(&code);
		TEST_ASSERT_EQUAL_HEX8(0x21, FSR[WREG]);
		TEST_ASSERT_EQUAL_HEX16(0xfa1, code.operand1);
		TEST_ASSERT_EQUAL_HEX8(0x01, code.absoluteAddress);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}

}

void test_swapf_should_swap_0x12_into_0x21_should_change_operand1_0xa2_into_0xfa2_save_in_wreg_access_bank_should_pass(){
	int error;
	Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xa2, .operand2 = ACCESS, .operand3 = -1};
	
	FSR[code.operand1] = 0x12;
	code.absoluteAddress = 0x00;
	
	Try{
		swapf(&code);
		TEST_ASSERT_EQUAL_HEX8(0x21, FSR[code.operand1]);
		TEST_ASSERT_EQUAL_HEX16(0xfa2, code.operand1);
		TEST_ASSERT_EQUAL_HEX8(0x01, code.absoluteAddress);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}
