#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"myhead.h"
//correct


typedef struct circle
{
	int a;
	int flag;
	//struct circle *next;
}random_gene;

static random_gene * gene_store[gene_num];
static int gene_store_pointer;					//指出循环中所指对象


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

animal_kingdom * produce_kingdom(void)
{
    animal_kingdom * a;
    a=(animal_kingdom *)malloc(sizeof(animal_kingdom));
    int i;
    for(i=0;i<generation_num;i++)
        a->population[i]=produce_animal();
	return a;
}
