#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"myhead.h"

int time_table[gene_num][move_num]={{31,41,25,30},{19,55,3,34},{23,42,27,6},{13,22,14,13},{33,5,57,19}};

int main(void)
{
	initialize();
	srand((unsigned)time(NULL));
	animal_kingdom * old;
	old=produce_kingdom();
	int i;
	animal_kingdom * last_generation;
	animal_kingdom * middle;
	for(i=0;i<generation_time;i++)
	{
		middle=recursive(old);
		old=middle;
	}
	last_generation=old;
	print(last_generation->population[0]);
	return 0;
}
