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
bool sumATable[100];

char* nextTokenPos(char* buffer){
	for(char* i = buffer; i<buffer+strlen(buffer); i++){
		if(*i == ',' || *i == ';')
		return i+2;
	}
	return NULL;
}

char* getToken(char* buffer){
	char* nextToken = nextTokenPos(buffer);
	if(nextToken == NULL)
		return buffer;

	char* token = malloc(nextToken-buffer);
	strncpy(token, buffer, nextToken-buffer-2);
	return token;
}

bool is_token_bigger_than_reality(char* token, int gameID){
	int tokenValue = atoi(token);
	printf("%d\n", tokenValue);
	
	char* color = strchr(token, ' ')+1;

	if(strcmp(color, "red") == 0 && tokenValue > 12)
		sumATable[gameID-1] = true;
	if(strcmp(color, "green") == 0 && tokenValue > 13)
		sumATable[gameID-1] = true;
	if(strcmp(color, "blue") == 0 && tokenValue > 14)
		sumATable[gameID-1] = true;

	return true;
}

void handle_line(char* line){
	printf("%lu -> %s\n", strlen(line), line);

	char* gameIDpre = strchr(line, ' ')+1;
	size_t gameIDlen = strchr(gameIDpre, ':')-gameIDpre;
	char* gameIDstr = malloc(gameIDlen);
	strncpy(gameIDstr, gameIDpre, gameIDlen);
	int gameID = atoi(gameIDstr);
	
	printf("gameID %d\n", gameID);

	char* tokenPos = strstr(line, ": ")+2;
	printf("%s -> \n", getToken(tokenPos));
	is_token_bigger_than_reality(getToken(tokenPos), gameID);
	while(tokenPos = nextTokenPos(tokenPos)){
		printf("%s -> \n", getToken(tokenPos));
		is_token_bigger_than_reality(getToken(tokenPos), gameID);
	}
	printf("\n");
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

	printf("%s\n", input);

	for(int i = 0; i<100; i++){
		sumATable[i] = false;
	}

	char* line = strtok(input, "\n");
	handle_line(line);
	while(line = strtok(NULL, "\n")) {
		handle_line(line);
	}

	for(int i = 0; i<100; i++){
		if(!sumATable[i])
			sumA += i+1;
	}

	printf("sumA = %d\n", sumA);
	printf("sumB = %d\n", sumB);

	return 0;
}
