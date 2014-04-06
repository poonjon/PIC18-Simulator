#include <stdio.h>
#include "CException.h"
#include "Bytecode.h"
#include "TblwtPostDec.h"

unsigned char TABLE[0x200000];
unsigned char FSR[0x1000];

int tblwt_postdec(Bytecode *code){
	int tblptr_h, tblptr_l, tblptr_u;
	int tableAdd;
	
	tblptr_u = FSR[TBLPTRU]<<16;
	tblptr_h = FSR[TBLPTRH]<<8;
	tblptr_l = FSR[TBLPTRL];
	
	tableAdd = tblptr_u + tblptr_h + tblptr_l;
	TABLE[tableAdd] = FSR[TABLAT];
	
	if(tableAdd >= 0x200000)
		Throw(ERR_INVALID_OPERAND);
		
	if(FSR[TBLPTRL] == 0x00 && FSR[TBLPTRH != 0x00]){
		FSR[TBLPTRL]--;
		FSR[TBLPTRH]--;
	}
	
	else if(FSR[TBLPTRH] == 0x00 && FSR[TBLPTRL] == 0x00){
		FSR[TBLPTRU]--;
		FSR[TBLPTRH]--;
		FSR[TBLPTRL]--;
	}
	
	else
		FSR[TBLPTRL]--;
		
	return code->absoluteAddress += 1;
}