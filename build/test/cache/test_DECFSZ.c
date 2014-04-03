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

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = ACCESS};



 FSR[code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  decfsz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)23, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_store_in_wreg_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = ACCESS};



 FSR[code.operand1] = 0x02;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  decfsz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)39, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x01_expect_0x00_pc_add_4_store_in_file_reg_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = ACCESS};



 FSR[code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  decfsz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_store_in_file_reg_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = ACCESS};



 FSR[code.operand1] = 0x02;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  decfsz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)71, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x00_expect_0xff_pc_add_2_store_in_file_reg_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xf89, .operand2 = F, .operand3 = ACCESS};



 FSR[code.operand1] = 0x0;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  decfsz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0xff)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_store_in_file_reg_access_address_0xa1_should_change_to_0xfa1_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xa1, .operand2 = F, .operand3 = 0};



 FSR[code.operand1] = 0x02;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  decfsz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)102, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US16)((0xfa1)), (_U_SINT)(_US16)((code.operand1)), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_default_operand2_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = ACCESS, .operand3 = -1};



 FSR[code.operand1] = 0x02;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  decfsz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)119, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)121, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_default_operand2_operand3_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = -1, .operand3 = -1};



 FSR[code.operand1] = 0x02;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  decfsz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)135, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)137, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x01_expect_0x00_pc_add_4_store_in_wreg_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 1};



 FSR[0xfe0] = 0x05;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  decfsz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)152, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)154, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_store_in_wreg_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = BANKED};



 FSR[0xfe0] = 0x05;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x02;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  decfsz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)169, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)171, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x10_expect_0x0f_pc_add_2_store_in_wreg_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xf92, .operand2 = W, .operand3 = BANKED};



 FSR[0xfe0] = 0x05;

 FSR[code.operand1] = 0x10;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  decfsz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)186, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x0f)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)188, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x01_expect_0x00_pc_add_4_store_in_file_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = 1};



 FSR[0xfe0] = 0x05;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  decfsz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)203, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((FSR[code.operand1+(FSR[0xfe0]<<8)])), (((void *)0)), (_U_UINT)205, UNITY_DISPLAY_STYLE_HEX8);

}



void test_decfsz_should_decrement_value_0x02_expect_0x01_pc_add_2_store_in_file_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = DECFSZ, .name = "decfsz" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = BANKED};



 FSR[0xfe0] = 0x05;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x02;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  decfsz(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)220, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((FSR[code.operand1+(FSR[0xfe0]<<8)])), (((void *)0)), (_U_UINT)222, UNITY_DISPLAY_STYLE_HEX8);

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

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)237, UNITY_DISPLAY_STYLE_INT);

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

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)253, UNITY_DISPLAY_STYLE_INT);

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

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)269, UNITY_DISPLAY_STYLE_INT);

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

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)284, UNITY_DISPLAY_STYLE_INT);

 }

}
