#include "unity.h"
#include "Bytecode.h"
#include "ByteOrientedOperations.h"

char FSR[0x1000];

void test_movff_mov_file_location_1_to_2(){
	Instruction inst = { .mnemonic = MOVFF, .name = "movff" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x011, .operand2 = 0x010, .operand3 = -1};
	
	FSR[code.operand1] = 0;
	FSR[code.operand2] = 1;
	
	movff(&code);
	
	TEST_ASSERT_EQUAL(1, FSR[0x011]);
	TEST_ASSERT_EQUAL(1, FSR[0x010]);
}