//
// Created by user on 2021/6/14.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#define INF 1e9

using namespace std;
double adj_matrix[20][20];
double dp[1 << 20][20];

double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}
void init(){
    for (int i = 0; i < 1<<20; ++i) {
        for (int j = 0; j < 20; ++j) {
            dp[i][j] = INF;
        }
    }

    for (int i = 0; i < 20; ++i) {
        dp[1<<i][i] = adj_matrix[0][i];
    }
}
double TSP( int status, int x ) {

    if ( dp[ status ][ x ] != INF )
        return dp[ status ][ x ];

    int mask = 1 << x;
    dp[ status ][ x ] = INF;

    for ( int i = 0; i < 20; ++i )
        if ( i != x && ( status & ( 1 << i ) ) )
            dp[ status ][ x ] = min( dp[ status ][ x ], TSP( status - mask, i ) + adj_matrix[ i ][ x ] );

    return dp[ status ][ x ];
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
    // initial dp array
    init();

    printf( "%.3f\n", TSP( ( 1 << 20 ) - 1, 0 ) );


}