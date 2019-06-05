#include<stdio.h>
#include<stdlib.h>
#include"myhead.h"


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

