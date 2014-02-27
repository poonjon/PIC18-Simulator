#include "unity.h"
#include "LiteralOperations.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_sublw_1_minus_1_equal_0(){

 Instruction inst = { .mnemonic = SUBLW, .name = "sublw" };

 Bytecode code = {.instruction = &inst, .operand1 = 1, .operand2 = -1, .operand3 = -1};



 FSR[0xfe8] = 1;



 sublw(&code);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)17, UNITY_DISPLAY_STYLE_HEX8);

 if (((-) != (FSR[0xfe8]))) {} else {UnityFail( (" Expected Not-Equal"), (_U_UINT)(_U_UINT)18);;};

}
