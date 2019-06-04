/*
	multiple.c
	written by joel
*/

#include <stdlib.h>
#include <time.h>

#include "animal.h"

/* create an animal with random gene */
animal *create_animal(void) {
	int i, j;
	animal *tmp = (animal*)malloc(sizeof(animal));

	if (tmp) {
		/* initializing the statistics of the animal */
		for (i = 0; i < gene_num; i ++) {
			tmp->gene[i] = 0;
			for (j = 0; j < move_num; j ++) 
				c[i][j] = 0;
		}
		
		for (i = 0; i < gene_num; i ++) {
			tmp->gene[i] = (rand() % move_num) + 1;
			for (j = 0; j < i; j ++) {
				if (tmp->gene[i] == tmp->gene[j]) {
					tmp->gene[i] = (rand() % move_num) + 1;
					j = 0;
				}
			}
		}
		calculate(tmp);		/* figure out adapt */
		tmp->p = 0;
	}
	
	return tmp;
}
