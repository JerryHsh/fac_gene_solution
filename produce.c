/* 
	produce.c: this file is mainly for producing the first generation
	of animals and their kingdom. In specific, this file involves 
	a special data structure called "random_gene", which is defined 
	in myhead.h
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"myhead.h"
//correct

random_gene * gene_store[gene_num];
int gene_store_pointer;					//指出循环中所指对象

void initialize(void)
{
    int i;
    for(i=0;i<gene_num;i++)
    {
        gene_store[i]=(random_gene *)malloc(sizeof(random_gene));
        gene_store[i]->a=i+1;
        gene_store[i]->flag=1;
    }
    gene_store_pointer=0;
}

void re_initialize(void)
{
    int i;
    for(i=0;i<gene_num;i++)
    {
        gene_store[i]->flag=1;
    }
}

/* produce animal without parents */
animal * produce_animal(void)
{
    re_initialize();
    animal * a;
    a=(animal *)malloc(sizeof(animal));
    int i;
    int step;
    for(i=0;i<gene_num;i++)
    {
    	step=rand()%gene_num+1;
        gene_store_pointer+=step;
        if(gene_store_pointer>=gene_num)
			gene_store_pointer-=gene_num;
        while(gene_store[gene_store_pointer]->flag==0)
        {
            gene_store_pointer++;
            if(gene_store_pointer==gene_num)
                gene_store_pointer=0;
        }
        a->gene[i]=gene_store[gene_store_pointer]->a;
        gene_store[gene_store_pointer]->flag=0;
    }
    calculate(a);
    return a;
}

/* produce an animal kingdom without an older kingdom */
animal_kingdom * produce_kingdom(void)
{
    animal_kingdom * a;
    a=(animal_kingdom *)malloc(sizeof(animal_kingdom));
    int i;
    for(i=0;i<generation_num;i++)
        a->population[i]=produce_animal();
    judge_man(a);
	return a;
}

/* produce an animal out of parents, using lst's idea */
animal * produce_child_random(animal *pa1,animal * pa2)
{
    animal *c;
    c=(animal *)malloc(sizeof(animal));
    generate_gene(c,pa1,pa2);
    fresh(c);
    calculate(c);
    return c;
}

/* generate the gene of the child, based on its parents. We use the middle 
value of the same items on parents genes to define the possibility. 
The possibility is used to randomly put items into child's gene. 

We expect that items with a larger weight to be put near the old of 
the gene.
*/
void generate_gene(animal *child, animal *a, animal *b)
{
    int weight[gene_num], flag[gene_num], i, j, sign;
	int p[gene_num], temp;
    for ( i = 0; i < gene_num; i++ ) {
        weight[i] = 0;
		flag[i] = 0;
	}
    for ( i = 0; i < gene_num; i++ ) {
		weight[a->gene[i] - 1] += i + 1;
		weight[b->gene[i] - 1] += i + 1;
	}
    for ( i = 0, temp = 0; i < gene_num; i++ ) {
		p[i] = weight[i] + temp;
		temp = p[i];
	}
	for ( i = gene_num - 1; i >= 0; i-- ) {
        do {
            sign = 0;
            temp = rand() % p[gene_num - 1];
            for ( j = 0; j < gene_num; j++ ) {
                if ( temp < p[j] && !flag[j]) {
                    child->gene[i] = j + 1;
                    flag[j] = 1;
                    break;
                } else if ( temp < p[j] && flag[j] ) {
                    sign = 1;
                    break;
                }
            }
        } while ( sign );
	}
}

#define ACCURANCY 1000000

/* pick out an animal */
animal *_pick(animal_kingdom *ak) {
	double rand_num;
	int i = 0;

	if (ak) {
		rand_num = (double)(rand() % ACCURANCY) / ACCURANCY;
		while ((rand_num -= (double)ak->population[i]->p) > 0 && i < nobel_num) 
			i ++;

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
					pa1 = _pick(old);
					pa2 = _pick(old);
					new->population[i] = produce_child_random(pa1, pa2);
					if (new->population[i]->adapt >= old->lowest_adapt)
						break;
					else
						free(new->population[i]);
				}
				// printf("pa1: %p, pa2: %p\n", pa1, pa2);
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
