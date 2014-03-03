#ifndef	__SWAPF_H__
#define	__SWAPF_H__

#define WREG  0xfe8
#define BSR   0xfe0

extern char FSR[];

void swapf(Bytecode *code);
#endif	// __SWAPF_H__