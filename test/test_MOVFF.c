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
	PC = 0x00;
	
	Try{
		movff(&code);
		TEST_ASSERT_EQUAL(1, FSR[0x010]); //test if source moved to destination
		TEST_ASSERT_EQUAL_HEX8(0x01, PC);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_movff_mov_file_location_0x011_to_0x0110_should_pass(){
	int error;
	Instruction inst = { .mnemonic = MOVFF, .name = "movff" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x011, .operand2 = 0x110, .operand3 = -1};
	
	FSR[code.operand1] = 2; //source
	FSR[code.operand2] = 0; //destination
	PC = 0x00;
	
	Try{
		movff(&code);
		TEST_ASSERT_EQUAL(2, FSR[0x110]); //test if source moved to destination
		TEST_ASSERT_EQUAL_HEX8(0x01, PC);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_movff_mov_file_location_0x110_to_0x011_should_pass(){
	int error;
	Instruction inst = { .mnemonic = MOVFF, .name = "movff" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x011, .operand2 = 0x110, .operand3 = -1};
	
	FSR[code.operand1] = 3; //source
	FSR[code.operand2] = 0; //destination
	PC = 0x00;
	
	Try{
		movff(&code);
		TEST_ASSERT_EQUAL(3, FSR[0x11]); //test if source moved to destination
		TEST_ASSERT_EQUAL_HEX8(0x01, PC);
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
	PC = 0x00;
	
	Try{
		movff(&code);
		TEST_ASSERT_EQUAL(1, FSR[0x010]); //test if source moved to destination
		TEST_ASSERT_EQUAL_HEX8(0x01, PC);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_movff_invalid_operand1_should_throw_exception(){
	int error;
	Instruction inst = { .mnemonic = MOVFF, .name = "movff" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x1000, .operand2 = 0xFFF, .operand3 = -1};
	
	FSR[code.operand1] = 1; //source
	FSR[code.operand2] = 0; //destination
	PC = 0x00;
	
	Try{
		movff(&code);
		TEST_ASSERT_EQUAL(1, FSR[0x010]); //test if source moved to destination
		TEST_ASSERT_EQUAL_HEX8(0x01, PC);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_movff_invalid_operand2_should_throw_exception(){
	int error;
	Instruction inst = { .mnemonic = MOVFF, .name = "movff" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x100, .operand2 = 0x1010, .operand3 = -1};
	
	FSR[code.operand1] = 1; //source
	FSR[code.operand2] = 0; //destination
	PC = 0x00;
	
	Try{
		movff(&code);
		TEST_ASSERT_EQUAL(1, FSR[0x010]); //test if source moved to destination
		TEST_ASSERT_EQUAL_HEX8(0x01, PC);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_movff_invalid_operand3_should_throw_exception(){
	int error;
	Instruction inst = { .mnemonic = MOVFF, .name = "movff" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x100, .operand2 = 0x11, .operand3 = 1};
	
	FSR[code.operand1] = 1; //source
	FSR[code.operand2] = 0; //destination
	PC = 0x00;
	
	Try{
		movff(&code);
		TEST_ASSERT_EQUAL(1, FSR[0x010]); //test if source moved to destination
		TEST_ASSERT_EQUAL_HEX8(0x01, PC);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}
