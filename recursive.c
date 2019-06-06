/*
	recursive.c: perform the process that a new generation born from the old one
	delete old animal_kingdom after successfully generating the new one.
*/

#include <stdio.h>
#include <stdlib.h>

#include "myhead.h"

#define ACCURANCY 1000000

/* pick out an animal */
animal *pick(animal_kingdom *ak) {
	double rand_num;
	int i = 0;

	if (ak) {
		rand_num = (double)(rand() % ACCURANCY) / ACCURANCY;
		printf("rand_num = %lf\n", rand_num);
		while (rand_num - ak->population[i]->p > 0 && i < nobel_num) {
			rand_num -= ak->population[i]->p;
			printf("rand_num: %lf\n", rand_num);
			i ++;
		}
		printf("i = %d\n", i);
		return ak->population[i];
	}

	return NULL;
}

animal_kingdom *recursive(animal_kingdom *old) {
	animal_kingdom *new;
	animal *pa1, *pa2;	// the parents
	int i, j, h;

	if (old) {
		new = (animal_kingdom*)malloc(sizeof(animal_kingdom));
		if (new) {
			/* for king */
			for (i = 0; i < king_num; i ++) {
				new->population[i] = (animal*)malloc(sizeof(animal));
				for (j = 0; j < gene_num; j ++) {
					new->population[i]->gene[j] =
						old->population[i]->gene[j];
					for (h = 0; h < move_num; h ++)
						new->population[i]->c[j][h] =
							old->population[i]->c[j][h];
				}
				new->population[i]->adapt = old->population[i]->adapt;	/* adapt */
				new->population[i]->p = 0;
			}
			/* for the rest */
			for (; i < generation_num; i ++) {
				while (1) {
					pa1 = pick(old);
					pa2 = pick(old);
					new->population[i] = produce_child_random(pa1, pa2);
					if (new->population[i]->adapt >= old->lowest_adapt) 
						break;
					else 
						free(new->population[i]);
				}
				printf("pa1: %p, pa2: %p\n", pa1, pa2);
			}

			judge_man(new);
			new->lowest_adapt = new->population[nobel_num - 1]->adapt;
			return new;
		}
		else
			fprintf(stderr, "recursive(): failed to generate new animal kingdom\n");
	}

	return NULL;
}
