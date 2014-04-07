#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "ExecuteBit.h"
#include "BTFSC.h"

void setUp(void){}
void tearDown(void){}

void test_btfsc_clear_bit_0_pc_add_4_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = ACCESS, .absoluteAddress = 0};
	
	FSR[code.operand1] = 0b00000000;


	btfsc(&code);
	TEST_ASSERT_EQUAL(2, code.absoluteAddress);
}

void test_btfsc_not_clear_bit_0_pc_add_2_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = ACCESS, .absoluteAddress = 0};
	
	FSR[code.operand1] = 0b00000001;

	btfsc(&code);
	TEST_ASSERT_EQUAL(1, code.absoluteAddress);
}

void test_btfsc_clear_bit_1_pc_add_4_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x92, .operand2 = 1, .operand3 = ACCESS, .absoluteAddress = 0};
	
	FSR[code.operand1] = 0b00000001;


	btfsc(&code);
	TEST_ASSERT_EQUAL(2, code.absoluteAddress);

}

void test_btfsc_not_clear_bit_1_pc_add_2_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x92, .operand2 = 1, .operand3 = ACCESS, .absoluteAddress = 0};
	
	FSR[code.operand1] = 0b00000010;
	
	btfsc(&code);
	TEST_ASSERT_EQUAL(1, code.absoluteAddress);
}

void test_btfsc_clear_bit_2_pc_add_4_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xff2, .operand2 = 2, .operand3 = ACCESS, .absoluteAddress = 0};
	
	FSR[code.operand1] = 0b11100001;

	btfsc(&code);
	TEST_ASSERT_EQUAL(2, code.absoluteAddress);
	
}

void test_btfsc_not_clear_bit_2_pc_add_2_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 2, .operand3 = ACCESS, .absoluteAddress = 0};
	
	FSR[code.operand1] = 0b00000100;

	btfsc(&code);
	TEST_ASSERT_EQUAL(1, code.absoluteAddress);
}

void test_btfsc_clear_bit_3_pc_add_4_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 3, .operand3 = ACCESS, .absoluteAddress = 0};
	
	FSR[code.operand1] = 0b11100011;

	btfsc(&code);
	TEST_ASSERT_EQUAL(2, code.absoluteAddress);

}

void test_btfsc_not_clear_bit_3_pc_add_2_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 3, .operand3 = ACCESS, .absoluteAddress = 0};
	
	FSR[code.operand1] = 0b00001000;

	btfsc(&code);
	TEST_ASSERT_EQUAL(1, code.absoluteAddress);
}

void test_btfsc_clear_bit_4_pc_add_4_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0xf92, .operand2 = 4, .operand3 = BANKED, .absoluteAddress = 0};
	
	FSR[BSR] = 0x2;
	FSR[code.operand1] = 0b11000111;

	btfsc(&code);
	TEST_ASSERT_EQUAL(2, code.absoluteAddress);
}

void test_btfsc_not_clear_bit_4_pc_add_2_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 4, .operand3 = BANKED, .absoluteAddress = 0};
	
	FSR[BSR] = 0x2;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0b00010000;

	btfsc(&code);
	TEST_ASSERT_EQUAL(1, code.absoluteAddress);
}

void test_btfsc_clear_bit_5_pc_add_4_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 5, .operand3 = BANKED, .absoluteAddress = 0};
	
	FSR[BSR] = 0x2;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0b11001111;

	btfsc(&code);
	TEST_ASSERT_EQUAL(2, code.absoluteAddress);
	
}

void test_btfsc_not_clear_bit_5_pc_add_2_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 5, .operand3 = BANKED, .absoluteAddress = 0};
	
	FSR[BSR] = 0x2;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0b00101100;

	btfsc(&code);
	TEST_ASSERT_EQUAL(1, code.absoluteAddress);
}

void test_btfsc_clear_bit_6_pc_add_4_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 6, .operand3 = BANKED, .absoluteAddress = 0};
	
	FSR[BSR] = 0x2;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0b10011111;
	
	btfsc(&code);
	TEST_ASSERT_EQUAL(2, code.absoluteAddress);

}

void test_btfsc_not_clear_bit_6_pc_add_2_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 6, .operand3 = BANKED, .absoluteAddress = 0};
	
	FSR[BSR] = 0x2;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0b01001100;
	
	btfsc(&code);
	TEST_ASSERT_EQUAL(1, code.absoluteAddress);
}

void test_btfsc_clear_bit_7_pc_add_4_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 7, .operand3 = BANKED, .absoluteAddress = 0};
	
	FSR[BSR] = 0x2;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0b00011111;
	
	btfsc(&code);
	TEST_ASSERT_EQUAL(2, code.absoluteAddress);

}

void test_btfsc_not_clear_bit_7_pc_add_2_should_pass(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 7, .operand3 = BANKED, .absoluteAddress = 0};
	
	FSR[BSR] = 0x2;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0b10001100;

	btfsc(&code);
	TEST_ASSERT_EQUAL(1, code.absoluteAddress);
}

void test_invalid_operand1(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x412, .operand2 = 7, .operand3 = BANKED};
	
	FSR[BSR] = 0x2;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0b10001100;
	
	Try{
		btfsc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_invalid_operand2(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 8, .operand3 = BANKED};
	
	FSR[BSR] = 0x2;
	FSR[code.operand1+(FSR[BSR]<<8)] = 0b10001100;
	
	Try{
		btfsc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

void test_invalid_operand3(void){
	int error;	
	
	Instruction inst = { .mnemonic = BTFSC, .name = "btfsc" };
	Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 7, .operand3 = 2};
	
	FSR[code.operand1+(FSR[BSR]<<8)] = 0b10001100;
	
	Try{
		btfsc(&code);
	}Catch(error){
		TEST_ASSERT_EQUAL(1, ERR_INVALID_OPERAND);
	}
}

