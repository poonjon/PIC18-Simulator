/**
 * Author: Poon Jon
 * Email: poonjon93@gmail.com
 * Date: 29/3/2014
 * Project name: PIC18 simulator
 * Programme: Microelectronics with Embedded Technology
 * Institution: Tunku Abdul Rahman University College
 * Copyright: GPLv3
 */

#ifndef	__SWAPF_H__
#define	__SWAPF_H__

#define WREG  0xfe8
#define BSR   0xfe0

unsigned extern char FSR[];

int swapf(Bytecode *code);

#endif	// __SWAPF_H__