#ifndef	__MOVFF_H__
#define	__MOVFF_H__

#define WREG  0xfe8

unsigned extern char FSR[];

void movff(Bytecode *code);

#endif	// __MOVFF_H__