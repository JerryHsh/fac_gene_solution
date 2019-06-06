#include<stdio.h>
#include<stdlib.h>
#include"myhead.h"

animal * produce_child_traditon(animal *pa1,animal *pa2)
{
    re_initialize();
    animal *c;
    c=(animal *)malloc(sizeof(animal));
    int i;
    int step;
    int flag=0;                 //if flag = 0 needn't change
    for(i=0;i<gene_num;i++)
    {
        if(pa1->gene[i]==pa2->gene[i])
        {
            c->gene[i]=pa1->gene[i];
            gene_store[pa1->gene[i]-1]->flag=0;
        }
        else
        {
            c->gene[i]=0;
            flag=1;
        }
    }
    if(flag)
    {
        for(i=0;i<gene_num;i++)
        {
            if(!c->gene[i])
            {
                step=rand()%gene_num+1;
                gene_store_pointer+=step;
                if(gene_store_pointer>=gene_num)
                    gene_store_pointer-=gene_num;
                while(gene_store[gene_store_pointer]->flag==0)
                {
                    gene_store_pointer++;
                    if(gene_store_pointer==gene_num)
                    gene_store_pointer=0;
                }
                c->gene[i]=gene_store[gene_store_pointer]->a;
                gene_store[gene_store_pointer]->flag=0;
            }
        }
    }
    return c;
}

