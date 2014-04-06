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

