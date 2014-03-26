#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "MOVFF.h"

void setUp() {}
void tearDown() {}

void test_movff_mov_file_location_0x011_to_0x010_should_pass(){
	int error;
	Instruction inst = { .mnemonic = MOVFF, .name = "movff" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x011, .operand2 = 0x010, .operand3 = -1};
	
	FSR[code.operand1] = 1; //source
	FSR[code.operand2] = 0; //destination
	
	Try{
		movff(&code);
		TEST_ASSERT_EQUAL(1, FSR[0x011]); //check source value
		TEST_ASSERT_EQUAL(1, FSR[0x010]); //test if source moved to destination
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_movff_mov_file_location_0x011_to_0xFFF_should_throw_exception(){
	int error;
	Instruction inst = { .mnemonic = MOVFF, .name = "movff" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x011, .operand2 = 0xFFF, .operand3 = -1};
	
	FSR[code.operand1] = 1; //source
	FSR[code.operand2] = 0; //destination
	
	Try{
		movff(&code);
		TEST_ASSERT_EQUAL(1, FSR[0x011]); //check source value
		TEST_ASSERT_EQUAL(1, FSR[0x010]); //test if source moved to destination
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}
