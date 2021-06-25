//
// Created by user on 2021/6/23.
//

//
// Created by user on 2021/6/14.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define INF 1e9
#define N 20


using namespace std;
double adj_matrix[N][N];
double c_tmp[N][N],nc_tmp[N][N];
bool visited[N];



double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}

double row_reduction(int flag){
    double low_bound = 0;
    if(flag == 0) {
        for (int i = 0; i < N; ++i) {
            double min = INF;
            for (int j = 0; j < N; ++j) {
                if (adj_matrix[i][j] < min && !visited[i])
                    min = adj_matrix[i][j];
            }
            for (int j = 0; j < N; ++j) {
                if(adj_matrix[i][j] != INF && !visited[i])
                    adj_matrix[i][j] -= min;
            }
            if (!visited[i])
                low_bound += min;
        }
    }else if(flag == 1) {
        for (int i = 0; i < N; ++i) {
            double min = INF;
            for (int j = 0; j < N; ++j) {
                if (c_tmp[i][j] < min && !visited[i])
                    min = c_tmp[i][j];
            }
            for (int j = 0; j < N; ++j) {
                if(c_tmp[i][j] != INF && !visited[i])
                    c_tmp[i][j] -= min;
            }
            if (!visited[i])
                low_bound += min;
        }
    }else{
        for (int i = 0; i < N; ++i) {
            double min = INF;
            for (int j = 0; j < N; ++j) {
                if (nc_tmp[i][j] < min && !visited[i])
                    min = nc_tmp[i][j];
            }
            for (int j = 0; j < N; ++j) {
                if(nc_tmp[i][j] != INF && !visited[i])
                    nc_tmp[i][j] -= min;
            }
            if (!visited[i])
                low_bound += min;
        }
    }

    return low_bound;
}

double col_reduction(int flag){

    double low_bound= 0;
    if(flag == 0) {
        for (int i = 0; i < N; ++i) {
            double min = INF;
            for (int j = 0; j < N; ++j) {
                if (adj_matrix[j][i] < min && !visited[i])
                    min = adj_matrix[j][i];
            }
            for (int j = 0; j < N; ++j) {
                if (adj_matrix[j][i] != INF && !visited[i])
                    adj_matrix[j][i] -= min;
            }
            if (!visited[i])
                low_bound += min;
        }
    }else if(flag == 1) {
        for (int i = 0; i < N; ++i) {
            double min = INF;
            for (int j = 0; j < N; ++j) {
                if (c_tmp[j][i] < min && !visited[i])
                    min = c_tmp[j][i];
            }
            for (int j = 0; j < N; ++j) {
                if (c_tmp[j][i] != INF && !visited[i])
                    c_tmp[j][i] -= min;
            }
            if (!visited[i])
                low_bound += min;
        }
    }else{
        for (int i = 0; i < N; ++i) {
            double min = INF;
            for (int j = 0; j < N; ++j) {
                if (nc_tmp[j][i] < min && !visited[i])
                    min = nc_tmp[j][i];
            }
            for (int j = 0; j < N; ++j) {
                if (nc_tmp[j][i] != INF && !visited[i])
                    nc_tmp[j][i] -= min;
            }
            if (!visited[i])
                low_bound += min;
        }
    }
    return low_bound;
}

int findmin(int i){
    int index;
    double min = INF;
    for (int j = 0; j < N; ++j) {
        if (adj_matrix[i][j] < min && !visited[j]){
            min = adj_matrix[i][j];
            index = j;
        }
    }
    return index;
}
void print(int flag){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << adj_matrix[i][j] <<" ";
        }
        cout<<endl;
    }
}

double dbst(double low,int from,int to){
    double c_low,nc_low;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            c_tmp[i][j] = adj_matrix[i][j];
            nc_tmp[i][j] = adj_matrix[i][j];
        }
    }
    // choose
    cout<<"ctest"<<endl;
    for (int i = 0; i < N; ++i) {
        c_tmp[from][i] = INF;
    }
    for (int i = 0; i < N; ++i) {
        c_tmp[i][to] = INF;
    }

    c_low = low + row_reduction(1) + col_reduction(1);

    //not choose
    cout<<"nctest"<<endl;
    nc_tmp[from][to] = INF;
    nc_low = low + row_reduction(2)+ col_reduction(2);

    cout<<c_low<<" "<<nc_low<<endl;
    if(c_low <= nc_low){
        visited[to] = true;
        cout<<"c"<<endl;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                adj_matrix[i][j] = c_tmp[i][j];
            }
        }
        cout<<"c"<<endl;
        int min = findmin(to);
        cout<<"c"<<endl;
        if (min!=INF && !visited[min]) {
            visited[min] = true;
            c_low += dbst(c_low, to, min);
        }
        cout<<"c:"<<c_low<<endl;
        return c_low;
    }else{
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                adj_matrix[i][j] = nc_tmp[i][j];
            }
        }
        nc_low += dbst(nc_low,from,to+1);
        cout<<"nc:"<<nc_low<<endl;
        return nc_low;
    }
}

double TSP(){
    double cost;
    //root lower bound
    cost = row_reduction(0) + col_reduction(0);
    // binary decision tree
    double result =0;
    int to = findmin(0);
    visited[0]=true;
    cout<<cost<<endl;
    result = dbst(cost,0,to);


    return result;
}



int main (){
    int id,x, y;
    memset(visited,0, sizeof(visited));
    double city[2][N]= {{0}};
    for (int i = 0; i < N; ++i) {
        cin >> id >> x >> y;
        city[0][id-1] = (double)x;
        city[1][id-1] = (double)y;
    }

    // create adj_matrix
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j)
                adj_matrix[i][j] = 0;
            else
                adj_matrix[i][j] = distance(city[0][i], city[1][i], city[0][j], city[1][j]);
        }
    }
    double result;
    result = TSP();

    printf( "%.3f\n", result);
}