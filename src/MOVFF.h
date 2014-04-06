/**
 * Author: Poon Jon
 * Email: poonjon93@gmail.com
 * Date: 29/3/2014
 * Project name: PIC18 simulator
 * Programme: Microelectronics with Embedded Technology
 * Institution: Tunku Abdul Rahman University College
 * Copyright: GPLv3
 */


#ifndef	__MOVFF_H__
#define	__MOVFF_H__

#define WREG  0xfe8

extern char FSR[];
extern int PC;

void movff(Bytecode *code);

#endif	// __MOVFF_H__