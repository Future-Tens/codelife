//
// Created by user on 2021/4/17.
//
#include <stdio.h>

int min(int a,int b){
    return a>b?b:a;
}

void floyd1(int n,int W[8][8],
           int D[8][8]) {
    int i, j, k;
    for(i=1; i <= n; i++)
        for(j=1; j <= n; j++)
            D[i][j] = W[i][j];
    for(k=1; k <= n; k++)
        for(i=1; i <= n; i++)
            for(j=1; j <= n; j++)
                D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
    for(i=1; i <= 8; i++) {
        for (j = 1; j <= 8; j++) {
            printf("%d",D[i][j]);
        }
        printf("\n");
    }
}


int main(){
     int adj[8][8] = {{0,0,0,0,0,0,0,0},
                    {0,0,4,0,0,0,10,0},
                    {0,3,0,0,18,0,0,0},
                    {0,0,6,0,0,0,0,0},
                    {0,0,5,15,0,2,19,10},
                    {0,0,0,12,1,0,0,0},
                    {0,0,0,0,0,0,0,10},
                    {0,0,0,0,8,0,0,0}};
     int T[8][8] = {{0}};
     floyd1(7,adj,T);
     int i,j;
     return 0;
}
