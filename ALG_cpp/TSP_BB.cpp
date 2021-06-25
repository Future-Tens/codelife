//
// Created by user on 2021/6/14.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#define INF 1e9
#define N 20


using namespace std;

double adj_matrix[N][N];
int min_index[N];


double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}

struct Node{
    int lvl;
    int id;
    double bound;
    Node(int x,int level,double lb){
        id = x;
        lvl = level;
        bound = lb;
    }
    /** operator **/
    friend bool operator<(const Node &c1, const Node &c2) {
        return c1.bound < c2.bound;
    }
    friend bool operator>(const Node &c1, const Node &c2) {
        return c1.bound > c2.bound;
    }
};


void BB(int i,int count,double cur, priority_queue<Node, vector<Node>, greater<Node> > &less_q,set<int> S, double &ans) {
    S.erase(i);
    if (S.empty()){
        if(ans > cur + adj_matrix[i][0]) {
            ans = cur + adj_matrix[i][0];
        }
        return;
    }
    //new level
    double tmp;
    for (int j = 0; j < N; ++j) {
        tmp = 0;
        if(j != i && S.count(j) == 1){
            for (int k = 0; k < N; ++k) {
               if(k != i && S.count(k) == 1){
                   tmp += adj_matrix[k][min_index[k]];
               }
            }
            Node node(j,count+1,cur + adj_matrix[i][j] + tmp );//已經走過的距離 + 上一個點到這個點 + others vertexes min
            less_q.push(node);
            //cout << "push "<< node.id<<"("<<node.lvl<<")"<<"now: "<< node.bound<<endl;
        }
    }

    while (!less_q.empty() && !S.empty()) {
        Node min_node = less_q.top();
        less_q.pop();

        if (min_node.bound < ans && S.count(min_node.id) == 1 && min_node.lvl <= N) {
            priority_queue<Node, vector<Node>, greater<Node> > new_q;
            set<int> new_S = S;
            new_S.erase(min_node.id);
            BB(min_node.id, min_node.lvl, cur + adj_matrix[i][min_node.id], new_q,new_S, ans);
        }else
            break;
    }
}


void TSP(double &ans){

    set<int> S;
    for (int i = 0; i < N; ++i) {
        S.insert(i);
    }
    S.erase(0); //start
    priority_queue<Node, vector<Node>, greater<Node> > less_q;

    BB(0,1, 0,less_q,S,ans);
}



int main (){
    int id,x, y;
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
                adj_matrix[i][j] = INF;
            else
                adj_matrix[i][j] = distance(city[0][i], city[1][i], city[0][j], city[1][j]);
        }
    }
    int index;
    for (int i = 0; i < N; ++i) {
        double m = INF;
        for (int j = 0; j < N; ++j) {
            if (m > adj_matrix[i][j]) {
                m = adj_matrix[i][j];
                index = j;
            }
        }
        min_index[i] = index;
    }
    /*
    cout<<endl;
    for (int i = 0; i < N; ++i) {
        cout << min_index[i]<<endl;
    }
    cout<<endl;
     */
    double ans =INF;
    TSP(ans);
    printf( "%.3f\n", ans);
}