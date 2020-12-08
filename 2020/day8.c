#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "day8.h"
#define DATASIZE 623

/*
gcc day8.c -g -D DEBUG -D PART1 -o day8

gcc day8.c -o day8 // Runs PART2 by default, watch out for wrong code
*/

//#define PART1
//#define DEBUG
//#define PRETEST

// Going global
int accumulator = 0;
unsigned int program_pointer = 0;
char was_instruction_executed_once_array[DATASIZE];
char* datacopy[DATASIZE]; // data copy for execute(), see part 2

void nop(){
	was_instruction_executed_once_array[program_pointer] = 1;
	program_pointer += 1;
}

void acc(int arg){
	was_instruction_executed_once_array[program_pointer] = 1;
	accumulator += arg;
	program_pointer += 1;
}

void jmp(int arg){
	//printf("jmp %d\n", arg);
	was_instruction_executed_once_array[program_pointer] = 1;
	program_pointer += arg;
}

int execute(){
	accumulator = 0;
	program_pointer = 0;
	memset(was_instruction_executed_once_array, 0x00, DATASIZE);
	while(1){
		char instruction[4];
		char sign;
		int argument;
		sscanf(datacopy[program_pointer], "%s %c%d", instruction, &sign, &argument);
#ifdef DEBUG
		printf("DEBUG: %s %c %d; current program pointer: %u/623\n", instruction, sign, argument, program_pointer);
#endif
		if(strcmp(instruction, "nop") == 0)
			nop();
		if(strcmp(instruction, "acc") == 0)
			acc(argument * (sign == '+' ? 1 : -1));
		if(strcmp(instruction, "jmp") == 0)
			jmp(argument * (sign == '+' ? 1 : -1));

		if(was_instruction_executed_once_array[program_pointer] == 1)
			return -1; // looped, exit
		if(program_pointer == DATASIZE)
			return 0; // executed properly
		if(program_pointer > DATASIZE)
			return -2; // overjumped, exit
	}
}

int main(){
#ifdef PART1
	memset(was_instruction_executed_once_array, 0x00, DATASIZE);
	while(was_instruction_executed_once_array[program_pointer] != 1){
		char instruction[4];
		char sign;
		int argument;
		sscanf(datain[program_pointer], "%s %c%d", instruction, &sign, &argument);
#ifdef DEBUG
		printf("DEBUG: %s %c %d; current program pointer: %u/623\n", instruction, sign, argument, program_pointer);
#endif
#ifdef PRETEST
		program_pointer++;
#endif
		if(strcmp(instruction, "nop") == 0)
			nop();
		if(strcmp(instruction, "acc") == 0)
			acc(argument * (sign == '+' ? 1 : -1));
		if(strcmp(instruction, "jmp") == 0)
			jmp(argument * (sign == '+' ? 1 : -1));
	}
	printf("Program looped at instruction %u, state of accumulator: %d\n", program_pointer, accumulator);
#else // part 2
#ifdef PART2_BADCODE
	// part 2.1 - change nop, execute, repeat
	// find all nops
	unsigned int nops[DATASIZE];
	int nops_n = 0;
	memset(nops, 0x00, DATASIZE*sizeof(unsigned int));
	for(int i = 0; i<DATASIZE; i++){
		char instruction[4];
		sscanf(datain[i], "%s %c%d", instruction, (char*)NULL, (int*)NULL);
		if(strcmp(instruction, "nop") == 0){
			nops[i] = 1;
			nops_n++;
		}
	}
	// print how many nops there are
	printf("nops_n: %d\n", nops_n);
	// for every nop, change one to jmp and execute
	unsigned long pass = 0;
	while(nops_n != 0){
		program_pointer = 0;
		accumulator = 0;
		// basically part 1
		memset(was_instruction_executed_once_array, 0x00, DATASIZE);
		while(was_instruction_executed_once_array[program_pointer] != 1){
			char instruction[4];
			char sign;
			int argument;
			sscanf(datain[program_pointer], "%s %c%d", instruction, &sign, &argument);
#ifdef DEBUG
			printf("DEBUG: %s %c %d; current program pointer: %u/623\n", instruction, sign, argument, program_pointer);
#endif
			if(strcmp(instruction, "nop") == 0){
				for(int i = 0; i<DATASIZE; i++){
					if(i == program_pointer && nops[i] == 1){
						nops[i] = 0;
						strcpy(instruction, "jmp");
						break;
					}else{
						nop();
						break;
					}
				}
			}
			if(strcmp(instruction, "acc") == 0)
				acc(argument * (sign == '+' ? 1 : -1));
			if(strcmp(instruction, "jmp") == 0)
				jmp(argument * (sign == '+' ? 1 : -1));
			if(program_pointer == DATASIZE)
				break;
		}
		if(program_pointer == DATASIZE){
			printf("Program completed! State of accumulator: %d\n", accumulator);
			break;
		}else{
			//printf("Program looped at instruction %u, state of accumulator: %d\n", program_pointer, accumulator);
		}
		if(program_pointer >= DATASIZE){
			printf("Program jumped over its size\n");
		}
		printf("pass: %lu\n", pass);
		pass++;
		nops_n--;
	}

	// part 2.2 - change jmp, execute, repeat
	// find all jmps
	unsigned int jmps[DATASIZE];
	int jmps_n = 0;
	memset(jmps, 0x00, DATASIZE*sizeof(unsigned int));
	for(int i = 0; i<DATASIZE; i++){
		char instruction[4];
		sscanf(datain[i], "%s %c%d", instruction, (char*)NULL, (int*)NULL);
		if(strcmp(instruction, "jmp") == 0){
			jmps[i] = 1;
			jmps_n++;
		}
	}
	// print how many jmps there are
	printf("jmps_n: %d\n", jmps_n);
	// for every jmp, change one to nop and execute
	pass = 0;
	while(jmps_n != 0){
		program_pointer = 0;
		accumulator = 0;
		// basically part 1
		memset(was_instruction_executed_once_array, 0x00, DATASIZE);
		while(was_instruction_executed_once_array[program_pointer] != 1){
			char instruction[4];
			char sign;
			int argument;
			sscanf(datain[program_pointer], "%s %c%d", instruction, &sign, &argument);
#ifdef DEBUG
			printf("DEBUG: %s %c %d; current program pointer: %u/623\n", instruction, sign, argument, program_pointer);
#endif
			//if(strcmp(instruction, "nop") == 0){
			if(strcmp(instruction, "jmp") == 0){
				for(int i = 0; i<DATASIZE; i++){
					if(i == program_pointer && jmps[i] == 1){
						jmps[i] = 0;
						strcpy(instruction, "nop");
						break;
					}else{
						jmp(argument * (sign == '+' ? 1 : -1));
						break;
					}
				}
			}
			if(strcmp(instruction, "acc") == 0)
				acc(argument * (sign == '+' ? 1 : -1));
			//if(strcmp(instruction, "jmp") == 0)
			//	jmp(argument * (sign == '+' ? 1 : -1));
			if(strcmp(instruction, "nop") == 0)
				nop();
			if(program_pointer == DATASIZE)
				break;
		}
		if(program_pointer == DATASIZE){
			printf("Program completed! State of accumulator: %d\n", accumulator);
			break;
		}else{
			//printf("Program looped at instruction %u, state of accumulator: %d\n", program_pointer, accumulator);
		}
		if(program_pointer >= DATASIZE){
			printf("Program jumped over its size\n");
		}
		printf("pass: %lu\n", pass);
		pass++;
		jmps_n--;
	}
#endif
	// Part 2
	// Create full map of nops and jmps
	char jmps[DATASIZE];
	char nops[DATASIZE];
	int jmps_n = 0, nops_n = 0;
	memset(jmps, 0x00, DATASIZE);
	memset(nops, 0x00, DATASIZE);
	for(int i = 0; i<DATASIZE; i++){
		if(datain[i][0] == 'j'){ //strcmp "jmp" > 0 returns over 300 lines (?)
			jmps[i] = 1;
			jmps_n++;
#ifdef DEBUG
			printf("DEBUG: jmp at %d\n", i);
#endif
		}
		if(strcmp(datain[i], "nop") > 0){
			nops[i] = 1;
			nops_n++;
		}
	}

	// Print map
	printf("jmps:\n");
	for(int i = 0; i<DATASIZE; i++)
		printf("%d", jmps[i]);
	printf("\nnops:\n");
	for(int i = 0; i<DATASIZE; i++)
		printf("%d", nops[i]);
	printf("\njmps: %d; nops: %d\n", jmps_n, nops_n);

	// Create data copy
	// char* datacopy[DATASIZE]; // <- global for execute()
	for(int i = 0; i<DATASIZE; i++){
		datacopy[i] = malloc(20);
		memset(datacopy[i], 0x00, 20);
		strcpy(datacopy[i], datain[i]);
	}

	// Execute for each changed jmps to nops
	for(int i = 0; i<DATASIZE; i++){
		// Change jmp to nop
		if(jmps[i] == 1){
			datacopy[i][0] = 'n';
			datacopy[i][1] = 'o';
			datacopy[i][2] = 'p';
		}else{
			continue;
		}
		// Execute
		if(execute() < 0){
			printf("Execution error, going to next iteration\n");
		}else{
			printf("Execution OK, wrong jmp, accumulator: %d\n", accumulator);
			return 0;
		}
		// Change back to jmp
		if(jmps[i] == 1){
			datacopy[i][0] = 'j';
			datacopy[i][1] = 'm';
			datacopy[i][2] = 'p';
			jmps[i] = 0;
		}
	}

	// Execute for each changed nops to jmps
	// WARNING! In my case, one jmp was wrong, this section is untested.
	for(int i = 0; i<DATASIZE; i++){
		// Change nop to jmp
		if(nops[i] == 1){
			datacopy[i][0] = 'j';
			datacopy[i][1] = 'm';
			datacopy[i][2] = 'p';
		}else{
			continue;
		}
		// Execute
		if(execute() < 0){
			printf("Execution error, going to next iteration\n");
		}else{
			printf("Execution OK, wrong nop, accumulator: %d\n", accumulator);
			return 0;
		}
		// Change back to nop
		if(nops[i] == 1){
			datacopy[i][0] = 'n';
			datacopy[i][1] = 'o';
			datacopy[i][2] = 'p';
			nops[i] = 0;
		}
	}

#endif
	return 0;
}
