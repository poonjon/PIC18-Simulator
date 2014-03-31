#ifndef	__SWAPF_H__
#define	__SWAPF_H__

#define WREG  0xfe8
#define BSR   0xfe0

unsigned extern char FSR[];
extern int PC;

void swapf(Bytecode *code);
int check_valid_operands(Bytecode *code);
int operand2_check(Bytecode *code);
int normal_operand2(Bytecode *code);
int default_operand2(Bytecode *code);
int access_destination_operand2(Bytecode *code);
int banked_destination_operand2(Bytecode *code);
void check_operand1_range(Bytecode *code);

#endif	// __SWAPF_H__