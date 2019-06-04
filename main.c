#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define generation_num 10   	//The number of the animal in a generation
#define gene_num 5				//The number of item
#define move_num 4				//The number of tackle movement
#define king_num 1				//Rank num move to the next generation
//#define nobel_num 5				//Rank who have the right to have child except 4 5
#define generation_time 50		//Times of evolution

static int time_table[gene_num][move_num]={{31,41,25,30},{19,55,3,34},{23,42,27,6},{13,22,14,13},{33,5,57,19}};

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
												//store calculate time

void judge_man(animal_kingdom *);															//rank
void fresh(animal *);
void calculate(animal *);
void print(animal *);

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

int main()
{
	animal * a;
	a=(animal *)malloc(sizeof(animal));
	fresh(a);
	a->gene[0]=4;
	a->gene[1]=2;
	a->gene[2]=5;
	a->gene[3]=1;
	a->gene[4]=3;
	calculate(a);
	print(a);
	return 0;
}

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





