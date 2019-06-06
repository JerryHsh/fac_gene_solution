/*
	cross.c: cross the animals gene, create new children for the next generation
*/

#include <stdlib.h>
#include <stdio.h>

#include "myhead.h"

void generate_gene(animal *child, animal *a1, animal *a2) {
	int i, j;

	if (child && a1 && a2) {
		for (i = 0; i < gene_num; i ++) {
			if (a1->gene[i] == a2->gene[i])
				child->gene[i] = a1->gene[i];
			else
				child->gene[i] = 0;
		}
		for (i = 0; i < gene_num; i ++) {
			if (child->gene[i] == 0) {
				child->gene[i] = rand() % gene_num + 1;
				for (j = 0; j < gene_num; j ++)
					if (i != j && child->gene[i] == child->gene[j]) {	// if find the number appeared before, regenerate it and re-check
						child->gene[i] = rand()% gene_num + 1;
						j = 0;
					}
			}
		}
	}
	else 	// print error information
		fprintf(stderr, "%s is NULL\n", (child)?(a1?"a2":"a1"):"child");
}
