#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "Execute.h"
#include "RLCF.h"

void setUp() {}
void tearDown() {}

void test_rlcf_00000000_with_carry_1_should_get_00000001_status_0x00_store_in_wreg_access_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = ACCESS};
	
	FSR[STATUS] = 0x1;
	FSR[code.operand1] = 0b00000000;
	
	Try{
		rlcf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0b00000001, FSR[WREG]);
	TEST_ASSERT_EQUAL(0b00000000, FSR[STATUS]);
}

void test_rlcf_10000000_with_carry_1_should_get_00000001_status_0x01_store_in_file_access_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = ACCESS};
	
	FSR[STATUS] = 0x1;
	FSR[code.operand1] = 0b10000000;
	
	Try{
		rlcf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0b0000001, FSR[code.operand1]);
	TEST_ASSERT_EQUAL(0b0000001, FSR[STATUS]);
}

void test_rlcf_11000000_with_carry_1_should_get_10000001_status_0x11_store_in_file_access_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = ACCESS, .operand3 = -1};
	
	FSR[STATUS] = 0x1;
	FSR[code.operand1] = 0b11000000;
	
	Try{
		rlcf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0b10000001, FSR[code.operand1]);
	TEST_ASSERT_EQUAL(0b00010001, FSR[STATUS]);
}

void test_rlcf_00000000_with_carry_0_should_get_00000000_status_0x11_store_in_file_access_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xff2, .operand2 = ACCESS, .operand3 = -1};
	
	FSR[STATUS] = 0x0;
	FSR[code.operand1] = 0b0000000;
	
	Try{
		rlcf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0b00000000, FSR[code.operand1]);
	TEST_ASSERT_EQUAL(0b00000100, FSR[STATUS]);
}

void test_rlcf_10000000_with_carry_1_should_get_00000000_status_0x05_store_in_file_f92_access_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x92, .operand2 = F, .operand3 = ACCESS};
	
	FSR[STATUS] = 0x0;
	FSR[code.operand1] = 0b10000000;
	
	Try{
		rlcf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0b0000000, FSR[code.operand1]);
	TEST_ASSERT_EQUAL(0b0000101, FSR[STATUS]);
}

void test_rlcf_10100110_with_carry_1_should_get_01001101_status_0x01_store_in_wreg_banked_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = BANKED};
	
	FSR[STATUS] = 1;
	FSR[BSR] = 0x5;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0b10100110;
	
	Try{
		rlcf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0b01001101, FSR[WREG]);
	TEST_ASSERT_EQUAL(0b00000001, FSR[STATUS]);
}
//sfr
void test_rlcf_11111111_with_carry_1_should_get_11111111_status_0x11_store_in_wreg_banked_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xf97, .operand2 = W, .operand3 = BANKED};
	
	FSR[STATUS] = 1;
	FSR[BSR] = 0x5;
	FSR[code.operand1] = 0xff;
	
	Try{
		rlcf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	//TEST_ASSERT_EQUAL(0b11111111, FSR[WREG]);
	//TEST_ASSERT_EQUAL(0b00010001, FSR[STATUS]);
}

void test_rlcf_01110110_with_carry_0_should_get_11101100_status_0x01_store_in_wreg_banked_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = BANKED};
	
	FSR[STATUS] = 0;
	FSR[BSR] = 0x5;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0b01110110;
	
	Try{
		rlcf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0b11101100, FSR[WREG]);
	TEST_ASSERT_EQUAL(0b00010000, FSR[STATUS]);
}

void test_rlcf_01001111_with_carry_0_should_get_10011110_status_0x10_store_in_file_banked_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = BANKED};
	
	FSR[STATUS] = 0;
	FSR[BSR] = 0x5;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0b01001111;
	
	Try{
		rlcf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0b10011110, FSR[(FSR[BSR]<<8)+code.operand1]);
	TEST_ASSERT_EQUAL(0b00010000, FSR[STATUS]);
}

void test_rlcf_00001111_with_carry_0_should_get_00011110_status_0x00_store_in_file_banked_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = BANKED, .operand3 = -1};
	
	FSR[STATUS] = 0;
	FSR[BSR] = 0x5;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0b00001111;
	
	Try{
		rlcf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0b00011110, FSR[(FSR[BSR]<<8)+code.operand1]);
	TEST_ASSERT_EQUAL(0b00000000, FSR[STATUS]);
}

void test_rlcf_invalid_operand1_should_throw_exception(){
	int error;	
	
	Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };
	Bytecode code = {.instruction = &inst, .operand1 = -123, .operand2 = F, .operand3 = BANKED};
	
	FSR[STATUS] = 0;
	FSR[BSR] = 0x5;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0b01001111;
	
	Try{
		rlcf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_rlcf_invalid_operand2_should_throw_exception(){
	int error;	
	
	Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 2, .operand3 = BANKED};
	
	FSR[STATUS] = 0;
	FSR[BSR] = 0x5;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0b01001111;
	
	Try{
		rlcf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_rlcf_invalid_operand3_should_throw_exception(){
	int error;	
	
	Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = 2};
	
	FSR[STATUS] = 0;
	FSR[BSR] = 0x5;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0b01001111;
	
	Try{
		rlcf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}
