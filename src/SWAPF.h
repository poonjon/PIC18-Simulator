#ifndef	__SWAPF_H__
#define	__SWAPF_H__

#define WREG  0xfe8
#define BSR   0xfe0

unsigned extern char FSR[];

int swapf(Bytecode *code);

#endif	// __SWAPF_H__