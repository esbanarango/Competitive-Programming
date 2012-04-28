/*
  929 - Number Maze
  UVa Online Judge
  Esteban Arango Medina

    Solution.
        Graph on a 2D grid, a little changes on the classic Dijsktra implementation to store the position (x,y) and
        weight. Then straightforward.

*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,int> si;
typedef pair<int,ii> iii;
typedef vector <si> vsi;
typedef vector <ii> vii;
typedef vector <int> vi;
#define INF 1000000000


int posX[4]={-1,0,1,0};
int posY[4]={0,1,0,-1};

int N,M;

bool validPos(int x, int y){
    return ((x>=0 && x<N) && (y>=0 && y<M));
}

void dijkstra(iii s, vector<vi> *dist, vector<vi> *graph){
    priority_queue< iii, vector<iii>, greater<iii> > pq; 
    pq.push(s);
    while (!pq.empty()) {
        iii front = pq.top(); 
        pq.pop();
        int d = front.first; 
        ii u = front.second;
        if (d == dist->at(u.first)[u.second])
            for (int j = 0; j < 4; j++) {
                int newX =u.first + posX[j];
                int newY =u.second + posY[j];
                if(validPos(newX,newY)){
                    int v = graph->at(newX)[newY];                                     // all outgoing edges from u
                    if (dist->at(u.first)[u.second] + v < dist->at(newX)[newY]) {
                        dist->at(newX)[newY] = dist->at(u.first)[u.second]  + v;       // relax operation
                        ii newV (newX,newY);
                        pq.push(iii(dist->at(newX)[newY], newV));
                    }
                }
            } 
    }
}

int main(){
    int n,num;scanf("%d",&n);
    while(n--){
        scanf("%d",&N);
        scanf("%d",&M);
        vector<vi> graph;
        for (int i = 0; i < N; ++i)
        {
            vi row;
            for (int j = 0; j < M; ++j)
            {
                scanf("%d",&num);
                row.push_back(num);
            }
            graph.push_back(row);
        }
        vi rowIni(M,INF);
        vector<vi> dist (N,rowIni);
        dist[0][0] = graph[0][0];
        dijkstra(iii(graph[0][0],ii(0,0)),&dist,&graph);
        printf("%d\n",dist[N-1][M-1]);

    } 
 return 0;   

}