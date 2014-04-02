#include "unity.h"
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

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_file_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = ACCESS};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x02_to_0x01_expect_0x03_save_in_file_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xf90, .operand2 = F, .operand3 = ACCESS};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x02;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)71, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)72, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_file_0xfa1_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xa1, .operand2 = F, .operand3 = ACCESS};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0xfa1)), (_U_SINT)((code.operand1)), (((void *)0)), (_U_UINT)94, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_wreg_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 1};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)114, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)117, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)118, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_file_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)137, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[(FSR[0xfe0]<<8)+code.operand1])), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x80_to_0x80_expect_0x00_save_in_wreg_status_0x0d_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x80;

 FSR[code.operand1] = 0x80;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)159, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00001101)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)163, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)164, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0xff_to_0x01_expect_0x00_save_in_wreg_status_0x07_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0xff;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)182, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)185, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000111)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)186, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)187, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x0f_to_0x01_expect_0x00_save_in_wreg_status_0x10_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x0f;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)205, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x10)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)208, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000010)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)209, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)210, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x0f_to_0x0a_expect_0x19_save_in_file_status_0x02_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x0f;

 FSR[code.operand1] = 0x0a;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)228, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x19)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)231, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000010)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)232, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)233, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x00_to_0x00_expect_0x00_save_in_file_status_0x00_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x00;

 FSR[code.operand1] = 0x00;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)251, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)254, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b0000100)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)255, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)256, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0xbb_to_0xcc_expect_0x87_save_in_file_status_0x13_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0xbb;

 FSR[code.operand1] = 0xcc;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)274, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x87)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)277, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00010011)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)278, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)279, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_file_bsr_5_status_0x00_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)298, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[(FSR[0xfe0]<<8)+code.operand1])), (((void *)0)), (_U_UINT)301, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)302, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)303, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x03_to_0x01_expect_0x04_save_in_file_bsr_5_status_0x00_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xf90, .operand2 = 1, .operand3 = 1};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x03;

 FSR[0xfe0] = 0x5;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)322, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x04)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)325, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)326, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)327, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x0a_to_0x0a_expect_0x14_save_in_file_bsr_5_status_0x02_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x0a;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0x0a;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)346, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x14)), (_U_SINT)((FSR[(FSR[0xfe0]<<8)+code.operand1])), (((void *)0)), (_U_UINT)349, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000010)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)350, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)351, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0xff_to_0x01_with_carry_expect_0x00_save_in_file_bsr_5_status_0x03_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};



 FSR[0xfd8] = 1;

 FSR[0xfe8] = 0xff;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)370, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((FSR[(FSR[0xfe0]<<8)+code.operand1])), (((void *)0)), (_U_UINT)373, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000011)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)374, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)375, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x0a_to_0x0a_with_carry_expect_0x15_save_in_file_bsr_5_status_0x02_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};



 FSR[0xfd8] = 0x01;

 FSR[0xfe8] = 0x0a;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0x0a;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)394, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x15)), (_U_SINT)((FSR[(FSR[0xfe0]<<8)+code.operand1])), (((void *)0)), (_U_UINT)397, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000011)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)398, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)399, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x0a_to_0x0a_with_carry_expect_0x15_default_operand2_bsr_5_status_0x02_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xf91, .operand2 = BANKED, .operand3 = -1};



 FSR[0xfd8] = 0x01;

 FSR[0xfe8] = 0x0a;

 FSR[0xfe0] = 0x5;

 FSR[code.operand1] = 0x0a;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)418, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x15)), (_U_SINT)((FSR[0xf91])), (((void *)0)), (_U_UINT)421, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000011)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)422, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)423, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0xfe_to_0x01_with_carry_expect_0x00_save_in_wreg_status_0x07_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfd8] = 0x1;

 FSR[0xfe8] = 0xfe;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)441, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)444, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000111)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)445, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)446, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x60_to_0x60_with_carry_expect_0x00_save_in_wreg_status_0x07_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfd8] = 0x1;

 FSR[0xfe8] = 0x40;

 FSR[code.operand1] = 0x40;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)464, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x81)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)467, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00011001)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)468, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)469, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_invalid_operand1_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = -1, .operand2 = W, .operand3 = ACCESS};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)487, UNITY_DISPLAY_STYLE_INT);

 }



}



void test_addwfc_invalid_operand2_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x01, .operand2 = 2, .operand3 = ACCESS};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)507, UNITY_DISPLAY_STYLE_INT);

 }



}



void test_addwfc_invalid_operand3_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x01, .operand2 = W, .operand3 = 2};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)527, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_addwfc_default_operand2_invalid_operand3_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x01, .operand2 = ACCESS, .operand3 = 2};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwfc(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)546, UNITY_DISPLAY_STYLE_INT);

 }

}
