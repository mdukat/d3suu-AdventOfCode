#include <stdio.h>
#include <stdbool.h>

#include "day9.h"
#define DATASIZE 1000

long long int buffer[25];

void push(long long int number);
bool is_sum(long long int number);

int main(){
	// Part 1
	unsigned int datapos = 0;
	// fill buffer
	for(int i = 0; i<25; i++){
		buffer[i] = datain[i];
		datapos++;
	}

	// check
	long long int p1answer;
	for(int i = datapos; i<DATASIZE; i++){
		if(is_sum(datain[i]) == false){
			printf("False number: %lld\n", datain[i]);
			p1answer = datain[i];
			break;
		}
		push(datain[i]);
		datapos++;
	}
	
	// Part 2
	for(int i = 0; i<DATASIZE; i++){
		long long int current = datain[i];
		long long int low = 999999999;
		long long int high = 0;
		for(int j = i+1; j<DATASIZE; j++){
			current+=datain[j];
			if(datain[j] < low)
				low = datain[j];
			if(datain[j] > high)
				high = datain[j];
			if(current > p1answer)
				break;
			if(current == p1answer){
				printf("Part 2: %lld-%lld: %lld; current: %lld\n", low, high, low+high, current);
				return 1;
			}
		}
	}

	return 0;
}

void push(long long int number){
	long long int newbuffer[25];
	for(int i = 1; i<25; i++)
		newbuffer[i-1] = buffer[i];
	newbuffer[24] = number;
	for(int i = 0; i<25; i++)
		buffer[i] = newbuffer[i];
}

bool is_sum(long long int number){
	for(int i = 0; i<25; i++){
		for(int j = 0; j<25; j++){
			if(i == j)
				continue;
			if(buffer[i] + buffer[j] == number)
				return true;
		}
	}
	return false;
}
