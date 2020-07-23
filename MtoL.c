#include "MtoL.h"


list* mtol(int* m,int row_n,int rsize){
    list* L=malloc(row_n*sizeof(list));
    
    initList(L,row_n,rsize);

    for(int i=0;i<row_n;i++){
        for(int j=0;j<row_n;j++){
            L[i].d+=m[i*row_n+j];
        }
    }
    
    for(int i=0;i<row_n;i++){
        int k=0;
            for(int j=0;j<row_n;j++){
                if(m[i*row_n+j]!=0) {L[i].v[k]=j;k++;}
            }   
    }

    return L;
}


void initList(list* L,int L_size,int rsize){
    for(int i=0; i<L_size;i++){
        L[i].d=0;
        L[i].v=(int*)calloc(L[i].d,sizeof(int));
        L[i].rstatus=(double*)calloc(rsize,sizeof(double));
    }

}

void freeList(list* L,int L_size){
    for(int i=0; i<L_size;i++){
        free(L[i].v);
        free(L[i].rstatus);
    }

}