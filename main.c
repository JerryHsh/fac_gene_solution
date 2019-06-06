#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"myhead.h"

int time_table[gene_num][move_num]={{31,41,25,30},{19,55,3,34},{23,42,27,6},{13,22,14,13},{33,5,57,19}};

int main(void)
{
	initialize();
	srand((unsigned)time(NULL));
	animal_kingdom * ak;
	int i;

	ak = produce_kingdom();
	show_kingdom(ak);
	getchar();
	for (i = 0; i < generation_time; i ++) {
		ak = recursive(ak);
		printf("generation %d:\n", i + 1);
		show_kingdom(ak);
		getchar();
	}

	return 0;
}
