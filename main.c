#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include"myhead.h"

int time_table[gene_num][move_num]={{31,41,25,30},{19,55,3,34},{23,42,27,6},{13,22,14,13},{33,5,57,19}};

int main()
{
	srand((unsigned)time(NULL));
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d ",rand());
	}
	putchar('\n');
	return 0;
}






