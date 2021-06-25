//
// Created by user on 2021/6/7.
//

#include <stdio.h>
#include <string.h>

#define INF 1e9
/*struct edge{
    int s;
    int t;
    int w;
}typedef Edge;*/


int main (){
    int c;
    scanf("%d",&c);
    int n,m;// n of system, m of wormholes
    for (int i = 0; i < c; ++i) {
        scanf("%d %d",&n,&m);
        int adj[n][n];
        // initial adj array
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if(j == k)
                    adj[j][k] = 0;
                else
                    adj[j][k] = INF;
            }
        }
        // construct adj array
        int s,t,w;
        for (int j = 0; j < m; ++j) {
            scanf("%d %d %d", &s,&t,&w);
            if(adj[s][t] > w)
                adj[s][t] = w;
            if(s == t && w != 0)
                continue;
        }
        int dis[n][n];
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                dis[j][k] = adj[j][k];
            }
        }

        // floyd_warshall
        for (int j = 0; j < n; ++j) { // medium
            for (int k = 0; k < n; ++k) { // s
                for (int l = 0; l < n; ++l) { // t
                    if(dis[k][j]+dis[j][l] < dis[k][l]) {
                        dis[k][l] = dis[k][j]+dis[j][l];
                    }
                }
            }
        }

        // find negative cycle
        int flag = 0;
        for (int j = 0; j < n; ++j) {
            if(dis[j][j] != 0){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            printf("possible\n");
        }else{
            printf("not possible\n");
        }
    }
}