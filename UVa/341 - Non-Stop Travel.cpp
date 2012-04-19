/*
  341 - Non-Stop Travel
  UVa Online Judge
  Esteban Arango Medina

    Solution.
        SSSP on Weighted graph and print the route. Actually solvable using Floyd-Warshall's. I used
        Dijkstra :).

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
typedef vector <ii> vii;
typedef vector <int> vi;
#define INF 1000000000

int route [12];

void dijkstra(int s, vi *dist, vector<vii> *graph){
    priority_queue< ii, vector<ii>, greater<ii> > pq; 
    pq.push(ii(0, s));
    while (!pq.empty()) {
        ii front = pq.top(); 
        pq.pop();
        int d = front.first, u = front.second;
        if (d == dist->at(u))
            for (int j = 0; j < (int)graph->at(u).size(); j++) {
                ii v = graph->at(u)[j];                                     // all outgoing edges from u
                if (dist->at(u) + v.second < dist->at(v.first)) {
                    dist->at(v.first) = dist->at(u) + v.second;             // relax operation
                    route[v.first]=u;
                    pq.push(ii(dist->at(v.first), v.first));
                }
            } 
    }
}

void printPath(int s, int t)
{
    if(s==t){printf("%d",t); return;}
    printPath(route[s],t);
    printf(" %d",s);
}

int main(){
    int N,cases=1;
    while(scanf("%d",&N) && N){
        memset(route,-1,sizeof route);
        vector<vii> graph (N+1,vii());
        //Read graph
        for(int i = 1; i<=N;i++)
        {   
            int relations,v,w;
            scanf("%d",&relations);
            for (int j = 0; j < relations; ++j)
            {
                scanf("%d %d",&v,&w);
                graph[i].push_back(ii(v, w)); 
            }
        }

        int s,t;

        scanf("%d %d",&s,&t);
        vi dist(N+1, INF);
        dist[s] = 0;
        dijkstra(s,&dist,&graph);
        printf("Case %d: Path = ",cases++);
        printPath(t,s);
        printf("; %d second delay\n",dist[t]);

 
    }


 return 0;   

}