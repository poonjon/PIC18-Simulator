/**
 * Author: Poon Jon
 * Email: poonjon93@gmail.com
 * Date: 29/3/2014
 * Project name: PIC18 simulator
 * Programme: Microelectronics with Embedded Technology
 * Institution: Tunku Abdul Rahman University College
 * Copyright: GPLv3
 */

#ifndef	__EXECUTE_H__
#define	__EXECUTE_H__

#define WREG  0xfe8
#define BSR   0xfe0
#define STATUS 0xfd8 //BIT 4 = N, BIT 3 = OV, BIT 2 = Z, BIT 1 = DC, BIT 0 = C

unsigned extern char FSR[];

int check_valid_operands(Bytecode *code);
int operand1_exceeded_range_checks(Bytecode *code);
int operand2_check(Bytecode *code);
int destination_check(Bytecode *code);
int access_destination_operand2(Bytecode *code);
int access_destination_operand2(Bytecode *code);
void check_operand1_access_range(Bytecode *code);
void check_status(int result, int temp1, int temp2, int carry_bit);
int check_carry(int temp1, int temp2, int carry_bit);
int check_digital_carry(int temp1, int temp2, int carry_bit);
int check_zero(int result);
int check_negative(int result);
int check_overflow(int temp1, int temp2, int carry_bit);

#endif	// __EXECUTE_H__