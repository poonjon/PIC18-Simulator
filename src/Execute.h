#ifndef	__EXECUTE_H__
#define	__EXECUTE_H__

#define WREG  0xfe8
#define BSR   0xfe0
#define STATUS 0xfd8 //BIT 4 = N, BIT 3 = OV, BIT 2 = Z, BIT 1 = DC, BIT 0 = C

unsigned extern char FSR[];

int check_valid_operands(Bytecode *code);
int operand1_exceeded_range_checks(Bytecode *code);
int check_operand3(Bytecode *code);
void check_operand1_access_range(Bytecode *code);
int check_operand2(Bytecode *code, int value);

#endif	// __EXECUTE_H__