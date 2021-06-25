//
// Created by user on 2021/5/23.
//
#include <stdio.h>
#include <string.h>
#include <math.h>

struct circle{
    int r,c;
    double left,right;
}typedef Circle;

double cal_dis(int r,float half_w){
    double d;
    d = sqrt(pow(r,2) - pow(half_w,2));//pow(x^y)

    return d;
}
void merge_sort_recursive(Circle A[],Circle tmp[],int start,int end){
    if(start >= end)return;
    int mid = (end+start)>>1;
    int start1 = start,end1 = mid;
    int start2 = mid + 1,end2 = end;
    merge_sort_recursive(A,tmp,start1,end1);
    merge_sort_recursive(A,tmp,start2,end2);
    //merge
    int k = start;
    while(start1<=end1 && start2<=end2){
        if(A[start1].left != A[start2].left)
            tmp[k]= A[start1].left < A[start2].left ?A[start1++]:A[start2++];
        else
            tmp[k]= A[start1].right < A[start2].right ?A[start1++]:A[start2++];
        k++;
    }
    while(start1<=end1){
        tmp[k] = A[start1];
        k++,start1++;
    }
    while(start2<=end2){
        tmp[k] = A[start2];
        k++,start2++;
    }
    for(k = start; k<=end;k++)
        A[k] = tmp[k];

}
void merge_sort(Circle A[],int len){
    Circle tmp[len];
    merge_sort_recursive(A,tmp,0,len-1);
}
void debug(Circle A[],int n){
    printf("--------- Debug --------\n");
    for (int i = 0; i < n; ++i) {
        printf("%d: ¥b®|->%d \t¤¤¤ß->%d \t ¥ª­­->%f \t ¥k­­->%f\n",i,A[i].r,A[i].c,A[i].left,A[i].right);
    }

}

void Solution_without_sort(Circle A[],int L,int n){
    int count = 0, flag = 1;
    double p = 0;
    double max = 0;
    while(p < L) {
        for (int i = 0; i < n; ++i) {// find right most
            if (A[i].left <= p && A[i].right > max) {
                max = A[i].right;
            }
        }
        if(max > p){
            p = max;
            count++;
        }else{
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("%d\n", count);
    else
        printf("-1\n");
    //debug(array,n);
}
void Solution_sort(Circle A[],int L,int n){
    merge_sort(A,n);
    int count = 0,index = -1, flag = 1,tmp;
    double p = 0;
    double max = 0;
    while(p <= L) {
        for (int i = index+1; i < n; ++i) {// find right most
            if (A[i].left <= p && A[i].right > max) {
                max = A[i].right;
                tmp = i;
            }
        }
        if(max > p){
            p = max;
            index = tmp;
            count++;
        }else{
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("%d\n", count);
    else
        printf("-1\n");
    //debug(array,n);
}
int main(){
    int n,L;
    float W;
    while(scanf("%d",&n)!=EOF) {
        scanf("%d %f", &L, &W);

        Circle array[n];
        memset(array, 0, sizeof(array));

        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &array[i].c, &array[i].r);
            double dis = cal_dis(array[i].r, W / 2);
            array[i].left = array[i].c - dis, array[i].right = array[i].c + dis;
        }
        //Solution_without_sort(array,L,n);
        //merge_sort(array, n);
        Solution_sort(array,L,n);
    }
}