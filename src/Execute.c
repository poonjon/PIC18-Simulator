/**
 * Author: Poon Jon
 * Email: poonjon93@gmail.com
 * Date: 29/3/2014
 * Project name: PIC18 simulator
 * Programme: Microelectronics with Embedded Technology
 * Institution: Tunku Abdul Rahman University College
 * Copyright: GPLv3
 */

#include <stdio.h>
#include "CException.h"
#include "Bytecode.h"
#include "Execute.h"

int temp1; 

/**
// check range of operand 1
// Input: bytecode
// Return: operand2_check if operand 1 is in between 0x00 and 0x7F
// Throw: ERR_INVALID_OPERAND if operand 1 is not in valid range
**/
int check_valid_operands(Bytecode *code){
	
	if(code->operand1 >= 0x0 && code->operand1 < 0x80)
		return operand2_check(code);	
	
	else if(code->operand1 >= 0x80 && code->operand1 < 0xfff)
		return operand1_exceeded_range_checks(code);
	
	else
		Throw(ERR_INVALID_OPERAND);
}

/**
// appropriate checks for operand 1 range that exceeds 0x80
// Input: bytecode
//
// if operand 1 is in between 0x80 to 0xff
// destroy: operand2 and operand3
// return: operand2_check
//
// if operand 1 is in between 0xf80 to 0xfff
// destroy: operand1, operand2 and operand3
// return: operand2_check
//
// if operand 1 is in between 0x100 to 0xf80
// destroy: operand1, operand2 and operand3
// return: operand2_check
**/
int operand1_exceeded_range_checks(Bytecode *code){
	
	if(code->operand1 >= 0x80 && code->operand1 <= 0xff){ //check if code operand1 is access sfr range
		
		if(code->operand3 == -1){ //if operand3 is default, check operand2
			
			if(code->operand2 == ACCESS){
				code->operand2 = F;	//destroy operand2, default F
				code->operand3 = ACCESS; //destroy operand3, replace with entered operand2
				return operand2_check(code);
			}
			
			else if(code->operand2 == BANKED || code->operand2 == -1){
				code->operand2 = F; //destroy operand2, default F
				code->operand3 = BANKED; //destroy operand3, replace with entered operand2
				return operand2_check(code);
			}
			
			else if(code->operand2 == W || code->operand2 == F || code->operand2 == 1 || code->operand2 == 0){
				code->operand3 = ACCESS; //destroy operand3, go access
				return operand2_check(code);
			}
			
			else
				Throw(ERR_INVALID_OPERAND);
		}
		
		else if(code->operand3 == ACCESS || code->operand3 == 0) //if operand3 is access, stay access
			return operand2_check(code);
		
		else if(code->operand3 == BANKED || code->operand3 == 1) //if operand3 is banked, destroy fsr, use bsr value
			return operand2_check(code);
		
		else
			Throw(ERR_INVALID_OPERAND);
	}
	
	else if(code->operand1 >= 0xf80 && code->operand1 <= 0xfff){ //check if code operand1 is sfr
		
		if(code->operand3 == -1){ //check if operand3 is default, check operand 2
			
			if(code->operand2 == ACCESS || code->operand2 == -1){ //destroy operand2 and 3, use sfr
				code->operand2 = F;
				code->operand3 = ACCESS;
				return operand2_check(code);
			}
			
			else if(code->operand2 == BANKED){ //destroy operand1,2 and 3, use bsr value
				temp1 = FSR[code->operand1];
				code->operand1 = ((code->operand1)&0x0ff)+(FSR[BSR]<<8);
				FSR[code->operand1] = temp1;
				code->operand1 = (code->operand1)&0x0ff;
				code->operand2 = F;
				code->operand3 = BANKED;
				return operand2_check(code);
			}
			
			else if(code->operand2 == W || code->operand2 == F || code->operand2 == 1 || code->operand2 == 0){ //destroy operand3, access
				code->operand3 = ACCESS; //destroy operand3, go access
				return operand2_check(code);
			}
			
			else
				Throw(ERR_INVALID_OPERAND);
		}
		
		else if(code->operand3 == ACCESS || code->operand3 == 0) //if operand3 is access, stay access
			return operand2_check(code);
		
		else if(code->operand3 == BANKED || code->operand3 == 1){ //if operand3 is banked, destroy fsr, use bsr value
			temp1 = FSR[code->operand1];
			code->operand1 = ((code->operand1)&0x0ff)+(FSR[BSR]<<8);
			FSR[code->operand1] = temp1;
			code->operand1 = (code->operand1)&0x0ff;
			return operand2_check(code);
		}
		
		else
			Throw(ERR_INVALID_OPERAND);
	}

	else if(code->operand1 >= 0x100 && code->operand1 < 0xf80 ){ // check if code operand1 is not in sfr range but exceed 0xff
		
		if(code->operand3 == -1){ // if operand3 is set to default
			
			if(code->operand2 == ACCESS){ //destroy operand1,2 and 3
				temp1 = FSR[code->operand1];
				code->operand1 = (code->operand1)&0x0ff;
				FSR[code->operand1] = temp1;
				code->operand2 = F;
				code->operand3 = ACCESS;
				return operand2_check(code);
			}
			
			else if(code->operand2 == BANKED || code->operand2 == -1){ //destroy operand1,2 and 3
				temp1 = FSR[code->operand1];
				code->operand1 = ((code->operand1)&0x0ff)+(FSR[BSR]<<8);
				FSR[code->operand1] = temp1;
				code->operand1 = (code->operand1)&0x0ff;
				code->operand2 = F;
				code->operand3 = BANKED;
				return operand2_check(code);
			}
					
			else if(code->operand2 == W || code->operand2 == F || code->operand2 == 1 || code->operand2 == 0){ //destroy operand1 and 3
				temp1 = FSR[code->operand1]; //destroy operand1
				code->operand1 = (code->operand1)&0x0ff;
				FSR[code->operand1] = temp1; 
				code->operand3 = BANKED; //destroy operand3, go banked
				return operand2_check(code);
			}
			
			else
				Throw(ERR_INVALID_OPERAND);
		}
		
		else if(code->operand3 == BANKED || code->operand3 == 1){ // destroy msb
			temp1 = FSR[code->operand1];
			code->operand1 = ((code->operand1)&0x0ff)+(FSR[BSR]<<8);
			FSR[code->operand1] = temp1;
			code->operand1 = (code->operand1)&0x0ff;
			return operand2_check(code);
		}
		
		else if(code->operand3 == ACCESS || code->operand3 == 0){ //destroy msb
			temp1 = FSR[code->operand1];
			code->operand1 = (code->operand1)&0x0ff;
			FSR[code->operand1] = temp1;
			return operand2_check(code);
		}
		
		else
			Throw(ERR_INVALID_OPERAND);
	}
	
	else 
		Throw(ERR_INVALID_OPERAND);
}

/**
// check operand 2 values
// Input: bytecode
//
// if operand 2 is F, W, 1 or 0
// return: destination_check
//
// if operand 2 is ACCESS or -1 and operand3 is -1
// destroy: operand 2 and operand 3
// return destination_check
//
// if operand 2 is BANKED and operand 3 is -1
// destroy: operand 2 and operand 3
// return destination_check
**/
int operand2_check(Bytecode *code){

	//not default
	if(code->operand2 == W || code->operand2 == F || code->operand2 == 1 || code->operand2 == 0)
		return destination_check(code);
		
	//default operand2, access
	else if((code->operand2 == ACCESS || code->operand2 == -1) && code->operand3 == -1){
		code->operand2 = F;
		code->operand3 = ACCESS;
		return destination_check(code);
	}
		
	//default operand2, banked
	else if(code->operand2 == BANKED && code->operand3 == -1){
		code->operand2 = F;
		code->operand3 = BANKED;
		return destination_check(code);
	}
	
	//if operand 2 was default and there are still values in operand3
	else
		Throw(ERR_INVALID_OPERAND);
}

/**
// check if operand 3 is valid and the return it to either access or banked
// input: bytecode

// if operand 3 is access
// return: access_destination_operand2

// if operand 3 is banked
// return: banked_destination_operand2
**/
int destination_check(Bytecode *code){
	
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

/**
// check where the value is suppose to be saved for access 
// input: bytecode

// if operand 2 is W or 0
// return: 1 

// if operand 2 is F or 1
// return: 2 
**/
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

/**
// check where the value is suppose to be saved for banked and check if bsr is <15
// input: bytecode

// if operand 2 is W or 0
// return: 1 

// if operand 2 is F or 1
// return: 2 
**/
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
		if(FSR[BSR] >= 0x0 && FSR[BSR] <= 0xF)
			return 4;
				
		else
			Throw(ERR_INVALID_OPERAND);
	}
		
	//invalid destination
	else
	Throw(ERR_INVALID_OPERAND);
}

/**
//check if operand 1 is in between 0x80 to 0xff and operand 3 is access
// input: bytecode
// destroy: operand 1
**/
void check_operand1_access_range(Bytecode *code){

	if(code->operand1 >= 0x80 && code->operand1 <= 0xFF && (code->operand3 == ACCESS || code->operand3 == 0) ){
		int temp1;
		
		temp1 = FSR[code->operand1]; //store value into temp
		code->operand1 = (code->operand1) | 0xf00;  //destroy and replace addresses that are >= than 0x80 into  0xfxx
		FSR[code->operand1] = temp1; //place original value into the new address
	}
}

/**
// check and update status flag
// input: result, temp1, temp2 and carry_bit
// destroy: status flag
**/
void check_status(int result, int temp1, int temp2, int carry_bit){
	FSR[STATUS] = check_carry(temp1, temp2, carry_bit) | check_digital_carry(temp1, temp2, carry_bit) | check_zero(result) | check_negative(result) | check_overflow(temp1, temp2, carry_bit);
}

/**
//check and update carry flag
//input: temp1, temp2 and carry_bit
//destroy: carry
//return: carry
**/
int check_carry(int temp1, int temp2, int carry_bit){
	int carry=0;
	if(((temp1/2+1) + (temp2/2+1) + (carry_bit/2+1))-1 >= 0x80){
		carry = 0x01;
		return carry;
	}
	else 
		return carry;
}

/**
//check and update digital carry flag
//input: temp1, temp2 and carry_bit
//destroy: digital carry
//return: digital carry
**/
int check_digital_carry(int temp1, int temp2, int carry_bit){
	int digital_carry=0;

	if((temp1 & 0x0f) + (temp2 & 0x0f) + (carry_bit & 0x0f) >= 0x10 ){
		digital_carry = 0x02;
		return digital_carry;
	}
	else 
		return digital_carry;
}

/**
//check and update zero flag
//input: result
//destroy: zero
//return: zero
**/
int check_zero(int result){
	int zero=0;

	if(result == 0){
		zero = 0x04;
		return zero;
	}
	else 
		return zero;
}

/**
//check and update negative flag
//input: result
//destroy: negative
//return: negative
**/
int check_negative(int result){
	int negative=0;
	
	if((result & 0x80) != 0){
		negative = 0x10;
		return negative;
	}
	else 
		return negative;
}

/**
//check and update overflow flag
//input: temp1, temp2 and carry_bit
//destroy: overflow
//return: overflow
**/
int check_overflow(int temp1, int temp2, int carry_bit){
	int overflow=0, d6_carry=0, d7_carry=0;

	d6_carry = ((temp1&0x7f) + (temp2&0x7f) + carry_bit)>>7;
	d7_carry = (temp1+temp2+carry_bit)>>8;
	
	if(d6_carry == 1 && d7_carry == 1){ //d7 carry and d6 carry
		overflow = 0x0;
		return overflow;
	}
	
	else if((d7_carry != 1 && d6_carry == 1)||(d7_carry == 1 && d6_carry != 1)){ //d7 no carry, d6 carry, vice-versa
		overflow = 0x8;
		return overflow;
	}
	
	else 
		return overflow;
}
