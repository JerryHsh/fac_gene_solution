#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include"myhead.h"

int time_table[gene_num][move_num]={{31,41,25,30},{19,55,3,34},{23,42,27,6},{13,22,14,13},{33,5,57,19}};

int main()
{
	initialize();
	srand((unsigned)time(NULL));
	animal *a[gene_num];
	int i;
	int j;
	for(i=0;i<generation_num;i++)
	{
		a[i]=produce_animal();
		for(j=0;j<gene_num;j++)
		{
			printf("%d ",a[i]->gene[j]);
		}
		putchar('\n');
	}
	return 0;
}






