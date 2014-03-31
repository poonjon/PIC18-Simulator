#include <stdio.h>
#include "CException.h"
#include "Bytecode.h"
#include "BTFSC.h"

unsigned char FSR[0x1000];
int PC; 

void btfsc(Bytecode *code){
	int value;
	
	switch(check_valid_operands(code)){
		
		case 1: //access
			value = FSR[code->operand1];
			PC = check_operand2(code, value);
			break;
			
		case 2:	//bank
			value = FSR[code->operand1+(FSR[BSR]<<8)];
			PC = check_operand2(code, value);
			break;
		
	}
}

int check_valid_operands(Bytecode *code){
	
	//to check if the values are in range for operand 1 
	if(code->operand1 > -1 && code->operand1 <= 0xFF)
		return check_operand3(code);
	
	//values in operand 1 are invalid
	else 
		Throw(ERR_INVALID_OPERAND);

}

int check_operand3(Bytecode *code){	
	
	//access bank
	if(code->operand3 == ACCESS){
		check_operand1_access_range(code);
		return 1;
	}
	
	//banked
	else if(code->operand3 == BANKED){
		
		//to check if bsr is in range of 0 to F
		if(FSR[BSR] >= 0x0 && FSR[BSR] <= 0xF)
			return 2;
		
		//invalid bsr range
		else
		Throw(ERR_INVALID_OPERAND);
	}
	
	//invalid operand 3
	else
		Throw(ERR_INVALID_OPERAND);

}

void check_operand1_access_range(Bytecode *code){

	if(code->operand1 >= 0x80 && code->operand1 <= 0xFF){
		int temp1;
		
		temp1 = FSR[code->operand1]; //store value into temp
		code->operand1 = code->operand1 | 0xf00;  //change addresses that are >= than 0x80 into  0xfxx
		FSR[code->operand1] = temp1; //place original value into the new address
	}
}

int check_operand2(Bytecode *code, int value){
	if(code->operand2 < 8 && code->operand2 > -1){
		switch(code->operand2){
			case 0:
				if((value&0x1) == 0)
					return PC += 4;
				else if((value&0x1) != 0)
					return PC += 2;
				
				break;
				
			case 1:
				if((value&0x2) == 0)
					return PC += 4;
				else if((value&0x2) != 0)
					return PC += 2;
				
				break;
				
			case 2:
				if((value&0x4) == 0)
					return PC += 4;
				else if((value&0x4) != 0)
					return PC += 2;
				
				break;
				
			case 3:
				if((value&0x8) == 0)
					return PC += 4;
				else if((value&0x8) != 0)
					return PC += 2;
				
				break;
				
			case 4:
				if((value&0x10) == 0)
					return PC += 4;
				else if((value&0x10) != 0)
					return PC += 2;
				
				break;
				
			case 5:
				if((value&0x20) == 0)
					return PC += 4;
				else if((value&0x20) != 0)
					return PC += 2;
				
				break;
				
			case 6:
				if((value&0x40) == 0)
					return PC += 4;
				else if((value&0x40) != 0)
					return PC += 2;
				
				break;
				
			case 7:
				if((value&0x80) == 0)
					return PC += 4;
				else if((value&0x80) != 0)
					return PC += 2;
				
				break;
				
		}
	}
	
	else 
		Throw(ERR_INVALID_OPERAND);

}