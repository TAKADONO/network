#include<stdio.h>
#include<stdlib.h>
#define INIVT 5
#define MAX_V 20
#define ADD_N 3

void printm(int* matrix, int row_size, int start, int end);
int* makeComplitGraph(int vn);   
int main(void){

    int max_vertex=MAX_V;
    int complit_graphV=INIVT;
    double allD=0;
    double RM=RAND_MAX;
    int addn=ADD_N;
    int* BAnetwork=calloc(max_vertex*max_vertex,sizeof(int));
    int* D=calloc(max_vertex,sizeof(int));
    int* complit_graph=makeComplitGraph(complit_graphV);
    puts("A");
    for(int i=0;i<complit_graphV;i++){
        for(int j=0;j<complit_graphV;j++){
            BAnetwork[i*max_vertex+j]=complit_graph[i*complit_graphV+j];
            D[i]+=complit_graph[i*complit_graphV+j];
            //printf("i=%d, j=%d\n",i,j);
        }
        
        allD+=D[i];
    }
    puts("B");
    srand(0);
    int* choosed_list=calloc(max_vertex,sizeof(int));
    for(int now_vt=complit_graphV;now_vt<max_vertex;now_vt++){
        //printf("p=%f\n",p);
        double useD=allD;
        for(int j=0;j<addn;j++){
            double p=rand()/RM;
            double start=0;
            double end=0;
            for(int i=0;i<now_vt;i++){
                    if(choosed_list[i]!=1){
                        end+=D[i]/useD;
                    // printf("i=%d, j=%d\n",now_vt,i);
                        if(start<p&&p<=end){
                            BAnetwork[i*max_vertex+now_vt]=1;
                            BAnetwork[now_vt*max_vertex+i]=1;
                            useD-=D[i];
                            D[i]++;
                            D[now_vt]++;
                            allD+=2;
                            choosed_list[i]=1;
                            break;
                    }
                
                    start=end;
                }   
            }
        }
        for(int k=0;k<max_vertex;k++) choosed_list[k]=0;
    }
    printm(BAnetwork,max_vertex,0,max_vertex);
    free(BAnetwork);
    free(D);
    free(complit_graph);
    free(choosed_list);


    return 0;


}


void printm(int* matrix, int row_size,int start, int end){
    for(int i=start;i<end;i++){
        for(int j=start;j<end;j++){
            printf("%d ",matrix[i*row_size+j]);
        }
        puts("");
    }

}

int* makeComplitGraph(int vn){
    int* network=calloc(vn*vn,sizeof(int));
    for(int i=0;i<vn;i++){
        for(int j=0;j<vn;j++){
        if(i!=j){
            network[i*vn+j]=1;
            }   
        }               
    }   
    printm(network,vn,0,vn);
    return network;
}   
