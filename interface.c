/* 
	interface.c: including some functions for output 
*/

#include <stdio.h>

#include "myhead.h"

int _fit(const int *gene1, const int *gene2) {
	int i;

	if (gene1 && gene2) {
		for (i = 0; i < gene_num; i ++) 
			if (gene1[i] != gene2[i]) 
				return 0;
		return 1;
	}

	return 0;
}

void show_kingdom(animal_kingdom *ak) {
	static int pool[generation_num][gene_num + 2];
	int i, j, h;

	/* initialize */
	for (i = 0; i < generation_num; i ++) 
		pool[i][gene_num] = 0;
	
	for (i = 0; i < generation_num; i ++) {
		// for every animal in the kingdom
		j = 0;
		while (pool[j][gene_num]) {
			if (_fit(pool[j], ak->population[i]->gene)) {
				pool[j][gene_num] ++;
				goto end_of_loop;
			} else 
				j ++;
		}
		/* if the animal do not belong to any pool existing record in pool before, 
			add it to a new one */
		for (h = 0; h < gene_num; h ++) 
			pool[j][h] = ak->population[i]->gene[h];
		pool[j][gene_num] ++;
		pool[j][gene_num + 1] = ak->population[i]->adapt;
		end_of_loop:;
	}

	for (i = 0; pool[i][gene_num]; i ++) {
		for (j = 0; j < gene_num; j ++) 
			printf("%d ", pool[i][j]);
		printf(":");
		//printf("%d: ", pool[i][gene_num + 1]);
		for (j = 0; j < pool[i][gene_num]; j ++) 
			printf("* ");
		putchar('\n');
	}
}

/* print animal's matrix c to the screen */
void print(animal *a)
{
	int i,j;
	for(i=0;i<gene_num;i++)
	{
		for(j=0;j<move_num;j++)
		{
			if(j!=move_num-1)
				printf("%d ",(a->c)[i][j]);
			else
				printf("%d\n",(a->c)[i][j]);
		}
	}
}
