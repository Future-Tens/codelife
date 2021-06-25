//
// Created by user on 2021/6/23.
//
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define INF 1e9
using namespace std;

double adj_matrix[20][20];
double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}

int main (){
    int id,x, y;
    double city[2][20]= {{0}};
    for (int i = 0; i < 20; ++i) {
        cin >> id >> x >> y;
        city[0][id-1] = (double)x;
        city[1][id-1] = (double)y;
    }

    // create adj_matrix
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (i == j)
                adj_matrix[i][j] = 0;
            else
                adj_matrix[i][j] = distance(city[0][i], city[1][i], city[0][j], city[1][j]);
        }
    }

    TSP();

    printf( "%.3f\n", result);


}