#include <stdio.h>
void sort_by_digit(int *A, int n, int r, int p)
{
    int base = 1; while (p > 0)
    {
        --p;
        base *= r;
    }
    int count[r], B[n] ;
    for (int j = 0; j < r; ++j)
        count[j] = 0;
    for (int i = 0; i < n; ++i) count[(A[i] / base) % r]++;
    for (int j = 0, psum = 0, sum = 0; j < r; ++j)
    {
        psum = sum;
        sum += count[j];
        count[j] = psum;
    }
    for (int i = 0; i < n; ++i)
        B[count[(A[i] / base) % r]++] = A[i];
    for (int i = 0; i < n; ++i)
        A[i] = B[i];
}

void radix_sort(int *A, int n, int r, int d)// *A=陣列, n = 元素個數, r = , d = 最高位數
{
    for (int i = d; i >0 ; --i) sort_by_digit(A, n, r, i);
}
int find(int max,int r){
    int tmp = max,t = 0;
    while(tmp > 0){
        tmp /= r;
        t++;
    }
    return t;
}
int main() {
    /*int a[10] = {9,2,4,3,10,11,104,2013,1002,24};
    radix_sort(a,10,2,11);
    for(int i = 0;i<10;++i){
        printf("%d ",a[i]);
    }*/
    int a = find(31,2);
    printf("%d",a);
    return 0;
}
