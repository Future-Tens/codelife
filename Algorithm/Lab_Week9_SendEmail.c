//
// Created by user on 2021/5/30.
//
#include <stdio.h>
#include <string.h>

#define INF 1e9

struct point{
    int id;
}typedef Point;

struct edge{
    int s;
    int t;
    int w;
}typedef Edge;

void update_path(int p[],int s,int now ,Edge e[],int e_num,int direct){
    if(direct == 0){
        for(int i = 0;i < e_num; ++i){
            if (e[i].s == now) {
                if (p[now] + e[i].w < p[e[i].t])
                    p[e[i].t] = p[now] + e[i].w ;
            }
            else if(e[i].t == now) {
                if (p[now] + e[i].w < p[e[i].s])
                    p[e[i].s] = p[now] + e[i].w ;
            }
        }
    }else{
        //有向圖之後再說:)
        return;
    }
}
int find_min_id(int vertex[], int path[], int p_num){
    int tmp = INF;
    int id = -1;
    for (int i = 0; i < p_num; ++i) {
        if(vertex[i]!=1 && path[i]< tmp) {
            tmp = path[i];
            id = i;
        }
    }
    return id;
}

void init(int p[],int num,int s){
    for (int i = 0; i < num; ++i) {
        if(i == s)
            p[i] = 0;
        else
            p[i] = INF;
    }
}

void debug(int p[],int p_num,int s){
    printf("=================== Debug ===================\n");
    printf("Pick: %d\n",s);
    for (int i = 0; i < p_num; ++i) {
        printf("%d ",p[i]);
    }
    printf("\n=================== Debug ===================\n");
}
int Dijkstra(Point p[],Edge e[],int p_num,int e_num,int s,int t,int direct){

    int now = s,min_id;
    int vertex[p_num];
    int path[p_num];

    memset(vertex,0, sizeof(vertex));
    init(path,p_num,s); // initialize path array
    if(direct == 0){
        path[s] = 0;
        vertex[s] = 1;
        while(1){
            update_path(path, s, now, e, e_num, direct);
            min_id = find_min_id(vertex,path,p_num);
            if(min_id == -1)break;
            now = min_id;
            vertex[now] = 1;
            //debug(path,p_num,now);
        }
    }else{
        //有向圖之後再說:)
        return -1;
    }
    if(path[t] != INF){
        return path[t];
        //printf("%d\n",path[t]);
    }else{
        return -1;
        printf("unreachable\n");
    }

}

int main(){
    int N;
    scanf("%d",&N);
    int n,m,s,t;//n個點, m個邊
    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d %d",&n,&m,&s,&t);
        /*if(m == 0){
            printf("Case #%d: unreachable",i+1);
            if(i != N-1){
                printf("\n");
            }
            continue;
        }*/
        Point p_array[n];
        Edge e_array[m];
        memset(p_array, 0, sizeof(p_array));
        memset(e_array, 0, sizeof(e_array));
        for (int j = 0; j < m; ++j) {
            scanf("%d %d %d",&e_array[j].s,&e_array[j].t,&e_array[j].w);
        }
        int result = Dijkstra(p_array,e_array,n,m,s,t,0);
        if(result != -1){
            printf("Case #%d: %d\n",i+1,result);
        }else{
            printf("Case #%d: unreachable\n",i+1);
        }
    }
}