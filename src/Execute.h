#ifndef	__EXECUTE_H__
#define	__EXECUTE_H__

#define WREG  0xfe8
#define BSR   0xfe0
#define STATUS 0xfd8 //BIT 4 = N, BIT 3 = OV, BIT 2 = Z, BIT 1 = DC, BIT 0 = C

unsigned extern char FSR[];
extern int PC;

int check_valid_operands(Bytecode *code);
int operand2_check(Bytecode *code);
int normal_operand2(Bytecode *code);
int default_operand2(Bytecode *code);
int access_destination_operand2(Bytecode *code);
int banked_destination_operand2(Bytecode *code);
void check_operand1_access_range(Bytecode *code);
void check_status(int temp3, int temp1, int temp2, int temp4);
int check_carry(int temp1, int temp2, int temp4);
int check_digital_carry(int temp1, int temp2, int temp4); 
int check_zero(int temp3);
int check_negative(int temp3);
int check_overflow(int temp1, int temp2, int temp4);

#endif	// __EXECUTE_H__