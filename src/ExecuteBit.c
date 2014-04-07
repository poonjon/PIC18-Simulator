#include <stdio.h>
#include "CException.h"
#include "Bytecode.h"
#include "ExecuteBit.h"

int temp1;

int check_valid_operands(Bytecode *code){
	
	if(code->operand1 < 0)
		Throw(ERR_INVALID_OPERAND);
	
	else if(code->operand1 >= 0x0 && code->operand1 < 0x80)
		return check_operand3(code);	
	
	else if(code->operand1 >= 0x80 && code->operand1 < 0xfff)
		return operand1_exceeded_range_checks(code);
}

int operand1_exceeded_range_checks(Bytecode *code){
	
	if(code->operand1 >= 0x80 && code->operand1 <= 0xff){ //check if code operand1 is access sfr range
		
		if(code->operand3 == -1){ //destroy operand3
			code->operand3 = BANKED; //destroy operand3
			return check_operand3(code);
		}
		
		else if(code->operand3 == ACCESS || code->operand3 == 0) //if operand3 is access, stay access
			return check_operand3(code);
		
		else if(code->operand3 == BANKED || code->operand3 == 1) //if operand3 is banked, destroy fsr, use bsr value
			return check_operand3(code);
		
		else
			Throw(ERR_INVALID_OPERAND);
	}
	
	else if(code->operand1 >= 0xf80 && code->operand1 <= 0xfff){ //check if code operand1 is sfr
		
		if(code->operand3 == -1){ //check if operand3 is default, check operand 2
			code->operand3 = ACCESS;
			return check_operand3(code);
		}

		else if(code->operand3 == ACCESS || code->operand3 == 0) //if operand3 is access, stay access
			return check_operand3(code);
		
		else if(code->operand3 == BANKED || code->operand3 == 1){ //if operand3 is banked, destroy fsr, use bsr value
			temp1 = FSR[code->operand1];
			code->operand1 = ((code->operand1)&0x0ff)+(FSR[BSR]<<8);
			FSR[code->operand1] = temp1;
			code->operand1 = (code->operand1)&0x0ff;
			return check_operand3(code);
		}
		
		else
			Throw(ERR_INVALID_OPERAND);
	}

	else if(code->operand1 >= 0x100 && code->operand1 < 0xf80 ){ // check if code operand1 is not in sfr range but exceed 0xff
		
		if(code->operand3 == -1){ // if operand3 is set to default
			temp1 = FSR[code->operand1];
			code->operand1 = ((code->operand1)&0x0ff)+(FSR[BSR]<<8);
			FSR[code->operand1] = temp1;
			code->operand1 = (code->operand1)&0x0ff;
			code->operand3 = BANKED;
			return check_operand3(code);
		}

		else if(code->operand3 == BANKED || code->operand3 == 1){ // destroy msb
			temp1 = FSR[code->operand1];
			code->operand1 = ((code->operand1)&0x0ff)+(FSR[BSR]<<8);
			FSR[code->operand1] = temp1;
			code->operand1 = (code->operand1)&0x0ff;
			return check_operand3(code);
		}
		
		else if(code->operand3 == ACCESS || code->operand3 == 0){ //destroy msb
			temp1 = FSR[code->operand1];
			code->operand1 = (code->operand1)&0x0ff;
			FSR[code->operand1] = temp1;
			return check_operand3(code);
		}
		
		else
			Throw(ERR_INVALID_OPERAND);
	}
	
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
		code->operand1 = code->operand1 | 0xf00;  //destroy and replace addresses that are >= than 0x80 into  0xfxx
		FSR[code->operand1] = temp1; //place original value into the new address
	}
}

int check_operand2(Bytecode *code, int value){

	if(code->operand2 > -1 && code->operand2 < 8){
		switch(code->operand2){
			case 0:
				if((value&0x1) == 0)
					return 2;
				else if((value&0x1) != 0)
					return 1;
				
				break;
				
			case 1:
				if((value&0x2) == 0)
					return 2;
				else if((value&0x2) != 0)
					return 1;
				
				break;
				
			case 2:
				if((value&0x4) == 0)
					return 2;
				else if((value&0x4) != 0)
					return 1;
				
				break;
				
			case 3:
				if((value&0x8) == 0)
					return 2;
				else if((value&0x8) != 0)
					return 1;
				
				break;
				
			case 4:
				if((value&0x10) == 0)
					return 2;
				else if((value&0x10) != 0)
					return 1;
				
				break;
				
			case 5:
				if((value&0x20) == 0)
					return 2;
				else if((value&0x20) != 0)
					return 1;
				
				break;
				
			case 6:
				if((value&0x40) == 0)
					return 2;
				else if((value&0x40) != 0)
					return 1;
				
				break;
				
			case 7:
				if((value&0x80) == 0)
					return 2;
				else if((value&0x80) != 0)
					return 1;
				
				break;
				
		}
	}
	
	else 
		Throw(ERR_INVALID_OPERAND);
}