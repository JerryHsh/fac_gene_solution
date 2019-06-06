#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"myhead.h"

int time_table[gene_num][move_num]={{31,41,25,30},{19,55,3,34},{23,42,27,6},{13,22,14,13},{33,5,57,19}};

int main(void) {
	
}

/*
int main()
{

	int  i;
	int j;
	initialize();
	srand((unsigned)time(NULL));
	animal *a,*b,*c;
	a=produce_animal();
	for(i=0;i<gene_num;i++)
	{
		printf("%d ",a->gene[i]);
	}
	putchar('\n');
	b=produce_animal();
	for(i=0;i<gene_num;i++)
	{
		printf("%d ",b->gene[i]);
	}
	putchar('\n');
	c=produce_animal();
	for(i=0;i<gene_num;i++)
	{
		printf("%d ",c->gene[i]);
	}
	putchar('\n');
	putchar('\n');
	generate_gene(c,a,b);

	for(i=0;i<gene_num;i++)
	{
		printf("%d ",a->gene[i]);
	}
	putchar('\n');

	for(i=0;i<gene_num;i++)
	{
		printf("%d ",b->gene[i]);
	}
	putchar('\n');
	calculate(c);
	for(i=0;i<gene_num;i++)
	{
		printf("%d ",c->gene[i]);
	}
	putchar('\n');

	initialize();
	animal_kingdom * a;
	a=produce_kingdom();
	int i;
	int j;
	for(i=0;i<generation_num;i++)
	{
		for(j=0;j<gene_num;j++)
		{
			printf("%d ",a->population[i]->gene[j]);
		}
		printf("%lf",a->population[i]->adapt);
		putchar('\n');
	}
	judge_man(a);
	putchar('\n');
	for(i=0;i<generation_num;i++)
	{
		for(j=0;j<gene_num;j++)
		{
			printf("%d ",a->population[i]->gene[j]);
		}
		printf("%d ",a->population[i]->c[4][3]);
		printf("%lf ",a->population[i]->adapt);
		printf("%.4lf",a->population[i]->p);
		putchar('\n');
	}
	return 0;
}*/
