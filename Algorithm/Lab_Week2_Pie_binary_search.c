//
// Created by Tens on 2021/3/21.
//

#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
int conquer_pie(double pie[],int amount,int people,double mid){
    double pie_amount = 0;
    for(int i = 0;i != amount;i++){
        pie_amount = pie_amount +(int)(pie[i]/mid);
        if(pie_amount >= people)return 1;
    }
    return 0;
}
double divide_pie(double pie[],int amount,int people){
    double start = 0, end= 0, mid;
    for (int i = 0;i < amount;i++){
        end += pie[i];
    }
    end = end/people;
    while ( fabs(start-end)/2 > 1e-6){
        mid =  (start + end)/2;
        int r = conquer_pie(pie,amount,people,mid);
        if (r==1)//切太小
            start = mid ;
        else//切太大
            end = mid ;
    }
    return mid;
}
double round_i(double d){
    return round(d*1e4)/1e4;
}
int main(){
    int n_test;
    scanf("%d",&n_test);
    for(int i = 0; i != n_test; i++){
        int F = 0, N = 0;
        double total = 0,result;
        scanf("%d %d",&N,&F);
        double arr[N];
        int tmp;
        for(int j = 0; j != N; j++){
            scanf("%d",&tmp);
            arr[j]= tmp * tmp * PI;//轉體積丟入陣列
        }
        result = divide_pie(arr,N,F+1);//記得包含自己
        printf("%.4f\n",round_i(result));
    }
}