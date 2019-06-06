#include "myhead.h"

void cross(animal *child, animal *a, animal *b)
{
    int weight[gene_num], flag[gene_num], i, j, sign;
	int p[gene_num], temp;
    for ( i = 0; i < gene_num; i++ ) {
        weight[i] = 0;
		flag[i] = 0;
	}
    for ( i = 0; i < gene_num; i++ ) {
		weight[a->gene[i] - 1] += i + 1;
		weight[b->gene[i] - 1] += i + 1;
	}
    for ( i = 0, temp = 0; i < gene_num; i++ ) {
		p[i] = weight[i] + temp;
		temp = p[i];
	}
	for ( i = gene_num - 1; i >= 0; i-- ) {
        do {
            sign = 0;
            temp = rand() % p[gene_num - 1];
            for ( j = 0; j < gene_num; j++ ) {
                if ( temp < p[j] && !flag[j]) {
                    child->gene[i] = j + 1;
                    flag[j] = 1;
                    break;
                } else if ( temp < p[j] && flag[j] ) {
                    sign = 1;
                    break;
                }
            }
        } while ( sign );
	}
}
