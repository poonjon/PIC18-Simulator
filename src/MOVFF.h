#ifndef	__MOVFF_H__
#define	__MOVFF_H__

#define WREG  0xfe8

extern char FSR[];
extern int PC;

void movff(Bytecode *code);

#endif	// __MOVFF_H__