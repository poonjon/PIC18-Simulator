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

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = ACCESS, .absoluteAddress = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[0x12] = 0x01;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_file_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = ACCESS, .absoluteAddress = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[0x12] = 0x01;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[code.operand1])), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x02_to_0x01_expect_0x03_save_in_file_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x190, .operand2 = F, .operand3 = -1, .absoluteAddress = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x02;

 FSR[0x190] = 0x01;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x03)), (_U_SINT)((FSR[0x090])), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_file_0xfa1_access_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xa1, .operand2 = F, .operand3 = ACCESS, .absoluteAddress = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[0xa1] = 0x01;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[0xfa1])), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_wreg_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 1, .absoluteAddress = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[0xfe0] = 0x5;

 FSR[0x512] = 0x01;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_file_bsr_5_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1, .absoluteAddress = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[0xfe0] = 0x5;

 FSR[0x512] = 0x01;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[0x512])), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x80_to_0x80_expect_0x00_save_in_wreg_status_0x0d_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0, .absoluteAddress = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x80;

 FSR[0x12] = 0x80;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00001101)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0xff_to_0x01_expect_0x00_save_in_wreg_status_0x07_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0, .absoluteAddress = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0xff;

 FSR[0x12] = 0x01;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)122, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000111)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)123, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x0f_to_0x01_expect_0x00_save_in_wreg_status_0x10_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0, .absoluteAddress = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x0f;

 FSR[0x12] = 0x01;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x10)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)137, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000010)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)138, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x0f_to_0x0a_expect_0x19_save_in_file_status_0x02_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0, .absoluteAddress = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x0f;

 FSR[0x12] = 0x0a;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x19)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)152, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000010)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)153, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x00_to_0x00_expect_0x00_save_in_file_status_0x00_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0, .absoluteAddress = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x00;

 FSR[0x12] = 0x00;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)167, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b0000100)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)168, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0xbb_to_0xcc_expect_0x87_save_in_file_status_0x13_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0, .absoluteAddress = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0xbb;

 FSR[0x12] = 0xcc;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x87)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)182, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00010011)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x01_to_0x01_expect_0x02_save_in_file_bsr_5_status_0x00_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1, .absoluteAddress = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x01;

 FSR[0xfe0] = 0x5;

 FSR[0x512] = 0x01;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((FSR[0x512])), (((void *)0)), (_U_UINT)198, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)199, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x03_to_0x01_expect_0x04_save_in_file_bsr_5_status_0x00_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xf90, .operand2 = 1, .operand3 = 1, .absoluteAddress = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x03;

 FSR[0xfe0] = 0x5;

 FSR[0xf90] = 0x01;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x04)), (_U_SINT)((FSR[0x590])), (((void *)0)), (_U_UINT)214, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)215, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x0a_to_0x0a_expect_0x14_save_in_file_bsr_5_status_0x02_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1, .absoluteAddress = 0};



 FSR[0xfd8] = 0;

 FSR[0xfe8] = 0x0a;

 FSR[0xfe0] = 0x5;

 FSR[0x512] = 0x0a;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x14)), (_U_SINT)((FSR[0x512])), (((void *)0)), (_U_UINT)230, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000010)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)231, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0xff_to_0x01_with_carry_expect_0x00_save_in_file_bsr_5_status_0x03_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1, .absoluteAddress = 0};



 FSR[0xfd8] = 1;

 FSR[0xfe8] = 0xff;

 FSR[0xfe0] = 0x5;

 FSR[0x512] = 0x01;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x01)), (_U_SINT)((FSR[0x512])), (((void *)0)), (_U_UINT)246, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000011)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)247, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x0a_to_0x0a_with_carry_expect_0x15_save_in_file_bsr_5_status_0x02_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = 1, .absoluteAddress = 0};



 FSR[0xfd8] = 0x01;

 FSR[0xfe8] = 0x0a;

 FSR[0xfe0] = 0x5;

 FSR[0x512] = 0x0a;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x15)), (_U_SINT)((FSR[0x512])), (((void *)0)), (_U_UINT)262, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000010)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)263, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x0a_to_0x01_with_carry_expect_0x0b_default_operand2_bsr_5_status_0x02_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xf91, .operand2 = BANKED, .operand3 = -1, .absoluteAddress = 0};



 FSR[0xfd8] = 0x01;

 FSR[0xfe8] = 0x0a;

 FSR[0xfe0] = 0x5;

 FSR[0xf91] = 0x01;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x0c)), (_U_SINT)((FSR[0x591])), (((void *)0)), (_U_UINT)278, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000000)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)279, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0xfe_to_0x01_with_carry_expect_0x00_save_in_wreg_status_0x07_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0, .absoluteAddress = 0};



 FSR[0xfd8] = 0x1;

 FSR[0xfe8] = 0xfe;

 FSR[0x12] = 0x01;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)293, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00000111)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)294, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_should_add_0x60_to_0x60_with_carry_expect_0x00_save_in_wreg_status_0x07_should_pass(){

 int error;



 Instruction inst = { .mnemonic = ADDWFC, .name = "addwfc" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = 0, .absoluteAddress = 0};



 FSR[0xfd8] = 0x1;

 FSR[0xfe8] = 0x40;

 FSR[0x12] = 0x40;



 addwfc(&code);

 UnityAssertEqualNumber((_U_SINT)((0x81)), (_U_SINT)((FSR[0xfe8])), (((void *)0)), (_U_UINT)308, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0b00011000)), (_U_SINT)((FSR[0xfd8])), (((void *)0)), (_U_UINT)309, UNITY_DISPLAY_STYLE_INT);

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

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)325, UNITY_DISPLAY_STYLE_INT);

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

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)343, UNITY_DISPLAY_STYLE_INT);

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

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)361, UNITY_DISPLAY_STYLE_INT);

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

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)378, UNITY_DISPLAY_STYLE_INT);

 }

}
