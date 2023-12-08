#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

int sumA = 0;
int sumB = 0;

bool is_text_digit(char* charPointer){
	char* digits[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	for(int i = 0; i<9; i++){
		//printf("%s\n", digits[i]);
		if(strncmp(charPointer, digits[i], strlen(digits[i])) == 0)
			return true;
	}

	return false;
}

int text_digit(char* charPointer){
	char* digits[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	for(int i = 0; i<9; i++){
		//printf("%s\n", digits[i]);
		if(strncmp(charPointer, digits[i], strlen(digits[i])) == 0)
			return i+1;
	}

	return 0;
}

void handle_line(char* line){
	printf("%lu -> %s\n", strlen(line), line);

	char* digit = malloc(3);
	digit[2] = '\0';

	for (int i = 0; i<strlen(line); i++) {
		if(line[i] >= '0' && line[i] <= '9'){
			digit[0] = line[i];
			break;
		}
	}

	for (int i = strlen(line); i>=0; i--) {
		if(line[i] >= '0' && line[i] <= '9'){
			digit[1] = line[i];
			break;
		}
	}

	printf("%s\n", digit);
	int digitInt = atoi(digit);
	printf("%d\n", digitInt);

	sumA += digitInt;

// part 2
	int digitB[2];

	for (int i = 0; i<strlen(line); i++) {
		if(line[i] >= '0' && line[i] <= '9'){
			digitB[0] = line[i]-48;
			break;
		}
		if(is_text_digit(line+i)){
			digitB[0] = text_digit(line+i);
			break;
		}
	}

	for (int i = strlen(line); i>=0; i--) {
		if(line[i] >= '0' && line[i] <= '9'){
			digitB[1] = line[i]-48;
			break;
		}
		if(is_text_digit(line+i)){
			digitB[1] = text_digit(line+i);
			break;
		}
	}

	sumB += digitB[0] * 10 + digitB[1];
}

int main() {
	int fd = open("input.txt", O_RDONLY);

	char buffer[1024];
	char* input = NULL;
	size_t inputSize = 0;
	size_t readSize = 0;

	while(readSize = read(fd, buffer, 1024)){
		input = realloc(input, inputSize+readSize);
		memcpy(input+inputSize, buffer, readSize);
		inputSize += readSize;
	}

	/*
	input = realloc(input, inputSize+1);
	*(input+inputSize+1) = '\0';
	*/

	printf("%s\n", input);

	char* line = strtok(input, "\n");
	handle_line(line);
	while(line = strtok(NULL, "\n")) {
		handle_line(line);
	}

	printf("sumA = %d\n", sumA);

	printf("%d\n", is_text_digit("one"));
	printf("%d\n", is_text_digit("djsiao"));

	printf("sumB = %d\n", sumB);

	return 0;
}
