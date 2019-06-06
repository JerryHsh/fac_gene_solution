/* 
	recursive.c: function responsible for generating animal generations
*/

#include <stdio.h>
#include <stdlib.h>

#include "myhead.h"

/* remove the animal_kingdom of older generation */
void rm_animal_kingdom(animal_kingdom *ak);

animal_kingdom *new_generation(animal_kingdom *old) {
	int i, j, h;
	animal_kingdom *new = NULL;

	if (old) {
		for (i = 0; i < king_num; i ++) {	// for some elites
			if (new->population[i] = (animal*)malloc(sizeof(animal))) 
				;
			else 
				fprintf(stderr, "recursive(): error occured when mallocating memory for new\n");
			for (j = 0; j < gene_num; j ++) {
				new->population[i]->gene[j] = old->population[i]->gene[i];
				for (h = 0; h < move_num; h ++) 
					new->population[i]->c[j][h] = old->population[i]->c[j][h];
			}
			new->population[i]->adapt = old->population[i]->adapt;
			new->population[i]->p = 0;
		}
		for (; i < generation_num; i ++) {
			if (new->population[i] = (animal*)malloc(sizeof(animal))) 
				;
			else 
				fprintf(stderr, "recursive(): error occured when mallocating memory for new\n");
			
			calculate(new->population[i]);
			
		}
	}
	else 
		fprintf(stderr, "recursive(): old is null\n");

	return new;
}
