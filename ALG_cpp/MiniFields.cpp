//
// Created by user on 2021/6/23.
//

#include <iostream>
#include <cstring>

using namespace std;

int m,n;

void allocArray(int ***p)
{
    int **array;
    array = (int **)malloc(sizeof(int*)*m);
    int *size =  (int *)malloc(sizeof(int)*n*m);
    for(int i = 0;i != m;i++){
        array[i] = size ;
        size += n;
    }
    *p=array;
}

int dfs(int **map, int i , int j){
    int result = 1;

    if(j+1 < n && map[i][j+1] == 1) {
        map[i][j+1] = 2;
        result += dfs(map, i, j+1);
        //cout<< "right : "<<result<<endl;
    }
    if( i+1 < m && map[i+1][j] == 1) {
        map[i+1][j] = 2;
        result += dfs(map, i+1, j);
        //cout<< "down : "<<result<<endl;
    }
    if(i-1 >= 0 && map[i-1][j] == 1) {
        map[i-1][j] = 2;
        result += dfs(map, i-1, j);
        //cout<< "top : "<<result<<endl;
    }
    if(j-1 >= 0 && map[i][j-1] == 1) {
        map[i][j-1] = 2;
        result += dfs(map, i, j-1);
        //cout<< "left : "<<result<<endl;
    }

    return result;
}

int main(){
    m = -1,n = -1;
    string c;

    getline(cin,c);
    for (int i = 0; i < 20; ++i) {
        if('0'<=c[i]&& c[i]<='9'&& m==-1){
            m = c[i] - 48;
        }
        else if('0'<=c[i]&& c[i]<='9'&& m!=-1){
            n = c[i] - 48;
        }
    }

    //cout<< "m: "<<m<<" n: "<<n<<endl;

    int **map;
    allocArray(&map);
    for (int i = 0; i < m; ++i) {
        int count= 0;
        getline(cin,c);
        for (int j = 0;; ++j) {
            if(count == n)break;
            if('0'<=c[j]&& c[j]<='9'){
                map[i][count] = c[j]-48;
                count++;
            }
        }
    }
    getline(cin,c);


    int max = 0,tmp;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(map[i][j] == 1){
                map[i][j] = 2;
                tmp = dfs(map,i,j);
                if (max < tmp){
                    max = tmp;
                }
            }
        }
    }
    cout << max <<endl;
}