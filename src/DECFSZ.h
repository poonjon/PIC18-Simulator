#ifndef	__DECFSZ_H__
#define	__DECFSZ_H__

#define WREG  0xfe8
#define BSR   0xfe0

extern char FSR[];
extern int PC;

void decfsz(Bytecode *code);
int check_valid_operands(Bytecode *code);
int operand2_check(Bytecode *code);
int normal_operand2(Bytecode *code);
int default_operand2(Bytecode *code);
int access_destination_operand2(Bytecode *code);
int banked_destination_operand2(Bytecode *code);
int check_operand1_range(Bytecode *code);

#endif	// __DECFSZ_H__