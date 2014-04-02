#include "unity.h"
#include "Bytecode.h"
#include "ByteOrientedOperations.h"


char FSR[0x1000];



void test_movff_mov_file_location_1_to_2(){

 Instruction inst = { .mnemonic = MOVFF, .name = "movff" };

 Bytecode code = {.instruction = &inst, .operand1 = 0x011, .operand2 = 0x010, .operand3 = -1};



 FSR[code.operand1] = 1;

 FSR[code.operand2] = 0;





 movff(&code);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((FSR[0x011])), (((void *)0)), (_U_UINT)17, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((FSR[0x010])), (((void *)0)), (_U_UINT)18, UNITY_DISPLAY_STYLE_INT);

}
