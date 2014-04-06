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
#include "SUBLW.h"

unsigned char FSR[0x1000];

/**
// subtract wreg with literal value
// input: bytecode
// return: absoluteAddress +1
**/
int sublw(Bytecode *code){
	unsigned char temp1, temp2, result;
	temp1 = (~FSR[code->operand1])+1;
	temp2 = FSR[WREG];
	FSR[WREG] = temp1 + temp2; //add file with wreg
	result = FSR[WREG];
	check_status(result, temp1, temp2);
	return code->absoluteAddress =+ 1;
}

/**
// check and update status flag
// input: result, temp1, temp2 
// destroy: status flag
**/
void check_status(int result, int temp1, int temp2){
	FSR[STATUS] = check_carry(temp1, temp2) | check_digital_carry(temp1, temp2) | check_zero(result) | check_negative(result) | check_overflow(temp1, temp2);
}

/**
//check and update carry flag
//input: temp1, temp2
//destroy: carry
//return: carry
**/
int check_carry(int temp1, int temp2){
	int carry=0;
	if((temp1/2+1) + (temp2/2+1) >= 0x80){
		carry = 0x01;
		return carry;
	}
	else 
		return carry;
}

/**
//check and update digital carry flag
//input: temp1, temp2
//destroy: digital carry
//return: digital carry
**/
int check_digital_carry(int temp1, int temp2){
	int digital_carry=0;

	if((temp1 & 0x0f) + (temp2 & 0x0f)>= 0x10 ){
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
//input: temp1, temp2
//destroy: overflow
//return: overflow
**/
int check_overflow(int temp1, int temp2){
	int overflow=0, d6_carry=0, d7_carry=0;

	d6_carry = ((temp1&0x7f) + (temp2&0x7f))>>7;
	d7_carry = (temp1+temp2)>>8;
	
	if(d6_carry == 1 && d7_carry == 1){ //d7 carry and d6 carry
		overflow = 0x08;
		return overflow;
	}
	
	else if((d7_carry != 1 && d6_carry == 1)||(d7_carry == 1 && d6_carry != 1)){ //d7 no carry, d6 carry, vice-versa
		overflow = 0x8;
		return overflow;
	}
	
	else 
		return overflow;
}
