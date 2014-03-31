#ifndef BTFSC_H
#define BTFSC_H

#define WREG  0xfe8
#define BSR   0xfe0

unsigned extern char FSR[];
extern int PC;

void btfsc(Bytecode *code);
int check_valid_operands(Bytecode *code);
int check_operand3(Bytecode *code);
void check_operand1_access_range(Bytecode *code);
int check_operand2(Bytecode *code, int value);

#endif // BTFSC_H
