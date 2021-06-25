//
// Created by user on 2021/5/3.
//
#include <stdio.h>
#include <string.h>

int knapsack(int N,int W,const int COST[],const int WEIGHT[]){
    int DP[W+1];

    memset(DP,0, sizeof(DP));

    for(int i =0; i < N;i++){
        for(int j = W; j>=WEIGHT[i];--j){//做到背包裝不下 WEIGHT[i]
            if(DP[j-WEIGHT[i]]+COST[i] > DP[j]){
                DP[j] = DP[j-WEIGHT[i]]+COST[i];
            }
        }
    }
    return DP[W];
}
//
int recur_knapsack(int N,int W,const int COST[],const int WEIGHT[]){

    if(N <= 0|| W <= 0)return 0;// N and W cannot be negative or zero

    if (WEIGHT[N-1] < W) { // can put
        // opt = max(COST[N - 1]+ recur_knapsack(N-1,W - WEIGHT[N - 1], COST,WEIGHT) , recur_knapsack(N-1,W, COST, WEIGHT))
        int put = COST[N - 1] + recur_knapsack(N - 1, W - WEIGHT[N - 1], COST, WEIGHT);
        int last = recur_knapsack(N - 1, W, COST, WEIGHT);
        return  put > last ? put : last;
    }
    else//can not put
        return recur_knapsack(N-1,W, COST, WEIGHT);

}
int main(){
    int T ,N;
    scanf("%d",&T);
    for(int j = 0;j<T;j++) {
        scanf("%d", &N);
        int COST[N], WEIGHT[N];
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &COST[i], &WEIGHT[i]);
        }

        int G, W, total = 0;
        scanf("%d", &G);
        for (int i = 0; i < G; i++) {

            scanf("%d", &W);
            total += recur_knapsack(N, W, COST, WEIGHT);
        }
        printf("%d\n", total);
    }
}