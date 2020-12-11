#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char* sanitydata[];
#define SANITYSIZE 10

void dataround(char** datain, int datalen, char** tmpdata){
	int datawidth = strlen(datain[0]);
	// tmp data set
	//char* tmpdata[datalen];
	for(int i = 0; i<datalen; i++){
		tmpdata[i] = malloc(datawidth+1); // data + /0
		tmpdata[i][datawidth] = 0x00;
		memset(tmpdata[i], ' ', datawidth+1);
	}
	// print data set
	/*
	for(int i = 0; i<datalen; i++){
		printf("%s\n", datain[i]);
	}
	*/

	/*

	0---> +x
	|
	\/ +y

	*/
	// round
	for(int y = 0; y<datalen; y++){
		for(int x = 0; x<datawidth; x++){
			if(datain[y][x] == '.'){ // Floor
				tmpdata[y][x] = '.';
				continue;
			}
			if(datain[y][x] == 'L'){ // Empty seat
				char microbuffer[3][3] = {
					{'.','.','.'},
					{'.','.','.'},
					{'.','.','.'}};

				microbuffer[1][1] = 'L';
				if(y-1 >= 0)					// top
					microbuffer[0][1] = datain[y-1][x];
				if(y+1 < datalen)				// bottom
					microbuffer[2][1] = datain[y+1][x];
				if(x-1 >= 0)					// left
					microbuffer[1][0] = datain[y][x-1];
				if(x+1 < datawidth)				// right
					microbuffer[1][2] = datain[y][x+1];
				if(y-1 >= 0 && x-1 >= 0)			// top left
					microbuffer[0][0] = datain[y-1][x-1];
				if(y-1 >= 0 && x+1 < datawidth)			// top right
					microbuffer[0][2] = datain[y-1][x+1];
				if(y+1 < datalen && x-1 >= 0)			// bottom left
					microbuffer[2][0] = datain[y+1][x-1];
				if(y+1 < datalen && x+1 < datawidth)		// bottom right
					microbuffer[2][2] = datain[y+1][x+1];

				// printf microbuffer (and check for round)
				bool possible_to_seat = true;
				for(int a = 0; a<3; a++){
					for(int b = 0; b<3; b++){
						//printf("%c", microbuffer[a][b]);
						if(microbuffer[a][b] == '#'){
							possible_to_seat = false;
							break;
						}
					}
					if(possible_to_seat == false)
						break;
					//printf("\n");
				}
				//printf("\n");

				if(possible_to_seat == true){
					tmpdata[y][x] = '#';
					continue;
				}else{
					tmpdata[y][x] = 'L';
					continue;
				}
			}
			if(datain[y][x] == '#'){ // Occupied seat
				char microbuffer[3][3] = {
					{'.','.','.'},
					{'.','.','.'},
					{'.','.','.'}};

				microbuffer[1][1] = 'L';
				if(y-1 >= 0)					// top
					microbuffer[0][1] = datain[y-1][x];
				if(y+1 < datalen)				// bottom
					microbuffer[2][1] = datain[y+1][x];
				if(x-1 >= 0)					// left
					microbuffer[1][0] = datain[y][x-1];
				if(x+1 < datawidth)				// right
					microbuffer[1][2] = datain[y][x+1];
				if(y-1 >= 0 && x-1 >= 0)			// top left
					microbuffer[0][0] = datain[y-1][x-1];
				if(y-1 >= 0 && x+1 < datawidth)			// top right
					microbuffer[0][2] = datain[y-1][x+1];
				if(y+1 < datalen && x-1 >= 0)			// bottom left
					microbuffer[2][0] = datain[y+1][x-1];
				if(y+1 < datalen && x+1 < datawidth)		// bottom right
					microbuffer[2][2] = datain[y+1][x+1];

				// printf microbuffer (and check for round)
				int occupied = 0;
				for(int a = 0; a<3; a++){
					for(int b = 0; b<3; b++){
						//printf("%c", microbuffer[a][b]);
						if(microbuffer[a][b] == '#'){
							occupied++;
						}
					}
				}

				if(occupied >= 4){
					tmpdata[y][x] = 'L';
					continue;
				}else{
					tmpdata[y][x] = '#';
					continue;
				}
			}
		}
	}
	// print tmp data set
	for(int i = 0; i<datalen; i++){
		printf("%s\n", tmpdata[i]);
	}
	printf("\n");
}

int main(){
	printf("TEST: %ld\n", strlen("TEST"));

	char* nextdataA[SANITYSIZE];
	char* nextdataB[SANITYSIZE];
	int a = 1;
	dataround(sanitydata, SANITYSIZE, nextdataA);
	for(int i = 0; i<5; i++){
		if(a == 1){
			dataround(nextdataA, SANITYSIZE, nextdataB);
			a = 0;
		}else{
			dataround(nextdataB, SANITYSIZE, nextdataA);
			a = 1;
		}
		a++;
	}
	return 0;
}

char* sanitydata[] = {
"L.LL.LL.LL",
"LLLLLLL.LL",
"L.L.L..L..",
"LLLL.LL.LL",
"L.LL.LL.LL",
"L.LLLLL.LL",
"..L.L.....",
"LLLLLLLLLL",
"L.LLLLLL.L",
"L.LLLLL.LL"
};
