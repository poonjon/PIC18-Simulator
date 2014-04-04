#include "unity.h"
#include "Execute.h"
#include "CException.h"
#include "Bytecode.h"
#include "ADDWFC.h"


void setUp() {}

void tearDown() {}



void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_wreg_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = ACCESS};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)23, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_file_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = ACCESS};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x02_to_0x01_expect_0x03_save_in_file_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x190, .operand2 = F, .operand3 = -1};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x02;

 FSR[code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((FSR[code.operand1+(FSR[0xfe0]<<8)])), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_file_0xfa1_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xa1, .operand2 = F, .operand3 = ACCESS};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0xfa1)), (_U_SINT)((code.operand1)), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_wreg_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 1};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)101, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_file_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)121, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[(FSR[0xfe0]<<8)+code.operand1])), (((void *)0)), (_U_UINT)124, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x80_to_0x80_expect_0x00_save_in_wreg_status_0x0d_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x80;

 FSR[code.operand1] = 0x80;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)143, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00001101)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0xff_to_0x01_expect_0x00_save_in_wreg_status_0x07_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0xff;

 FSR[code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)163, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000111)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)164, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x0f_to_0x01_expect_0x00_save_in_wreg_status_0x10_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x0f;

 FSR[code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)180, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x10)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000010)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)184, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x0f_to_0x0a_expect_0x19_save_in_file_status_0x02_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x0f;

 FSR[code.operand1] = 0x0a;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)200, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x19)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)203, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000010)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)204, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x00_to_0x00_expect_0x00_save_in_file_status_0x00_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x00;

 FSR[code.operand1] = 0x00;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)220, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)223, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b0000100)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)224, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0xbb_to_0xcc_expect_0x87_save_in_file_status_0x13_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0xbb;

 FSR[code.operand1] = 0xcc;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)240, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x87)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)243, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00010011)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)244, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_file_bsr_5_status_0x00_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)261, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[(FSR[0xfe0]<<8)+code.operand1])), (((void *)0)), (_U_UINT)264, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)265, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x03_to_0x01_expect_0x04_save_in_file_bsr_5_status_0x00_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xf90, .operand2 = 1, .operand3 = 1};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x03;

 FSR[0xfe0] = 0x5;

 FSR[code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)282, UNITY_DISPLAY_STYLE_INT);

 }







}



void test_addwfc_should_add_0x0a_to_0x0a_expect_0x14_save_in_file_bsr_5_status_0x02_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x0a;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0x0a;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)303, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x14)), (_U_SINT)((FSR[(FSR[0xfe0]<<8)+code.operand1])), (((void *)0)), (_U_UINT)306, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000010)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)307, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0xff_to_0x01_with_carry_expect_0x00_save_in_file_bsr_5_status_0x03_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};



 FSR[0xfd8] = 1;

 FSR[0xfe8] = 0xff;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)324, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((FSR[(FSR[0xfe0]<<8)+code.operand1])), (((void *)0)), (_U_UINT)327, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000011)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)328, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x0a_to_0x0a_with_carry_expect_0x15_save_in_file_bsr_5_status_0x02_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};



 FSR[0xfd8] = 0x01;

 FSR[0xfe8] = 0x0a;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0x0a;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)345, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x15)), (_U_SINT)((FSR[(FSR[0xfe0]<<8)+code.operand1])), (((void *)0)), (_U_UINT)348, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000011)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)349, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x0a_to_0x0a_with_carry_expect_0x15_default_operand2_bsr_5_status_0x02_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xf91, .operand2 = BANKED, .operand3 = -1};



 FSR[0xfd8] = 0x01;

 FSR[0xfe8] = 0x0a;

 FSR[0xfe0] = 0x5;

 FSR[code.operand1] = 0x0a;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)366, UNITY_DISPLAY_STYLE_INT);

 }







}



void test_addwfc_should_add_0xfe_to_0x01_with_carry_expect_0x00_save_in_wreg_status_0x07_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfd8] = 0x1;

 FSR[0xfe8] = 0xfe;

 FSR[code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)386, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)389, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000111)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)390, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x60_to_0x60_with_carry_expect_0x00_save_in_wreg_status_0x07_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfd8] = 0x1;

 FSR[0xfe8] = 0x40;

 FSR[code.operand1] = 0x40;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)406, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x81)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)409, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00011001)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)410, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_invalid_operand1_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = -1, .operand2 = W, .operand3 = ACCESS};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)426, UNITY_DISPLAY_STYLE_INT);

 }



}



void test_addwfc_invalid_operand2_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x01, .operand2 = 2, .operand3 = ACCESS};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)444, UNITY_DISPLAY_STYLE_INT);

 }



}



void test_addwfc_invalid_operand3_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x01, .operand2 = W, .operand3 = 2};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)462, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_addwfc_default_operand2_invalid_operand3_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x01, .operand2 = ACCESS, .operand3 = 2};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)479, UNITY_DISPLAY_STYLE_INT);

 }

}
