#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	FILE *checksum;

	checksum = fopen("./input.txt", "r");
	unsigned char buffer[28]; // ID + '\n' + '\0'
	int index = 0;
	int intBuffer = 0;

	const int asciiPointer = (int)'a'; // pointer to 'a' in ascii table
	int chars[26];	// ID's are build from 26 lower-case chars
			// This array gets how many chars are repeated

	int threes = 0;
	int twos = 0;

	while(1){
		index = 0; // clear buffers
		for(int i = 0; i<28; i++){
			buffer[i] = '\0';
		}
		for(int i = 0; i<26; i++){
			chars[i] = 0;
		}
		
		// write line to buffer
		while(1){
			//buffer[index] = fgetc(checksum);
			intBuffer = fgetc(checksum);
			//printf("%i\n", intBuffer); // debug
			//buffer[index] = (unsigned char)intBuffer;
			if(intBuffer == (int)'\n'){
				break;
			}else if(intBuffer == EOF){
				buffer[0] = '\0';
				break;
			}else{
				buffer[index] = (unsigned char)intBuffer;
				index++;
			}
		}

		// work on buffer
		for(int i = 0; i<26; i++){
			chars[(int)buffer[i] - asciiPointer] += 1;
		}
		
		for(int i = 0; i<26; i++){ // loop for 3's
			if(chars[i] == 3){
				threes += 1;
				break;
			}
		}
		for(int i = 0; i<26; i++){ // loop for 2's
			if(chars[i] == 2){
				twos += 1;
				break;
			}
		}
		if(intBuffer == EOF){
			break;
		}
	}

	printf("Result checksum: %i\n", threes*twos);
	return 0;
}
