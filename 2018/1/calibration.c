#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	FILE *calibration;

	calibration = fopen("./input.txt", "r");
	unsigned char buffer[20];
	int index = 0;
	int microbuffer = 0;
	unsigned char buffer_b[19];

	int calibration_value = 0;
	struct Line{
		unsigned char sign;
		int value;
	} line;

	while(1){
		// clear buffers
		index = 0;
		for(int i = 0; i<20; i++){
			buffer[i] = '\0';
		};

		// read line to buffer
		while(1){
			microbuffer = fgetc(calibration);
			if(microbuffer == (int)'\n'){
				break;
			}else if(microbuffer == EOF){
				buffer[0] = '\0';
				break;
			}else{
				buffer[index] = (unsigned char)microbuffer;
				index++;
			}
		}

		// parse line
		line.sign = buffer[0];
		line.value = atoi(&buffer[1]);

		// make things on calibration_value
		if(line.sign == '+'){
			calibration_value += line.value;
		}else if(line.sign == '-'){
			calibration_value -= line.value;
		}
		
		printf("Debug: %c, %i, %i\n", line.sign, line.value, calibration_value);
		if(microbuffer == EOF){
			break;
		}
	}

	printf("Final value: %i\n", calibration_value);
	return 0;
}
