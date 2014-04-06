/**
 * Author: Poon Jon
 * Email: poonjon93@gmail.com
 * Date: 29/3/2014
 * Project name: PIC18 simulator
 * Programme: Microelectronics with Embedded Technology
 * Institution: Tunku Abdul Rahman University College
 * Copyright: GPLv3
 */

#ifndef	__SUBLW_H__
#define	__SUBLW_H__

#define WREG  0xfe8
#define STATUS 0xfd8 //BIT 4 = N, BIT 3 = OV, BIT 2 = Z, BIT 1 = DC, BIT 0 = C

unsigned extern char FSR[];

int sublw(Bytecode *code);
void check_status(int result, int temp1, int temp2);
int check_carry(int temp1, int temp2);
int check_digital_carry(int temp1, int temp2); 
int check_zero(int result);
int check_negative(int result);
int check_overflow(int temp1, int temp2);

#endif	// __SUBLW_H__