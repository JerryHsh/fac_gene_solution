#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"myhead.h"

int time_table[gene_num][move_num]={{31,41,25,30},{19,55,3,34},{23,42,27,6},{13,22,14,13},{33,5,57,19}};

int main(void) {
	initialize();
	animal_kingdom *ak = produce_kingdom();
	show_kingdom(ak);

	return 0;
}
