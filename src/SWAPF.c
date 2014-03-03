#include <stdio.h>
#include "Bytecode.h"
#include "SWAPF.h"

char FSR[0x1000];

void swapf(Bytecode *code){

int temp1, temp2;

FSR[BSR] = code->operand3;

if(code->operand2 == 0){
temp1 = code->operand1;
temp2 = code->operand1;

FSR[WREG] = (temp1<<4)+(temp2>>4);
}

else if(code->operand2 == 1){
temp1 = code->operand1;
temp2 = code->operand1;

code->operand1 = (temp1<<4)+(temp2>>4);
}

else
printf("error\n");

}