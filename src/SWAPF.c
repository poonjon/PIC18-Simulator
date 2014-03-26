#include <stdio.h>
#include "CException.h"
#include "Bytecode.h"
#include "SWAPF.h"

unsigned char FSR[0x1000];

void swapf(Bytecode *code){
	int swap, temp1, temp2;
	
	swap = check_valid_operands(code);
	
	switch(swap){
	
		case 1: //normal, access, store in wreg
			temp1 = FSR[code->operand1]; //store fsr value in temp
			temp2 = temp1;
			FSR[WREG] = (temp1<<4)+(temp2>>4); //swap nibble and store in wreg
			break;
			
		case 2:	//normal, access store in file reg
			temp1 = FSR[code->operand1]; //store fsr value in temp
			temp2 = temp1;
			FSR[code->operand1] = (temp1<<4)+(temp2>>4); //swap nibble and store in operand1	
			break;
			
		case 3:	//normal, banked, store in wreg
			temp1 = FSR[code->operand1+(FSR[BSR]<<8)]; //store value into temp
			temp2 = temp1;
			FSR[WREG] = ((temp1<<4)+(temp2>>4)); //swap nibble and place to wreg
			break;
		
		case 4:	//normal, banked, store in file
			temp1 = FSR[code->operand1+(FSR[BSR]<<8)]; //store value into temp
			temp2 = temp1;
			FSR[code->operand1+(FSR[BSR]<<8)] = ((temp1<<4)+(temp2>>4)); //swap nibble and replace value
			break;		
			
		case 5:	//default operand2, access
			temp1 = FSR[code->operand1]; //store fsr value in temp
			temp2 = temp1;
			FSR[code->operand1] = (temp1<<4)+(temp2>>4); //swap nibble and store in operand1
			break;
			
		case 6:	//default operand2, banked
			temp1 = FSR[code->operand1+(FSR[BSR]<<8)]; //store value into temp
			temp2 = temp1;
			FSR[code->operand1+(FSR[BSR]<<8)] = ((temp1<<4)+(temp2>>4)); //swap nibble and replace value
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

	//to check if operand 2 is placed normally
	if(code->operand2 == W || code->operand2 == F || code->operand2 == 1 || code->operand2 == 0){
		return normal_operand2(code);
	}
		
	//if operand 2 is skipped 
	else if((code->operand2 == ACCESS || code->operand2 == BANKED) && code->operand3 == -1){
		return skipped_operand2(code);
	}
	
	//if operand 2 was skipped and there are still values in operand3
	else
		Throw(ERR_INVALID_OPERAND);
}

int normal_operand2(Bytecode *code){
	
	//access bank
	if(code->operand3 == ACCESS || code->operand3 == 0){
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
		check_operand1_range(code);
		return 1;
	}
	
	//destination in file reg
	else if(code->operand2 == F || code->operand2 == 1){
		check_operand1_range(code);
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

int skipped_operand2(Bytecode *code){	
	
	//access bank
	if(code->operand2 == ACCESS && code->operand3 == -1){
		check_operand1_range(code);
		return 5;
	}
	
	//banked
	else if(code->operand2 == BANKED && code->operand3 == -1){
		
		//to check if bsr is in range of 0 to F
		if(FSR[BSR] >= 0x0 && FSR[BSR] <= 0xF)
			return 6;
		
		//invalid bsr range
		else
		Throw(ERR_INVALID_OPERAND);
	}
	
	//invalid operand 2
	else
		Throw(ERR_INVALID_OPERAND);

}

int check_operand1_range(Bytecode *code){

	if(code->operand1 >= 0x80 && code->operand1 <= 0xFF){
		int temp1;
		
		temp1 = FSR[code->operand1]; //store value into temp
		code->operand1 = code->operand1 | 0xf00;  //change addresses that are >= than 0x80 into  0xfxx
		FSR[code->operand1] = temp1; //place original value into the new address
	}
}









