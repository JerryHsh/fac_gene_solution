#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"myhead.h"

int time_table[gene_num][move_num]={{31,41,25,30},{19,55,3,34},{23,42,27,6},{13,22,14,13},{33,5,57,19}};

int main(void)
{
	animal_kingdom * ak;
	int tmp;	// record user's choice 
	int i;

	/* initialization */
	do {
		printf("1 - manually set time table, 0 - use default: ");
		scanf("%d", &tmp);
		if (tmp == 1) 
			get_time_table(time_table);
	} while (tmp != 1 && tmp != 0);
	initialize();
	srand((unsigned)time(NULL));
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
