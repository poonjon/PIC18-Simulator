#include "unity.h"
#include "RLCF.h"
#include "Execute.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_rlcf_00000000_with_carry_1_should_get_00000001_status_0x00_store_in_wreg_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = ACCESS};



 FSR[0xfd8] = 0x1;

 FSR[code.operand1] = 0b00000000;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  rlcf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0b00000001)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000000)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

}



void test_rlcf_10000000_with_carry_1_should_get_00000001_status_0x01_store_in_file_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = ACCESS};



 FSR[0xfd8] = 0x1;

 FSR[code.operand1] = 0b10000000;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  rlcf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0b0000001)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b0000001)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT);

}



void test_rlcf_11000000_with_carry_1_should_get_10000001_status_0x11_store_in_file_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = ACCESS, .operand3 = -1};



 FSR[0xfd8] = 0x1;

 FSR[code.operand1] = 0b11000000;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  rlcf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0b10000001)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00010001)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);

}



void test_rlcf_00000000_with_carry_0_should_get_00000000_status_0x11_store_in_file_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xff2, .operand2 = ACCESS, .operand3 = -1};



 FSR[0xfd8] = 0x0;

 FSR[code.operand1] = 0b0000000;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  rlcf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0b00000000)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000100)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

}



void test_rlcf_10000000_with_carry_1_should_get_00000000_status_0x05_store_in_file_f92_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x92, .operand2 = F, .operand3 = ACCESS};



 FSR[0xfd8] = 0x0;

 FSR[code.operand1] = 0b10000000;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  rlcf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0b0000000)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)101, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b0000101)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)102, UNITY_DISPLAY_STYLE_INT);

}



void test_rlcf_10100110_with_carry_1_should_get_01001101_status_0x01_store_in_wreg_banked_should_pass(){

 int error;



 Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = BANKED};



 FSR[0xfd8] = 1;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0b10100110;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  rlcf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)118, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0b01001101)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)121, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000001)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)122, UNITY_DISPLAY_STYLE_INT);

}



void test_rlcf_11111111_with_carry_1_should_get_11111111_status_0x11_store_in_wreg_banked_should_pass(){

 int error;



 Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xf97, .operand2 = W, .operand3 = BANKED};



 FSR[0xfd8] = 1;

 FSR[0xfe0] = 0x5;

 FSR[code.operand1] = 0xff;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  rlcf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)138, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0b11111111)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00010001)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)142, UNITY_DISPLAY_STYLE_INT);

}



void test_rlcf_01110110_with_carry_0_should_get_11101100_status_0x01_store_in_wreg_banked_should_pass(){

 int error;



 Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = BANKED};



 FSR[0xfd8] = 0;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0b01110110;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  rlcf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0b11101100)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)161, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00010000)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT);

}



void test_rlcf_01001111_with_carry_0_should_get_10011110_status_0x10_store_in_file_banked_should_pass(){

 int error;



 Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = BANKED};



 FSR[0xfd8] = 0;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0b01001111;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  rlcf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)178, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0b10011110)), (_U_SINT)((FSR[(FSR[0xfe0]<<8)+code.operand1])), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00010000)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)182, UNITY_DISPLAY_STYLE_INT);

}



void test_rlcf_00001111_with_carry_0_should_get_00011110_status_0x00_store_in_file_banked_should_pass(){

 int error;



 Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = BANKED, .operand3 = -1};



 FSR[0xfd8] = 0;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0b00001111;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  rlcf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)198, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0b00011110)), (_U_SINT)((FSR[(FSR[0xfe0]<<8)+code.operand1])), (((void *)0)), (_U_UINT)201, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000000)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)202, UNITY_DISPLAY_STYLE_INT);

}



void test_rlcf_invalid_operand1_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };

 Bytecode code = {.instruction = &inst, .operand1 = -123, .operand2 = F, .operand3 = BANKED};



 FSR[0xfd8] = 0;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0b01001111;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  rlcf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)218, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_rlcf_invalid_operand2_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 2, .operand3 = BANKED};



 FSR[0xfd8] = 0;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0b01001111;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  rlcf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)235, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_rlcf_invalid_operand3_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = RLCF, .name = "rlcf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = 2};



 FSR[0xfd8] = 0;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0b01001111;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  rlcf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)252, UNITY_DISPLAY_STYLE_INT);

 }

}
