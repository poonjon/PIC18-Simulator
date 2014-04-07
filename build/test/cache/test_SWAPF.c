#include "unity.h"
#include "SWAPF.h"
#include "Execute.h"
#include "CException.h"
#include "Bytecode.h"


void setUp(){}

void tearDown(){}



void test_swapf_should_swap_0x12_into_0x21_save_in_wreg_access_bank_should_pass(){

 int error;



 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = ACCESS, .absoluteAddress = 0};



 FSR[0x12] = 0x12;



 swapf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x21)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x12_into_0x21_save_in_file_reg_acess_bank_should_pass(){

 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = ACCESS, .absoluteAddress = 0};



 FSR[0x12] = 0x12;



 swapf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x21)), (_U_SINT)(_US8 )((FSR[0x12])), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x13_into_0x21_save_in_file_reg_acess_bank_should_pass(){

 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xff0, .operand2 = 1, .operand3 = ACCESS, .absoluteAddress = 0};



 FSR[0xff0] = 0x13;



 swapf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x31)), (_U_SINT)(_US8 )((FSR[0xff0])), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x12_into_0x21_default_operand2_operand3_should_pass(){

 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = -1, .operand3 = -1, .absoluteAddress = 0};



 FSR[0x12] = 0x12;



 swapf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x21)), (_U_SINT)(_US8 )((FSR[0x12])), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x12_into_0x21_default_operand3_file_reg_should_pass(){

 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = -1, .absoluteAddress = 0};



 FSR[0x12] = 0x12;



 swapf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x21)), (_U_SINT)(_US8 )((FSR[0x12])), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x12_into_0x21_default_operand2_acess_bank_should_pass(){

 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x90, .operand2 = ACCESS, .operand3 = -1, .absoluteAddress = 0};



 FSR[0x90] = 0x12;



 swapf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x21)), (_U_SINT)(_US8 )((FSR[0xf90])), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x51_into_0x15_default_operand2_acess_bank_should_pass(){

 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xff3, .operand2 = ACCESS, .operand3 = -1, .absoluteAddress = 0};



 FSR[0xff3] = 0x51;



 swapf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x15)), (_U_SINT)(_US8 )((FSR[0xff3])), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x01_into_0x10_save_in_wreg_with_bsr_5_should_pass(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = BANKED, .absoluteAddress = 0};



 FSR[0xfe0] = 0x5;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;



 swapf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x10)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x11_into_0x11_save_in_wreg_with_bsr_5_should_pass(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xfa3, .operand2 = 0, .operand3 = BANKED, .absoluteAddress = 0};



 FSR[0xfe0] = 0x5;

 FSR[0xfa3] = 0x11;



 swapf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x01_into_0x10_save_in_file_reg_with_bsr_5_should_pass(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = BANKED, .absoluteAddress = 0};



 FSR[0xfe0] = 0x5;

 FSR[0x512] = 0x01;



 swapf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x10)), (_U_SINT)(_US8 )((FSR[0x512])), (((void *)0)), (_U_UINT)124, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x04_into_0x40_save_in_file_reg_with_bsr_5_should_pass(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xfa1, .operand2 = F, .operand3 = BANKED, .absoluteAddress = 0};



 FSR[0xfe0] = 0x5;

 FSR[0xfa1] = 0x04;



 swapf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x40)), (_U_SINT)(_US8 )((FSR[0x5a1])), (((void *)0)), (_U_UINT)137, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x01_into_0x10_default_operand2_with_bsr_5_should_pass(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = BANKED, .absoluteAddress = 0};



 FSR[0xfe0] = 0x5;

 FSR[0x512] = 0x01;



 swapf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x10)), (_U_SINT)(_US8 )((FSR[0x512])), (((void *)0)), (_U_UINT)150, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x01_into_0x10_save_in_file_reg_with_bsr_15_should_throw_exception(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = BANKED};



 FSR[0xfe0] = 0x15;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)165, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_swapf_should_swap_0x01_into_0x10_invalid_operand1_should_throw_exception(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = -1, .operand2 = 2, .operand3 = BANKED};



 FSR[0xfe0] = 0x15;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_swapf_should_swap_0x01_into_0x10_invalid_operand2_should_throw_exception(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 2, .operand3 = BANKED};



 FSR[0xfe0] = 0x15;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)197, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_swapf_should_swap_0x01_into_0x10_invalid_operand3_should_throw_exception(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = 2};



 FSR[0xfe0] = 0x15;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)213, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_swapf_should_swap_0x01_into_0x10_default_operand2_invalid_operand3_should_throw_exception(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = ACCESS, .operand3 = 2};



 FSR[0xfe0] = 0x15;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)229, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_swapf_should_swap_0x01_into_0x10_default_operand3_invalid_operand2_should_throw_exception(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 4, .operand3 = -1};



 FSR[0xfe0] = 0x15;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)245, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_swapf_should_swap_0x12_into_0x21_should_change_operand1_0xa1_into_0xfa1_save_in_wreg_access_bank_should_pass(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xa1, .operand2 = W, .operand3 = ACCESS, .absoluteAddress = 0};



 FSR[0xa1] = 0x12;



 swapf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x21)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)258, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x12_into_0x21_should_change_operand1_0xa2_into_0xfa2_save_in_wreg_access_bank_should_pass(){

 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xa2, .operand2 = ACCESS, .operand3 = -1, .absoluteAddress = 0};



 FSR[0xa2] = 0x12;



 swapf(&code);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x21)), (_U_SINT)(_US8 )((FSR[0xfa2])), (((void *)0)), (_U_UINT)269, UNITY_DISPLAY_STYLE_HEX8);

}
