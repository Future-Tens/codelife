//
// Created by user on 2021/5/9.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

/***
 * car 車子數量, amount 停車位數量, Park 停車場現況,  new 停車位重編後
 * */
void greedy_park(int L,const int Car[],const int Park[]){
    int left,right,cost = 0;
    int new[L];
    for (int i = 0; i < L; ++i) {
        if (new[i] != 0){//has car
            for (int j = 0; j < (L - i); ++j) {

            }
        }
    }
}

int main(){

    int i,j,car = 0, park = 0;
    int Car[MAX_SIZE] = {0};
    int Park[MAX_SIZE] = {0};
    printf("-----Car at Park-----\n");
    for (i = 0; ; i++) {
        scanf("%d",&Car[i]);
        if (Park[i] == -1)break;
        car++;
    }
    printf("-----Where can park-----\n");
    for (j = 0;; j++) {
        scanf("%d",&Park[j]);
        if (Park[j] == -1)break;
        park++
    }
    //*test*//
    /*
    printf("\n");
    for (int k = 0; k < i; ++k) {
        printf("%d ",Park[k]);
    }
    printf("\n");
    for (int k = 0; k < j; ++k) {
        printf("%d ",new[k]);
    }
    */
    if (i != j){
        printf("Error!\n");
    }else if(car > park)
        printf("Car Too MUCH!!!\n");
    else
        greedy_park(i, Car, Park);
}