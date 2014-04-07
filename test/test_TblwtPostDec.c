#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "TblwtPostDec.h"

void setUp(void){}
void tearDown(void){}

void test_tblwt_postdec_should_decrement_010101_expect_00_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = TBLWTPOSTDEC, .name = "TblwtPostDec" };
	Bytecode code = {.instruction = &inst, .operand1 = -1, .operand2 = -1, .operand3 = -1, .absoluteAddress = 0};
	
	FSR[TABLAT] = 0x10;
	FSR[TBLPTRH] = 0x1;
	FSR[TBLPTRL] = 0x1;
	FSR[TBLPTRU] = 0x1;

	tblwt_postdec(&code);
	TEST_ASSERT_EQUAL(0x10, TABLE[0x010101]);
	TEST_ASSERT_EQUAL(0x00, FSR[TBLPTRL]);
}

void test_tblwt_postdec_should_decrement_010000_expect_00ffff_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = TBLWTPOSTDEC, .name = "TblwtPostDec" };
	Bytecode code = {.instruction = &inst, .operand1 = -1, .operand2 = -1, .operand3 = -1, .absoluteAddress = 0};
	
	FSR[TABLAT] = 0x10;
	FSR[TBLPTRH] = 0x0;
	FSR[TBLPTRL] = 0x0;
	FSR[TBLPTRU] = 0x1;

	tblwt_postdec(&code);
	TEST_ASSERT_EQUAL(0x10, TABLE[0x010101]);
	TEST_ASSERT_EQUAL(0xff, FSR[TBLPTRL]);
	TEST_ASSERT_EQUAL(0xff, FSR[TBLPTRH]);
	TEST_ASSERT_EQUAL(0x00, FSR[TBLPTRU]);
}

void test_tblwt_postdec_should_throw_exception(void){
	int error;	
	
	Instruction inst = { .mnemonic = TBLWTPOSTDEC, .name = "TblwtPostDec" };
	Bytecode code = {.instruction = &inst, .operand1 = -1, .operand2 = -1, .operand3 = -1, .absoluteAddress = 0};
	
	FSR[TABLAT] = 0x10;
	FSR[TBLPTRU] = 0x20;
	FSR[TBLPTRH] = 0x20;
	FSR[TBLPTRL] = 0x01;
	
	Try{
	tblwt_postdec(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}

}
