#ifndef	__RLCF_H__
#define	__RLCF_H__

#define WREG  0xfe8
#define BSR   0xfe0
#define STATUS 0xfd8 //BIT 4 = N, BIT 3 = OV, BIT 2 = Z, BIT 1 = DC, BIT 0 = C

unsigned extern char FSR[];
extern int PC;

void rlcf(Bytecode *code);
int check_valid_operands(Bytecode *code);
int operand2_check(Bytecode *code);
int normal_operand2(Bytecode *code);
int default_operand2(Bytecode *code);
int access_destination_operand2(Bytecode *code);
int banked_destination_operand2(Bytecode *code);
void check_operand1_access_range(Bytecode *code);
int check_status(int temp2);
int check_zero(int temp2);
int check_negative(int temp2);
#endif	// __RLCF_H__
