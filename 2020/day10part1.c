#include <stdio.h>

#include "day10.h"

int sanityin[];
#define SANITYSIZE 31

int main(){
	int device_joltage = 0;
	for(int i = 0; i<DATASIZE; i++){
		if(datain[i] > device_joltage)
			device_joltage = datain[i];
	}
	device_joltage += 3;

#ifdef BADCODE
	// find adapters from lowest to highest
	int current_joltage = 0;
	int jolt_diff[3] = {0,0,0};
	while(current_joltage != device_joltage-3){
		// else, find +1 joltage adapter
		for(int i = 0; i<DATASIZE; i++){
			if(datain[i] == current_joltage+1){
				printf("1-Jolt difference: %d at line %d\n", datain[i], i);
				current_joltage = datain[i];
				jolt_diff[0]++;
				break;
			}
		}
		// else, find +2 joltage adapter
		for(int i = 0; i<DATASIZE; i++){
			if(datain[i] == current_joltage+2){
				printf("2-Jolt difference: %d at line %d\n", datain[i], i);
				current_joltage = datain[i];
				jolt_diff[1]++;
				break;
			}
		}
		// find +3 joltage adapter
		for(int i = 0; i<DATASIZE; i++){
			if(datain[i] == current_joltage+3){
				printf("3-Jolt difference: %d at line %d\n", datain[i], i);
				current_joltage = datain[i];
				jolt_diff[2]++;
				break;
			}
		}
	}

	printf("3-Jolt adapters: %d; 1-Jolt adapters: %d; Multiplied: %d\n", jolt_diff[2], jolt_diff[0], jolt_diff[2]*jolt_diff[0]);
#endif

	// Actually, sorting numbers and checking difference between next one's gives better results
	int adapters_sort[DATASIZE];
	int adapters_index = 0;
	int current_joltage = 0;
	int jolt_diff[3];
	jolt_diff[0] = 0;
	jolt_diff[1] = 0;
	jolt_diff[2] = 0;
	while(current_joltage != device_joltage-3){
		int cont_pass = 0;
		// else, find +1 joltage adapter
		for(int i = 0; i<DATASIZE; i++){
			if(datain[i] == current_joltage+1){
				printf("1-Jolt difference: %d at line %d\n", datain[i], i);
				adapters_sort[adapters_index] = datain[i];
				adapters_index++;
				current_joltage = datain[i];
				jolt_diff[0]++;
				cont_pass = 1;
				break;
			}
		}
		if(cont_pass == 1)
			continue;
		// else, find +2 joltage adapter
		for(int i = 0; i<DATASIZE; i++){
			if(datain[i] == current_joltage+2){
				printf("2-Jolt difference: %d at line %d\n", datain[i], i);
				adapters_sort[adapters_index] = datain[i];
				adapters_index++;
				current_joltage = datain[i];
				jolt_diff[1]++;
				cont_pass = 1;
				break;
			}
		}
		if(cont_pass == 1)
			continue;
		// find +3 joltage adapter
		for(int i = 0; i<DATASIZE; i++){
			if(datain[i] == current_joltage+3){
				printf("3-Jolt difference: %d at line %d\n", datain[i], i);
				adapters_sort[adapters_index] = datain[i];
				adapters_index++;
				current_joltage = datain[i];
				jolt_diff[2]++;
				break;
			}
		}
	}

	// Print table
	for(int i = 0; i<DATASIZE; i++){
		printf("%d\n", adapters_sort[i]);
	}

	// +1 for device itself
	jolt_diff[2]++;
		
	printf("3-Jolt adapters: %d; 1-Jolt adapters: %d; Multiplied: %d\n", jolt_diff[2], jolt_diff[0], jolt_diff[2]*jolt_diff[0]);
		
		
	return 0;
}

int sanityin[] = {28,
33,
18,
42,
31,
14,
46,
20,
48,
47,
24,
23,
49,
45,
19,
38,
39,
11,
1,
32,
25,
35,
8,
17,
7,
9,
4,
2,
34,
10,
3};
