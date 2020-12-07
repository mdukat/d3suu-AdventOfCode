// echo "This day is failed!"; gcc day7.c -o day7; ./day7 | sort | sed 's/ ->.*//' | awk '!seen[$0]++' | wc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "day7.h"

#define SANITYSIZE 9
#define DATASIZE 594
char* datasanity[];
struct bag;

struct bag {
	char* type;
	char* color;
	int n_childs;
	struct bag* childs[DATASIZE];
};
typedef struct bag bag_t;

//bag_t sanitybags[SANITYSIZE];
bag_t databags[DATASIZE];

int main(){
	// part 1
	// first pass, create bags without childs
	for(int i = 0; i<DATASIZE; i++){
		char* type = malloc(20);
		char* color = malloc(20);
		char* n_childs = malloc(3);
		sscanf(datain[i], "%s %s bags contain %s", type, color, n_childs);
		databags[i].type = type;
		databags[i].color = color;
		if(n_childs[0] == 'n'){
			databags[i].n_childs = 0;
		}else{
			// check for ','
			int commas = 0;
			for(int j = 0; j<strlen(datain[i]); j++){
				if(datain[i][j] == ',')
					commas++;
			}
			databags[i].n_childs = commas+1;
		}
	}

	// datacheck bags
#ifdef COOLOUTPUT
	for(int i = 0; i<DATASIZE; i++){
		printf("%s %s %d\n", databags[i].type, databags[i].color, databags[i].n_childs);
	}
#endif

	// second pass, link childs to parents
	for(int i = 0; i<DATASIZE; i++){
		// find all childs, and link them
		char* buffer;
		for(int j = 0; j<databags[i].n_childs; j++){
			// first one is after word "contain"
			if(j == 0){
				buffer = strstr(datain[i], "contain") + 8;
				//printf("DEBUG: %s\n", buffer);
				char* type = malloc(20);
				char* color = malloc(20);
				int nothing;
				sscanf(buffer, "%d %s %s bag", &nothing, type, color);
				// find this bag in array
				for(int k = 0; k<DATASIZE; k++){
					if(strcmp(databags[k].type, type) == 0 && strcmp(databags[k].color, color) == 0)
						databags[i].childs[j] = &databags[k];
				}
			}else{
				buffer = strchr(buffer, ',') + 1;
				char* type = malloc(20);
				char* color = malloc(20);
				int nothing;
				sscanf(buffer, "%d %s %s bag", &nothing, type, color);
				// find this bag in array
				for(int k = 0; k<DATASIZE; k++){
					//printf("DEBUG: %s = %s, %s = %s\n", databags[k].type, type, databags[k].color, color);
					if(strcmp(databags[k].type, type) == 0 && strcmp(databags[k].color, color) == 0)
						databags[i].childs[j] = &(databags[k]);
				}
			}
		}
	}

	// second and half pass, print debug info
#ifdef COOLOUTPUT
	for(int i = 0; i<DATASIZE; i++){
		printf("%s %s ->\n", databags[i].type, databags[i].color);
		for(int j = 0; j<databags[i].n_childs; j++){
			printf("\t%s %s\n", databags[i].childs[j]->type, databags[i].childs[j]->color);
		}
	}
#endif

	// third pass, check which ones contain 'shiny gold' directly
	bag_t* direct_shiny[DATASIZE];
	int direct_i = 0;
	for(int i = 0; i<DATASIZE; i++){
		for(int j = 0; j<databags[i].n_childs; j++){
			if(strcmp(databags[i].childs[j]->type, "shiny") == 0 && strcmp(databags[i].childs[j]->color, "gold") == 0){
				direct_shiny[direct_i] = &(databags[i]);
				direct_i++;
			}
		}
	}

	// third and half pass, print debug info
	for(int i = 0; i<direct_i; i++){
		printf("%s %s -> direct \"shiny gold\"\n", direct_shiny[i]->type, direct_shiny[i]->color);
	}

	// fourth pass, find all indirect bags
	bag_t* indirect_shiny[DATASIZE];
	int indirect_i = 0;
	int break_pass = 0;
	for(int i = 0; i<DATASIZE; i++){
		for(int j = 0; j<databags[i].n_childs; j++){
			for(int k = 0; k<direct_i; k++){
				if(strcmp(databags[i].childs[j]->type, direct_shiny[k]->type) == 0 && strcmp(databags[i].childs[j]->color, direct_shiny[k]->color) == 0){
					indirect_shiny[indirect_i] = &(databags[i]);
					indirect_i++;
					break_pass = 1;
				}
			}
			if(break_pass == 1){
				break_pass = 0;
				break;
			}
		}
	}

	// fourth and half pass, print debug info
	for(int i = 0; i<indirect_i; i++){
		printf("%s %s -> indirect \"shiny gold\"\n", indirect_shiny[i]->type, indirect_shiny[i]->color);
	}

	// fourth and 3/4 pass, indirect^2
	int indirect_last = indirect_i;
	int indirectup2 = 0;
	int depth = 2;
	bag_t* indirect2_shiny[DATASIZE];
	memcpy(indirect2_shiny, indirect_shiny, sizeof(bag_t*)*DATASIZE);
	while(indirect_last != 0){
		int indirect2_i = 0;
		break_pass = 0;
		for(int i = 0; i<DATASIZE; i++){
			for(int j = 0; j<databags[i].n_childs; j++){
				for(int k = 0; k<indirect_last; k++){
					if(strcmp(databags[i].childs[j]->type, indirect2_shiny[k]->type) == 0 && strcmp(databags[i].childs[j]->color, indirect2_shiny[k]->color) == 0){
						indirect2_shiny[indirect2_i] = &(databags[i]);
						indirect2_i++;
						break_pass = 1;
					}
				}
				if(break_pass == 1){
					break_pass = 0;
					break;
				}
			}
		}
		for(int i = 0; i<indirect2_i; i++){
			printf("%s %s -> indirect%d\n", indirect2_shiny[i]->type, indirect2_shiny[i]->color, depth);
		}
		depth++;
		indirect_last = indirect2_i;
		indirectup2 += indirect2_i;
	}

	// fifth pass, remove duplications
	/*
	int duplicates = 0;
	for(int i = 0; i<indirect_i; i++){
		for(int j = 0; j<direct_i; j++){
			if(strcmp(direct_shiny[j]->type, indirect_shiny[i]->type) == 0 && strcmp(direct_shiny[j]->color, indirect_shiny[i]->color) == 0){
				duplicates++;
				printf("Duplicate: %s %s\n", direct_shiny[j]->type, direct_shiny[j]->color);
			}
		}
	}
	*/

	// print all direct and indirect bags
	//printf("All bags containing \"shiny gold\": %d\n", direct_i+indirect_i+indirectup2);


}

char* datasanity[] = {"light red bags contain 1 bright white bag, 2 muted yellow bags.",
"dark orange bags contain 3 bright white bags, 4 muted yellow bags.",
"bright white bags contain 1 shiny gold bag.",
"muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.",
"shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.",
"dark olive bags contain 3 faded blue bags, 4 dotted black bags.",
"vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.",
"faded blue bags contain no other bags.",
"dotted black bags contain no other bags."};
