#ifndef PUSH_H
#define PUSH_H

#define WREG  0xfe8
#define BSR   0xfe0

unsigned extern char FSR[];
extern int PC;

void push(Bytecode *code);

#endif // PUSH_H
