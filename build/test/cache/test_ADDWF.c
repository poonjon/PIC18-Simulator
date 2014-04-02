#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "ADDWF.h"


void setUp() {}

void tearDown() {}



void test_addwf_should_add_0x01_to_0x01_expect_0x02_save_in_wreg_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = ACCESS};



 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)23, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_should_add_0x01_to_0x01_expect_0x02_save_in_file_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = ACCESS};



 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_should_add_0x01_to_0x01_expect_0x02_save_in_file_0xfa1_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xa1, .operand2 = F, .operand3 = ACCESS};



 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0xfa1)), (_U_SINT)((code.operand1)), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_should_add_0x01_to_0x01_expect_0x02_save_in_wreg_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 1};



 FSR[0xfe8] = 0x01;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)88, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_should_add_0x01_to_0x01_expect_0x02_save_in_file_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};



 FSR[0xfe8] = 0x01;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)110, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[(FSR[0xfe0]<<8)+code.operand1])), (((void *)0)), (_U_UINT)113, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)114, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_should_add_0x80_to_0x80_expect_0x00_save_in_wreg_status_0x0d_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfe8] = 0x80;

 FSR[code.operand1] = 0x80;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)131, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)134, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00001101)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)135, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)136, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_should_add_0xff_to_0x01_expect_0x00_save_in_wreg_status_0x0f_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfe8] = 0xff;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)153, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)156, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00001111)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)157, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_should_add_0x0f_to_0x01_expect_0x00_save_in_wreg_status_0x10_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfe8] = 0x0f;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)175, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x10)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)178, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000010)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)179, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)180, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_should_add_0x0f_to_0x0a_expect_0x19_save_in_file_status_0x12_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfe8] = 0x0f;

 FSR[code.operand1] = 0x0a;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)197, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x19)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)200, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00010010)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)201, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)202, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_should_add_0x00_to_0x00_expect_0x00_save_in_file_status_0x00_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfe8] = 0x00;

 FSR[code.operand1] = 0x00;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)219, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)222, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b0000100)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)223, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)224, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_should_add_0xbb_to_0xcc_expect_0x0x87_save_in_file_status_0x1b_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0};



 FSR[0xfe8] = 0xbb;

 FSR[code.operand1] = 0xcc;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)241, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x87)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)244, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00011011)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)245, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)246, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_should_add_0x01_to_0x01_expect_0x02_save_in_file_bsr_5_status_0x00_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};



 FSR[0xfe8] = 0x01;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)264, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[(FSR[0xfe0]<<8)+code.operand1])), (((void *)0)), (_U_UINT)267, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)268, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)269, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_should_add_0xff_to_0x01_expect_0x00_save_in_file_bsr_5_status_0x0f_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};



 FSR[0xfe8] = 0xff;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)287, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[(FSR[0xfe0]<<8)+code.operand1])), (((void *)0)), (_U_UINT)290, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00001111)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)291, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)292, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_should_add_0x0a_to_0x0a_expect_0x00_save_in_file_bsr_5_status_0x02_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1};



 FSR[0xfe8] = 0x0a;

 FSR[0xfe0] = 0x5;

 FSR[(FSR[0xfe0]<<8)+code.operand1] = 0x0a;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)310, UNITY_DISPLAY_STYLE_INT);

 }



 UnityAssertEqualNumber((_U_SINT)((0x14)), (_U_SINT)((FSR[(FSR[0xfe0]<<8)+code.operand1])), (((void *)0)), (_U_UINT)313, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000010)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)314, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((PC)), (((void *)0)), (_U_UINT)315, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_invalid_operand1_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = -1, .operand2 = W, .operand3 = ACCESS};



 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)332, UNITY_DISPLAY_STYLE_INT);

 }



}



void test_addwf_invalid_operand2_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x01, .operand2 = 2, .operand3 = ACCESS};



 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)351, UNITY_DISPLAY_STYLE_INT);

 }



}



void test_addwf_invalid_operand3_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x01, .operand2 = W, .operand3 = 2};



 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)370, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_addwf_default_operand2_invalid_operand3_should_throw_exception(){

 int error;



 Instruction inst = { .mnemonic = ADDWF, .name = "addwf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x01, .operand2 = ACCESS, .operand3 = 2};



 FSR[0xfe8] = 0x01;

 FSR[code.operand1] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  addwf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)388, UNITY_DISPLAY_STYLE_INT);

 }

}
