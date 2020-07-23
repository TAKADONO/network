#include"closeness_centrality.h"
#include<stdio.h>
#include<stdlib.h>
void printm1(int* matrix, int row_size,int start, int end){
    for(int i=start;i<1;i++){
        for(int j=start;j<end;j++){
            printf("%d ",matrix[i*row_size+j]);
        }
        puts("");
    }

}


list* closenessCentrality(int* gragh, int row_n){
    //I WANT LAPACK
    //int* closeC_list=(int*)calloc(row_n*row_n,sizeof(int));
//printm1(gragh,row_n,0,row_n);
   list* L=mtol(gragh,row_n,row_n);

    int* zero=calloc(row_n,sizeof(int));
    int* next_check_l=calloc(row_n,sizeof(int));
    int* check_l=calloc(row_n,sizeof(int));
    int* close_l=calloc(row_n,sizeof(int));
    int close_cnt=0;
    int dis=0;
   for(int i=0;i<row_n;i++){//もとに着目
        aryAtoB(zero,close_l,row_n);
        dis=0;
        L[i].rstatus[i]=dis;
        close_l[i]=1;
        close_cnt=1;
        for(int j=0;j<L[i].d;j++) {
           //L.rstatus[L[i].v[j]]=1;
           check_l[L[i].v[j]]=1;
           close_l[L[i].v[j]]=1;
       }
      // printf("i=%d\n",i);

       while (close_cnt<row_n){
        //     printf("i=%d\n",i);
             dis++;
            for(int j=0;j<row_n;j++){//check_lの頂点に着目
          //  printf("startj=%d\n",j);
                
                if(check_l[j]==1){
                    L[i].rstatus[j]=dis;
                    close_cnt++;
              //      printf("j=%d\n",j);
                    for(int l=0;l<L[j].d;l++){//check_lの隣接に着目 make next_check_l
                        if(close_l[L[j].v[l]]==0){
                                next_check_l[L[j].v[l]]=1;
                                close_l[L[j].v[l]]=1;
              //                  printf("l=%d\n",l);
                            }
                        }
               //         printf("endj=%d\n",j);
                    }

                }
             //   puts("B");
               //        printm1(check_l,0,0,row_n);
                aryAtoB(next_check_l,check_l,row_n);
                aryAtoB(zero,next_check_l,row_n);
              //         printm1(next_check_l,0,0,row_n);
              //  printf("cnt=%d\n",close_cnt);
                
           }
       

       }

    free(zero);
    free(close_l);
    free(check_l);
    free(next_check_l);
return L;
}

void aryAtoB(int* arya,int* aryb,int ary_size){
    for(int i=0;i<ary_size;i++){
        aryb[i]=arya[i];
    }
}


