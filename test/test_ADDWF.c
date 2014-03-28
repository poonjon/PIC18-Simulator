#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "ADDWF.h"

void setUp() {}
void tearDown() {}

void test_addwf_should_add_0x01_to_0x01_expect_0x02_save_in_wreg_access_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = ACCESS};
	
	FSR[WREG] = 0x01;
	FSR[code.operand1] = 0x01;
	code.absoluteAddress = 0x00;
	PC = code.absoluteAddress;
	
	Try{
		addwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x02, FSR[WREG]);
	TEST_ASSERT_EQUAL(0x02, PC);
}

void test_addwf_should_add_0x01_to_0x01_expect_0x02_save_in_file_access_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = ACCESS};
	
	FSR[WREG] = 0x01;
	FSR[code.operand1] = 0x01;
	code.absoluteAddress = 0x00;
	PC = code.absoluteAddress;
	
	Try{
		addwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x02, FSR[code.operand1]);
	TEST_ASSERT_EQUAL(0x02, PC);
}

void test_addwf_should_add_0x01_to_0x01_expect_0x02_save_in_wreg_bsr_5_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 1};
	
	FSR[WREG] = 0x01;
	FSR[BSR] = 0x5;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x01;
	code.absoluteAddress = 0x00;
	PC = code.absoluteAddress;
	
	Try{
		addwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x02, FSR[WREG]);
	TEST_ASSERT_EQUAL(0x02, PC);
}

void test_addwf_should_add_0x01_to_0x01_expect_0x02_save_in_file_bsr_5_should_pass(){
	int error;	
	
	Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};
	
	FSR[WREG] = 0x01;
	FSR[BSR] = 0x5;
	FSR[(FSR[BSR]<<8)+code.operand1] = 0x01;
	code.absoluteAddress = 0x00;
	PC = code.absoluteAddress;
	
	Try{
		addwf(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
	
	TEST_ASSERT_EQUAL(0x02, FSR[(FSR[BSR]<<8)+code.operand1]);
	TEST_ASSERT_EQUAL(0x02, PC);
}