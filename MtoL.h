#ifndef MTOL_H
#define MTOL_H
#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int d;
    int* v; 
    double* rstatus; 
}list;

list* mtol(int* m,int row_n,int rsize);
void initList(list* L,int L_size,int rsize);
void freeList(list* L,int L_size);
#endif //MTOL_H