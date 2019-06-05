#include<stdio.h>
#include<stdlib.h>
#include"myhead.h"

void select_animal(animal_kingdom *a)
{
	double q[generation_num];												//store the probalbility
	int i;
	for(i=0;i<generation_num;i++)
	{
		if(i==0)
			q[i]=a->population[i]->p;
		else
			q[i]=q[i-1]+a->population[i]->p;
	}
	srand((unsigned)time(NULL));

}
