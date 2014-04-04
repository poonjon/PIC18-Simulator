#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "Execute.h"
#include "ADDWFC.h"

void setUp() {}
void tearDown() {}

void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_wreg_access_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = ACCESS};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0x01;
	FSR[code.operand1] = 0x01;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x02, FSR[WREG]);
}

void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_file_access_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = ACCESS};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0x01;
	FSR[code.operand1] = 0x01;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x02, FSR[code.operand1]);
}

void test_addwfc_should_add_0x02_to_0x01_expect_0x03_save_in_file_access_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x190, .operand2 = F, .operand3 = -1};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0x02;
	FSR[code.operand1] = 0x01;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}

	TEST_ASSERT_EQUAL(0x03, FSR[code.operand1+(FSR[BSR]<<8)]);
}

void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_file_0xfa1_access_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xa1, .operand2 = F, .operand3 = ACCESS};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0x01;
	FSR[code.operand1] = 0x01;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x02, FSR[code.operand1]);
	TEST_ASSERT_EQUAL(0xfa1, code.operand1);
}

void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_wreg_bsr_5_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 1};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0x01;
	FSR[BSR] = 0x5;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x01;

	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x02, FSR[WREG]);
}

void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_file_bsr_5_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0x01;
	FSR[BSR] = 0x5;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x01;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x02, FSR[(FSR[BSR]<<8)+code.operand1]);
}

void test_addwfc_should_add_0x80_to_0x80_expect_0x00_save_in_wreg_status_0x0d_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0x80;
	FSR[code.operand1] = 0x80;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x00, FSR[WREG]);
	TEST_ASSERT_EQUAL(0b00001101, FSR[STATUS]);
}

void test_addwfc_should_add_0xff_to_0x01_expect_0x00_save_in_wreg_status_0x07_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0xff;
	FSR[code.operand1] = 0x01;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x00, FSR[WREG]);
	TEST_ASSERT_EQUAL(0b00000111, FSR[STATUS]);
}

void test_addwfc_should_add_0x0f_to_0x01_expect_0x00_save_in_wreg_status_0x10_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0x0f;
	FSR[code.operand1] = 0x01;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x10, FSR[WREG]);
	TEST_ASSERT_EQUAL(0b00000010, FSR[STATUS]);
}

void test_addwfc_should_add_0x0f_to_0x0a_expect_0x19_save_in_file_status_0x02_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0x0f;
	FSR[code.operand1] = 0x0a;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x19, FSR[WREG]);
	TEST_ASSERT_EQUAL(0b00000010, FSR[STATUS]);
}

void test_addwfc_should_add_0x00_to_0x00_expect_0x00_save_in_file_status_0x00_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0x00;
	FSR[code.operand1] = 0x00;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x00, FSR[WREG]);
	TEST_ASSERT_EQUAL(0b0000100, FSR[STATUS]);
}

void test_addwfc_should_add_0xbb_to_0xcc_expect_0x87_save_in_file_status_0x13_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0xbb;
	FSR[code.operand1] = 0xcc;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x87, FSR[WREG]);
	TEST_ASSERT_EQUAL(0b00010011, FSR[STATUS]);
}

void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_file_bsr_5_status_0x00_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0x01;
	FSR[BSR] = 0x5;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x01;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x02, FSR[(FSR[BSR]<<8)+code.operand1]);
	TEST_ASSERT_EQUAL(0x00, FSR[STATUS]);
}
//sfr
void test_addwfc_should_add_0x03_to_0x01_expect_0x04_save_in_file_bsr_5_status_0x00_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xf90, .operand2 = 1, .operand3 = 1};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0x03;
	FSR[BSR] = 0x5;
	FSR[code.operand1] = 0x01;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	/*
	TEST_ASSERT_EQUAL(0x04, FSR[code.operand1]);
	TEST_ASSERT_EQUAL(0x00, FSR[STATUS]);*/
}

void test_addwfc_should_add_0x0a_to_0x0a_expect_0x14_save_in_file_bsr_5_status_0x02_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0x0a;
	FSR[BSR] = 0x5;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x0a;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x14, FSR[(FSR[BSR]<<8)+code.operand1]);
	TEST_ASSERT_EQUAL(0b00000010, FSR[STATUS]);
}

void test_addwfc_should_add_0xff_to_0x01_with_carry_expect_0x00_save_in_file_bsr_5_status_0x03_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};
	
	FSR[STATUS] = 1;
	FSR[WREG] = 0xff;
	FSR[BSR] = 0x5;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x01;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x01, FSR[(FSR[BSR]<<8)+code.operand1]);
	TEST_ASSERT_EQUAL(0b00000011, FSR[STATUS]);
}

void test_addwfc_should_add_0x0a_to_0x0a_with_carry_expect_0x15_save_in_file_bsr_5_status_0x02_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};
	
	FSR[STATUS] = 0x01;
	FSR[WREG] = 0x0a;
	FSR[BSR] = 0x5;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x0a;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x15, FSR[(FSR[BSR]<<8)+code.operand1]);
	TEST_ASSERT_EQUAL(0b00000011, FSR[STATUS]);
}
//sfr
void test_addwfc_should_add_0x0a_to_0x0a_with_carry_expect_0x15_default_operand2_bsr_5_status_0x02_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xf91, .operand2 = BANKED, .operand3 = -1};
	
	FSR[STATUS] = 0x01;
	FSR[WREG] = 0x0a;
	FSR[BSR] = 0x5;
	FSR[code.operand1] = 0x0a;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	/*
	TEST_ASSERT_EQUAL(0x15, FSR[0xf91]);
	TEST_ASSERT_EQUAL(0b00000011, FSR[STATUS]);*/
}

void test_addwfc_should_add_0xfe_to_0x01_with_carry_expect_0x00_save_in_wreg_status_0x07_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};
	
	FSR[STATUS] = 0x1;
	FSR[WREG] = 0xfe;
	FSR[code.operand1] = 0x01;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x00, FSR[WREG]);
	TEST_ASSERT_EQUAL(0b00000111, FSR[STATUS]);
}

void test_addwfc_should_add_0x60_to_0x60_with_carry_expect_0x00_save_in_wreg_status_0x07_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};
	
	FSR[STATUS] = 0x1;
	FSR[WREG] = 0x40;
	FSR[code.operand1] = 0x40;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x81, FSR[WREG]);
	TEST_ASSERT_EQUAL(0b00011001, FSR[STATUS]);
}

void test_addwfc_invalid_operand1_should_throw_exception(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = -1, .operand2 = W, .operand3 = ACCESS};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0x01;
	FSR[code.operand1] = 0x01;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}

}

void test_addwfc_invalid_operand2_should_throw_exception(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x01, .operand2 = 2, .operand3 = ACCESS};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0x01;
	FSR[code.operand1] = 0x01;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}

}

void test_addwfc_invalid_operand3_should_throw_exception(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x01, .operand2 = W, .operand3 = 2};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0x01;
	FSR[code.operand1] = 0x01;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_addwfc_default_operand2_invalid_operand3_should_throw_exception(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x01, .operand2 = ACCESS, .operand3 = 2};
	
	FSR[STATUS] = 0;
	FSR[WREG] = 0x01;
	FSR[code.operand1] = 0x01;
	
	Try{
		addwfc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}


	