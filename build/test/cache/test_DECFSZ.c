#include "unity.h"
#include "Execute.h"
#include "DECFSZ.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_decfsz_should_decrement_value_0x01_expect_0x00_pc_add_4_store_in_wreg_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = ACCESS, .absoluteAddress = 0};



 FSR[code.operand1] = 0x01;



 decfsz(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_store_in_wreg_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = ACCESS, .absoluteAddress = 0};



 FSR[code.operand1] = 0x02;



 decfsz(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x01_expect_0x00_pc_add_4_store_in_file_reg_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = ACCESS, .absoluteAddress = 0};



 FSR[code.operand1] = 0x01;



 decfsz(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_store_in_file_reg_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = ACCESS, .absoluteAddress = 0};



 FSR[code.operand1] = 0x02;



 decfsz(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x00_expect_0xff_pc_add_2_store_in_file_reg_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x244, .operand2 = F, .operand3 = -1, .absoluteAddress = 0};



 FSR[code.operand1] = 0x0;



 decfsz(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0xff)), (_U_SINT)(_US8 )((FSR[code.operand1+(FSR[0xfe0]<<8)])), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_store_in_file_reg_access_address_0xa1_should_change_to_0xfa1_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xa1, .operand2 = F, .operand3 = 0, .absoluteAddress = 0};



 FSR[code.operand1] = 0x02;





 decfsz(&code);

 UnityAssertEqualNumber((_U_SINT)(_US16)((0xfa1)), (_U_SINT)(_US16)((code.operand1)), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_HEX16);

}



void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_default_operand2_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = ACCESS, .operand3 = -1, .absoluteAddress = 0};



 FSR[code.operand1] = 0x02;



 decfsz(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_default_operand2_operand3_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = -1, .operand3 = -1, .absoluteAddress = 0};



 FSR[code.operand1] = 0x02;



 decfsz(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x01_expect_0x00_pc_add_4_store_in_wreg_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 1, .absoluteAddress = 0};



 FSR[0xfe0] = 0x05;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;





 decfsz(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)118, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_store_in_wreg_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = BANKED, .absoluteAddress = 0};



 FSR[0xfe0] = 0x05;

 FSR[0x512] = 0x02;



 decfsz(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)131, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x10_expect_0x0f_pc_add_2_store_in_wreg_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xf92, .operand2 = W, .operand3 = BANKED, .absoluteAddress = 0};



 FSR[0xfe0] = 0x05;

 FSR[code.operand1] = 0x10;



 decfsz(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x0f)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x01_expect_0x00_pc_add_4_store_in_file_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = 1, .absoluteAddress = 0};



 FSR[0xfe0] = 0x05;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;



 decfsz(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1+(FSR[0xfe0]<<8)])), (((void *)0)), (_U_UINT)157, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_store_in_file_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = BANKED, .absoluteAddress = 0};



 FSR[0xfe0] = 0x05;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x02;



 decfsz(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((FSR[code.operand1+(FSR[0xfe0]<<8)])), (((void *)0)), (_U_UINT)170, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_invalid_operand1_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = -1, .operand2 = F, .operand3 = BANKED};



 FSR[0xfe0] = 0x05;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x02;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  decfsz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)185, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_decfsz_invalid_operand2_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 2, .operand3 = BANKED};



 FSR[0xfe0] = 0x05;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x02;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  decfsz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)201, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_decfsz_invalid_operand3_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = 2};



 FSR[0xfe0] = 0x05;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x02;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  decfsz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)217, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_default_operand2_invalid_operand3_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = ACCESS, .operand3 = 2};



 FSR[code.operand1] = 0x02;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  decfsz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)232, UNITY_DISPLAY_STYLE_INT);

 }

}
