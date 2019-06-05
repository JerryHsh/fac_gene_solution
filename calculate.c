#include<stdio.h>
#include<stdlib.h>
#include"myhead.h"


void fresh(animal *a)
{
	int i,j;
	for(i=0;i<gene_num;i++)
	{
		for(j=0;j<move_num;j++)
		{
			(a->c)[i][j]=0;
		}
	}
}


void calculate(animal *a)			//correct
{
	int i,j;
	(a->c)[0][0]=time_table[(a->gene)[0]-1][0];
	for(i=1;i<gene_num;i++)
		(a->c)[i][0]=(a->c)[i-1][0]+time_table[(a->gene)[i]-1][0];
	for(i=0;i<gene_num;i++)
	{
		for(j=1;j<move_num;j++)
		{
			if(i==0)
			{
				(a->c)[i][j]=(a->c)[i][j-1]+time_table[(a->gene)[i]-1][j];
			}
			else
			{
				if((a->c)[i][j-1]>=(a->c)[i-1][j])
					(a->c)[i][j]=(a->c)[i][j-1]+time_table[(a->gene)[i]-1][j];
				else
					(a->c)[i][j]=(a->c)[i-1][j]+time_table[(a->gene)[i]-1][j];
			}
		}
	}
	a->adapt=1.0/a->c[gene_num-1][move_num-1];
}



void judge_man(animal_kingdom *a)							//rank from big to small
{
	double total;
	int i;
	for(i=0,total=0;i<generation_num;i++)
		total+=a->population[i]->adapt;
	for(i=0;i<generation_num;i++)
		a->population[i]->p=a->population[i]->adapt/total;
	animal * swap;
	int j;
	for(i=0;i<generation_num-1;i++)
		for(j=0;j<generation_num-1-i;j++)
		{
			if(a->population[j]->p<a->population[j+1]->p)
			{
				swap=a->population[j];
				a->population[j]=a->population[j+1];
				a->population[j+1]=swap;
			}
		}
}

