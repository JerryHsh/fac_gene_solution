#ifndef MYHEAD_H_INCLUDED
#define MYHEAD_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>

#define generation_num 	10   		//The number of the animal in a generation
#define gene_num 	5		//The number of item
#define move_num 	4		//The number of tackle movement
#define king_num 	1		//Rank num move to the next generation
#define nobel_num 	3		//Rank who have the right to have child except 4 5
#define generation_time 15		//Times of evolution

typedef struct node
{
	int gene[gene_num];														//describe the order
	int c[gene_num][move_num];
	double adapt;															//calculate time
	double p;																//The probalbility of being chosen full is 100
}animal;

typedef struct node2
{
	animal * population[generation_num];									//store the population Gene
	double lowest_adapt;			// recording the lowest adapt fittable for having child
}animal_kingdom;

typedef struct node3
{
	int a[gene_num];														//store the order
}order;

typedef struct circle
{
	int a;
	int flag;
	//struct circle *next;
}random_gene;

extern int time_table[gene_num][move_num];
extern random_gene * gene_store[gene_num];
extern int gene_store_pointer;					//指出循环中所指对象

/* calculate.c: */
/* calculate the time comsuption matrix (c[][]) of an animal */
void fresh(animal *);

/* calculate the estimated adapt of an animal */
void calculate(animal *);

/* ranking the whole animal kingdom, and sort its animals in 
	descending order by adapt */
void judge_man(animal_kingdom *a);


/* produce.c: */

/* initialize the gene_store structure */
void initialize(void);

/* re-initialize the gene_store structure */
void re_initialize(void);

/* produce animal without parents */
animal * produce_animal(void);

/* produce an animal kingdom without an older kingdom */
animal_kingdom *produce_kingdom(void);

/* produce an animal out of parents */
animal *produce_child_random(animal *pa1, animal *pa2);

/* generate the animal's gene based on its parents */
void generate_gene(animal *child, animal *a1, animal *a2);

/* generate a new kingdom out of the older one */
animal_kingdom *recursive(animal_kingdom *);


/* interface.c: */

/* print statistics information on the screen */
void show_kingdom(animal_kingdom *ak);

/* print animal's matrix c to the screen */
void print(animal *a);
/* manually set the time table */
void get_time_table(int time_table[gene_num][move_num]);

#endif // MYHEAD_H_INCLUDED
