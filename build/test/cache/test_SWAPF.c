#include "unity.h"
#include "SWAPF.h"
#include "CException.h"
#include "Bytecode.h"


void setUp() {}

void tearDown() {}



void test_swapf_should_swap_0x12_into_0x21_save_in_wreg_access_bank_should_pass(){

 int error;



 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = W, .operand3 = ACCESS};



 FSR[code.operand1] = 0x12;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x21)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)23, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x02)), (_U_SINT)(_US8 )((PC)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x12_into_0x21_save_in_file_reg_acess_bank_should_pass(){

 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 1, .operand3 = ACCESS};



 FSR[code.operand1] = 0x12;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)39, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x21)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US16)((0x02)), (_U_SINT)(_US16)((PC)), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_HEX16);

}



void test_swapf_should_swap_0x13_into_0x21_save_in_file_reg_acess_bank_should_pass(){

 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xff0, .operand2 = 1, .operand3 = ACCESS};



 FSR[code.operand1] = 0x13;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x31)), (_U_SINT)(_US8 )((FSR[0xff0])), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US16)((0x02)), (_U_SINT)(_US16)((PC)), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_HEX16);

}



void test_swapf_should_swap_0x12_into_0x21_default_operand2_operand3_should_pass(){

 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = -1, .operand3 = -1};



 FSR[code.operand1] = 0x12;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x21)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)77, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US16)((0x02)), (_U_SINT)(_US16)((PC)), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_HEX16);

}



void test_swapf_should_swap_0x12_into_0x21_default_operand3_file_reg_should_pass(){

 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = -1};



 FSR[code.operand1] = 0x12;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x21)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US16)((0x02)), (_U_SINT)(_US16)((PC)), (((void *)0)), (_U_UINT)96, UNITY_DISPLAY_STYLE_HEX16);

}



void test_swapf_should_swap_0x12_into_0x21_default_operand2_acess_bank_should_pass(){

 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = ACCESS, .operand3 = -1};



 FSR[code.operand1] = 0x12;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x21)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)113, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x02)), (_U_SINT)(_US8 )((PC)), (((void *)0)), (_U_UINT)114, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x51_into_0x15_default_operand2_acess_bank_should_pass(){

 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xff3, .operand2 = ACCESS, .operand3 = -1};



 FSR[code.operand1] = 0x51;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)129, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x15)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)131, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x02)), (_U_SINT)(_US8 )((PC)), (((void *)0)), (_U_UINT)132, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x01_into_0x10_save_in_wreg_with_bsr_5_should_pass(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 0, .operand3 = BANKED};



 FSR[0xfe0] = 0x5;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)149, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x10)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)151, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x02)), (_U_SINT)(_US8 )((PC)), (((void *)0)), (_U_UINT)152, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x11_into_0x11_save_in_wreg_with_bsr_5_should_pass(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xfa3, .operand2 = 0, .operand3 = BANKED};



 FSR[0xfe0] = 0x5;

 FSR[code.operand1] = 0x11;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)169, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)171, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x02)), (_U_SINT)(_US8 )((PC)), (((void *)0)), (_U_UINT)172, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x01_into_0x10_save_in_file_reg_with_bsr_5_should_pass(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = BANKED};



 FSR[0xfe0] = 0x5;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)189, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x10)), (_U_SINT)(_US8 )((FSR[code.operand1+(FSR[0xfe0]<<8)])), (((void *)0)), (_U_UINT)191, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x02)), (_U_SINT)(_US8 )((PC)), (((void *)0)), (_U_UINT)192, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x04_into_0x40_save_in_file_reg_with_bsr_5_should_pass(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xfa1, .operand2 = F, .operand3 = BANKED};



 FSR[0xfe0] = 0x5;

 FSR[code.operand1] = 0x04;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)209, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x40)), (_U_SINT)(_US8 )((FSR[0xfa1])), (((void *)0)), (_U_UINT)211, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x02)), (_U_SINT)(_US8 )((PC)), (((void *)0)), (_U_UINT)212, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x01_into_0x10_default_operand2_with_bsr_5_should_pass(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = BANKED};



 FSR[0xfe0] = 0x5;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)229, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x10)), (_U_SINT)(_US8 )((FSR[code.operand1+(FSR[0xfe0]<<8)])), (((void *)0)), (_U_UINT)231, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x02)), (_U_SINT)(_US8 )((PC)), (((void *)0)), (_U_UINT)232, UNITY_DISPLAY_STYLE_HEX8);

}



void test_swapf_should_swap_0x01_into_0x10_save_in_file_reg_with_bsr_15_should_throw_exception(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = BANKED};



 FSR[0xfe0] = 0x15;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)249, UNITY_DISPLAY_STYLE_INT);

 }



}



void test_swapf_should_swap_0x01_into_0x10_invalid_operand1_should_throw_exception(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x112, .operand2 = 2, .operand3 = BANKED};



 FSR[0xfe0] = 0x15;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)268, UNITY_DISPLAY_STYLE_INT);

 }



}



void test_swapf_should_swap_0x01_into_0x10_invalid_operand2_should_throw_exception(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 2, .operand3 = BANKED};



 FSR[0xfe0] = 0x15;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)287, UNITY_DISPLAY_STYLE_INT);

 }



}



void test_swapf_should_swap_0x01_into_0x10_invalid_operand3_should_throw_exception(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = F, .operand3 = 2};



 FSR[0xfe0] = 0x15;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)306, UNITY_DISPLAY_STYLE_INT);

 }



}



void test_swapf_should_swap_0x01_into_0x10_default_operand2_invalid_operand3_should_throw_exception(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = ACCESS, .operand3 = 2};



 FSR[0xfe0] = 0x15;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)325, UNITY_DISPLAY_STYLE_INT);

 }



}



void test_swapf_should_swap_0x01_into_0x10_default_operand3_invalid_operand2_should_throw_exception(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x12, .operand2 = 4, .operand3 = -1};



 FSR[0xfe0] = 0x15;

 FSR[code.operand1+(FSR[0xfe0]<<8)] = 0x01;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)344, UNITY_DISPLAY_STYLE_INT);

 }





}



void test_swapf_should_swap_0x12_into_0x21_should_change_operand1_0xa1_into_0xfa1_save_in_wreg_access_bank_should_pass(){



 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xa1, .operand2 = W, .operand3 = ACCESS};



 FSR[code.operand1] = 0x12;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)363, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x21)), (_U_SINT)(_US8 )((FSR[0xfe8])), (((void *)0)), (_U_UINT)365, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US16)((0xfa1)), (_U_SINT)(_US16)((code.operand1)), (((void *)0)), (_U_UINT)366, UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x02)), (_U_SINT)(_US8 )((PC)), (((void *)0)), (_U_UINT)367, UNITY_DISPLAY_STYLE_HEX8);



}



void test_swapf_should_swap_0x12_into_0x21_should_change_operand1_0xa2_into_0xfa2_save_in_wreg_access_bank_should_pass(){

 int error;

 Instruction inst = { .mnemonic = SWAPF, .name = "swapf" };

 Bytecode code = {.instruction = &inst, .operand1 = 0xa2, .operand2 = ACCESS, .operand3 = -1};



 FSR[code.operand1] = 0x12;

 code.absoluteAddress = 0x00;

 PC = code.absoluteAddress;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  swapf(&code);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { error = CExceptionFrames[MY_ID].Exception; error=error; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((ERR_INVALID_OPERAND)), (((void *)0)), (_U_UINT)383, UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x21)), (_U_SINT)(_US8 )((FSR[code.operand1])), (((void *)0)), (_U_UINT)385, UNITY_DISPLAY_STYLE_HEX8);

 UnityAssertEqualNumber((_U_SINT)(_US16)((0xfa2)), (_U_SINT)(_US16)((code.operand1)), (((void *)0)), (_U_UINT)386, UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((_U_SINT)(_US8 )((0x02)), (_U_SINT)(_US8 )((PC)), (((void *)0)), (_U_UINT)387, UNITY_DISPLAY_STYLE_HEX8);

}
