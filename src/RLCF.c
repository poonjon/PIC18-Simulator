#include <stdio.h>
#include "CException.h"
#include "Bytecode.h"
#include "RLCF.h"

unsigned char FSR[0x1000];
int PC; 

void rlcf(Bytecode *code){
	int status;
	int temp1, temp2, temp3, temp4;

	switch(check_valid_operands(code)){
	
		case 1: //access, store in wreg
			FSR[WREG] = (FSR[code->operand1]<<1)|FSR[STATUS];
			temp2 = FSR[WREG];
			FSR[STATUS] = FSR[code->operand1]>>7; 
			check_status(temp2);
			PC +=2;
			break;
			
		case 2:	//access store in file reg
			temp1 = FSR[code->operand1];
			FSR[code->operand1] = (FSR[code->operand1]<<1)|FSR[STATUS];
			temp2 = FSR[code->operand1];
			FSR[STATUS] = temp1>>7; 
			check_status(temp2);
			PC +=2;
			break;
			
		case 3:	//banked, store in wreg
			FSR[WREG] = (FSR[code->operand1+(FSR[BSR]<<8)]<<1)|FSR[STATUS];
			temp2 = FSR[WREG];
			FSR[STATUS] = FSR[code->operand1+(FSR[BSR]<<8)]>>7; 
			check_status(temp2);
			PC +=2;
			break;
		
		case 4:	//banked, store in file
			temp1 = FSR[code->operand1+(FSR[BSR]<<8)];
			FSR[code->operand1+(FSR[BSR]<<8)] = (FSR[code->operand1+(FSR[BSR]<<8)]<<1)|FSR[STATUS];
			temp2 = FSR[code->operand1+(FSR[BSR]<<8)];
			FSR[STATUS] = temp1>>7; 
			check_status(temp2);
			PC +=2;
			break;
		
	}
	
}

int check_valid_operands(Bytecode *code){
	
	//to check if the values are in range for operand 1 
	if(code->operand1 > -1 && code->operand1 <= 0xFF)
		return operand2_check(code);
	
	//values in operand 1 and 2 are invalid
	else 
		Throw(ERR_INVALID_OPERAND);

}

int operand2_check(Bytecode *code){

	//to check if operand 2 not default
	if(code->operand2 == W || code->operand2 == F || code->operand2 == 1 || code->operand2 == 0){
		return normal_operand2(code);
	}
		
	//default operand2
	else if((code->operand2 == ACCESS || code->operand2 == BANKED) && code->operand3 == -1){
		return default_operand2(code);
	}
	
	//default operand2 and operand3
	else if(code->operand2 == -1 && code->operand3 == -1){
		code->operand2 = F;
		code->operand3 = ACCESS;
		return access_destination_operand2(code);
	}
		
	//if operand 2 was default and there are still values in operand3
	else
		Throw(ERR_INVALID_OPERAND);
}

int normal_operand2(Bytecode *code){
	
	//access bank or default operand3
	if(code->operand3 == ACCESS || code->operand3 == 0 || code->operand3 == -1){
		return access_destination_operand2(code);
	}
		
	//BSR
	else if(code->operand3 == BANKED || code->operand3 == 1){
		return banked_destination_operand2(code);		
	}
	
	//invalid operand3
	else
		Throw(ERR_INVALID_OPERAND);
		
}

int access_destination_operand2(Bytecode *code){
	
	//destination WREG
	if(code->operand2 == W || code->operand2 == 0){
		check_operand1_access_range(code);
		return 1;
	}
	
	//destination in file reg
	else if(code->operand2 == F || code->operand2 == 1){
		check_operand1_access_range(code);
		return 2;
	}
	
	//invalid destination
	else
		Throw(ERR_INVALID_OPERAND);
		
}

int banked_destination_operand2(Bytecode *code){
	
	//destination WREG
	if(code->operand2 == W || code->operand2 == 0){
				
		//to check if bsr is in range of 0 to F
		if(FSR[BSR] > 0x0 && FSR[BSR] <= 0xF)
			return 3;
					
		//invalid bsr range
		else
			Throw(ERR_INVALID_OPERAND);		
		}
				
	//destination file reg
	else if(code->operand2 == F || code->operand2 == 1){
				
		//to check if bsr is in range of 0 to F
		if(FSR[BSR] > 0x0 && FSR[BSR] <= 0xF)
			return 4;
				
		else
			Throw(ERR_INVALID_OPERAND);
	}
		
	//invalid destination
	else
	Throw(ERR_INVALID_OPERAND);
}

int default_operand2(Bytecode *code){	
	
	//access bank
	if(code->operand2 == ACCESS && code->operand3 == -1){
		check_operand1_access_range(code);
		return 2;
	}
	
	//banked
	else if(code->operand2 == BANKED && code->operand3 == -1){
		
		//to check if bsr is in range of 0 to F
		if(FSR[BSR] >= 0x0 && FSR[BSR] <= 0xF)
			return 4;
		
		//invalid bsr range
		else
		Throw(ERR_INVALID_OPERAND);
	}
	
	//invalid operand 2
	else
		Throw(ERR_INVALID_OPERAND);

}

int check_operand1_access_range(Bytecode *code){

	if(code->operand1 >= 0x80 && code->operand1 <= 0xFF){
		int temp1;
		
		temp1 = FSR[code->operand1]; //store value into temp
		code->operand1 = code->operand1 | 0xf00;  //change addresses that are >= than 0x80 into  0xfxx
		FSR[code->operand1] = temp1; //place original value into the new address
	}
}

int check_status(int temp2){
	FSR[STATUS] = check_zero(temp2) | check_negative(temp2) | FSR[STATUS];

}

int check_zero(int temp2){
	int zero=0;
	
	if(temp2 == 0 ){
		zero = 0x4;
		return zero;
	}
	
	return zero;

}

int check_negative(int temp2){
	int negative=0;
	
	if((temp2 & 0x80) !=  0){
		negative = 0x10;
		return negative;
	}
	
	return negative;

}








