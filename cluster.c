#include"cluster.h"

list* cluster(int* gragh, int row_n){
    list* L=mtol(gragh,row_n,1);
    for(int i=0;i<row_n;i++){//元の頂点
        for(int j=0;j<L[i].d;j++){//元の隣
            int nextv=L[i].v[j];
            for(int k=0;k<L[nextv].d;k++){//隣の隣
                int n_nextv=L[nextv].v[k];
                for(int l=0;l<L[n_nextv].d;l++){//隣の隣の隣
                    if(L[n_nextv].v[l]==i){
                        L[i].rstatus[0]++;
                        break;
                    }
                }
            }
        }
        L[i].rstatus[0]=L[i].rstatus[0]/2;
    }

    return L;
}