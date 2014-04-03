#ifndef	__RLCF_H__
#define	__RLCF_H__

#define WREG  0xfe8
#define BSR   0xfe0
#define STATUS 0xfd8 //BIT 4 = N, BIT 3 = OV, BIT 2 = Z, BIT 1 = DC, BIT 0 = C

unsigned extern char FSR[];

int rlcf(Bytecode *code);

#endif	// __RLCF_H__
