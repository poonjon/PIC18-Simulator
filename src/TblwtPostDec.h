/**
 * Author: Poon Jon
 * Email: poonjon93@gmail.com
 * Date: 29/3/2014
 * Project name: PIC18 simulator
 * Programme: Microelectronics with Embedded Technology
 * Institution: Tunku Abdul Rahman University College
 * Copyright: GPLv3
 */

#ifndef TblwtPostDec_H
#define TblwtPostDec_H

#define TBLPTRU	0xFF8
#define TBLPTRH	0xFF7
#define TBLPTRL	0xFF6
#define TABLAT	0xFF5

unsigned extern char TABLE[];
unsigned extern char FSR[];

int tblwt_postdec(Bytecode *code);

#endif // TblwtPostDec_H

