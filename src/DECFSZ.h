#ifndef	__DECFSZ_H__
#define	__DECFSZ_H__

#define WREG  0xfe8
#define BSR   0xfe0

unsigned extern char FSR[];

int decfsz(Bytecode *code);

#endif	// __DECFSZ_H__