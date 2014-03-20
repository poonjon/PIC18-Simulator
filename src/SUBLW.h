#ifndef	__SUBLW_H__
#define	__SUBLW_H__

#define WREG  0xfe8
#define STATUS 0xfd8 //BIT 4 = N, BIT 3 = OV, BIT 2 = Z, BIT 1 = DC, BIT 0 = C

extern char FSR[];

void sublw(Bytecode *code);
#endif	// __SUBLW_H__