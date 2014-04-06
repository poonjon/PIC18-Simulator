#ifndef BTFSC_H
#define BTFSC_H

#define WREG  0xfe8
#define BSR   0xfe0

unsigned extern char FSR[];

int btfsc(Bytecode *code);

#endif // BTFSC_H
