//
// Created by user on 2021/3/29.
// Reference https://www.itread01.com/content/1547954848.html
//
#include <stdio.h>
#include <math.h>

struct Point{
    int x,y;
};

double min(double a,double b);
double cal_dis(struct Point a, struct Point b);
void pick_sort(struct Point p[],int A[],int n);

double Closest_Pair(struct Point p[], int L, int R,int pick[]){
    double dis = 1e10;
    if (L == R)return dis;
    if (R-L == 1)return cal_dis(p[L],p[R]);
    int mid = (L+R)>>1;
    double dis_L = Closest_Pair(p,L,mid,pick);
    double dis_R = Closest_Pair(p,mid+1,R,pick);
    dis = min(dis_L,dis_R);
    int i,j,k = 0;
    for (i = L;i <= R;i++) {
        if (abs(p[mid].x - p[i].x) <= dis)
            pick[k++] = i;
    }
    pick_sort(p,pick,k);
    for(i = 0;i<k;i++){
        for (j = i+1;j<k && p[pick[j]].y - p[pick[i]].y < dis;j++){
            double dis_ij = cal_dis(p[pick[i]],p[pick[j]]);
            if (dis > dis_ij)
                dis = dis_ij;
        }
    }
    return dis;
}

double min(double a,double b) {
    if (a>b)return b;
    return a;
}
double cal_dis(struct Point a, struct Point b){
    return sqrt(((a.x-b.x)*(a.x-b.x))
                + ((a.y-b.y)*(a.y-b.y)));
}

void pick_sort(struct Point p[],int A[],int n){
    if (n == 0)return;
    int tmp, flag = 1;
    for(int i = 0;flag == 1 && i < n-1;i++)
    {
        flag = 0;
        for(int j = 0;j < n-1-i;j++)
        {
            if(p[A[j]].y>p[A[j+1]].y)
            {
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
                flag = 1;
            }
        }
    }
}
void merge_sort_recursive(struct Point A[],struct Point tmp[],int start,int end){
    if(start >= end)return;
    int mid = (end+start)>>1;
    int start1 = start,end1 = mid;
    int start2 = mid + 1,end2 = end;
    merge_sort_recursive(A,tmp,start1,end1);
    merge_sort_recursive(A,tmp,start2,end2);
    //merge
    int k = start;
    while(start1<=end1 && start2<=end2){
        if(A[start1].x != A[start2].x)
            tmp[k]= A[start1].x < A[start2].x ?A[start1++]:A[start2++];
        else
            tmp[k]= A[start1].y < A[start2].y ?A[start1++]:A[start2++];
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
void merge_sort(struct Point A[],int len){
    struct Point tmp[len];
    merge_sort_recursive(A,tmp,0,len-1);
}

int main(){
    int n = 0;
    scanf("%d",&n);
    while(1){
        if (n==0)break;
        struct Point p[n];
        int pick[10005]={0};
        int i;
        for(i = 0; i<n; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            p[i].x = x;
            p[i].y = y;
        }
        merge_sort(p,n);
        double d = Closest_Pair(p,0,n-1,pick);
        if(d < 10000)
            printf("%.4f\n",d);
        else
            printf("INFINITY\n");
        scanf("%d",&n);
    }
}
