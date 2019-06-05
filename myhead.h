#ifndef MYHEAD_H_INCLUDED
#define MYHEAD_H_INCLUDED


#define generation_num 10   	//The number of the animal in a generation
#define gene_num 5				//The number of item
#define move_num 4				//The number of tackle movement
#define king_num 1				//Rank num move to the next generation
//#define nobel_num 5				//Rank who have the right to have child except 4 5
#define generation_time 50		//Times of evolution

extern int time_table[gene_num][move_num];

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
}animal_kingdom;

typedef struct node3
{
	int a[gene_num];														//store the order
}order;


void judge_man(animal_kingdom *);															//rank
void fresh(animal *);
void calculate(animal *);
void print(animal *);
void create_order(animal *);
void select_animal(animal_kingdom *);
void initialize(void);
animal * produce_animal(void);
animal_kingdom *produce_kingdom(void);
void re_initialize(void);

#endif // MYHEAD_H_INCLUDED