#include<stdio.h>
#include"BA.h"
#include"closeness_centrality.h"
#include"cluster.h"
#define MAXV 20 //頂点数
#define INIV 3  //BAの場合の最初の完全グラフ
#define ADDV 2  //BAの場合の加える辺の数
int main(void){

    int* net=BAnet(MAXV,INIV,ADDV);
    //printm(net,MAXV,0,MAXV);
    //list* L=closenessCentrality(net, MAXV);
    list *L=cluster(net,MAXV);
    for(int i=0;i<MAXV;i++){
       // for(int j=0;j<10;j++){
          //  printf("L[%d]->j=%f##",i,L[i].rstatus[0]);
        //}
        puts("");
    }
    free(net);
    freeList(L,MAXV);
    free(L);
    return 0;
}