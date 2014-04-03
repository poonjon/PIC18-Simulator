#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "Execute.h"
#include "DECFSZ.h"

void setUp() {}
void tearDown() {}

void test_decfsz_should_decrement_value_0x01_expect_0x00_pc_add_4_store_in_wreg_access_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = ACCESS};

	FSR[code.operand1] = 0x01;
	
	Try{
		decfsz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	TEST_ASSERT_EQUAL_HEX8(0x00, FSR[WREG]);
}

void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_store_in_wreg_access_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = ACCESS};

	FSR[code.operand1] = 0x02;
	
	Try{
		decfsz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	TEST_ASSERT_EQUAL_HEX8(0x01, FSR[WREG]);
}

void test_decfsz_should_decrement_value_0x01_expect_0x00_pc_add_4_store_in_file_reg_access_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = ACCESS};

	FSR[code.operand1] = 0x01;
		
	Try{
		decfsz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	TEST_ASSERT_EQUAL_HEX8(0x00, FSR[code.operand1]);
}

void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_store_in_file_reg_access_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = ACCESS};

	FSR[code.operand1] = 0x02;
	 	
	Try{
		decfsz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	TEST_ASSERT_EQUAL_HEX8(0x01, FSR[code.operand1]);
}

void test_decfsz_should_decrement_value_0x00_expect_0xff_pc_add_2_store_in_file_reg_access_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xf89, .operand2 = F, .operand3 = ACCESS};

	FSR[code.operand1] = 0x0;
	
	Try{
		decfsz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	TEST_ASSERT_EQUAL_HEX8(0xff, FSR[code.operand1]);
}

void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_store_in_file_reg_access_address_0xa1_should_change_to_0xfa1_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xa1, .operand2 = F, .operand3 = 0};

	FSR[code.operand1] = 0x02; 
	
	Try{
		decfsz(&code);
	}Catch(error){
	
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	TEST_ASSERT_EQUAL_HEX16(0xfa1, code.operand1);
	TEST_ASSERT_EQUAL_HEX8(0x01, FSR[code.operand1]);
}

void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_default_operand2_access_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = ACCESS, .operand3 = -1};

	FSR[code.operand1] = 0x02;	 	 
	
	Try{
		decfsz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	TEST_ASSERT_EQUAL_HEX8(0x01, FSR[code.operand1]);
}

void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_default_operand2_operand3_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = -1, .operand3 = -1};

	FSR[code.operand1] = 0x02; 
	
	Try{
		decfsz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	TEST_ASSERT_EQUAL_HEX8(0x01, FSR[code.operand1]);
}

void test_decfsz_should_decrement_value_0x01_expect_0x00_pc_add_4_store_in_wreg_bsr_5_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 1};

	FSR[BSR] = 0x05;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x01; 
	
	Try{
		decfsz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	TEST_ASSERT_EQUAL_HEX8(0x00, FSR[WREG]);
}

void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_store_in_wreg_bsr_5_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = BANKED};

	FSR[BSR] = 0x05;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x02; 	 
	
	Try{
		decfsz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	TEST_ASSERT_EQUAL_HEX8(0x01, FSR[WREG]);
}

void test_decfsz_should_decrement_value_0x10_expect_0x0f_pc_add_2_store_in_wreg_bsr_5_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xf92, .operand2 = W, .operand3 = BANKED};

	FSR[BSR] = 0x05;
	FSR[code.operand1] = 0x10;  
	
	Try{
		decfsz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	TEST_ASSERT_EQUAL_HEX8(0x0f, FSR[WREG]);
}

void test_decfsz_should_decrement_value_0x01_expect_0x00_pc_add_4_store_in_file_bsr_5_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = 1};

	FSR[BSR] = 0x05;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x01; 
	
	Try{
		decfsz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	TEST_ASSERT_EQUAL_HEX8(0x00, FSR[code.operand1+(FSR[BSR]<<8)]);
}

void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_store_in_file_bsr_5_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = BANKED};

	FSR[BSR] = 0x05;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x02; 	 
	
	Try{
		decfsz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	TEST_ASSERT_EQUAL_HEX8(0x01, FSR[code.operand1+(FSR[BSR]<<8)]);
}

void test_decfsz_invalid_operand1_should_throw_exception(){
	int error;	
	
	Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };
	Bytecode code = {.instruction = &inst, .operand1 = -1, .operand2 = F, .operand3 = BANKED};

	FSR[BSR] = 0x05;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x02;	 

	Try{
		decfsz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_decfsz_invalid_operand2_should_throw_exception(){
	int error;	
	
	Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 2, .operand3 = BANKED};

	FSR[BSR] = 0x05;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x02; 
	
	Try{
		decfsz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_decfsz_invalid_operand3_should_throw_exception(){
	int error;	
	
	Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = 2};

	FSR[BSR] = 0x05;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0x02;	 
	
	Try{
		decfsz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_default_operand2_invalid_operand3_should_throw_exception(){
	int error;	
	
	Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = ACCESS, .operand3 = 2};

	FSR[code.operand1] = 0x02;	 	 
	
	Try{
		decfsz(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

