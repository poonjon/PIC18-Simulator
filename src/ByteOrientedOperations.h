#ifndef	__BYTEORIENTEDOPERATIONS_H__
#define	__BYTEORIENTEDOPERATIONS_H__

#define WREG  0xfe8

extern char FSR[];

void movff(Bytecode *code);
#endif	// __BYTEORIENTEDOPERATIONS_H__