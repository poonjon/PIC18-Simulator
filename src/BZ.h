/**
 * Author: Poon Jon
 * Email: poonjon93@gmail.com
 * Date: 29/3/2014
 * Project name: PIC18 simulator
 * Programme: Microelectronics with Embedded Technology
 * Institution: Tunku Abdul Rahman University College
 * Copyright: GPLv3
 */

#ifndef BZ_H
#define BZ_H

#define WREG  0xfe8
#define BSR   0xfe0
#define STKPTR 0xffc
#define TOSU 0xfff
#define TOSH 0xffe
#define TOSL 0xffd

unsigned extern char FSR[];
unsigned extern int PIC18Stack[];

int bz(Bytecode *code);

#endif // BZ_H
