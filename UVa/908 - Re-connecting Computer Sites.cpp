/*
  908 - Re-connecting Computer Sites
  UVa Online Judge
  Esteban Arango Medina

    Solution.
        MST using Prims algo.

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
#include <bitset>
#include <cmath>
#include <queue>
#include <tuple>
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
typedef vector <char> vc;
typedef vector <string> vs;
typedef map <string,vs> msvs;
typedef map <string,int> msi;
typedef map <string,string> mss;
#define INF 1000000000

void process(int vtx, vector<vii> &graph, vi &taken, priority_queue<ii> &pq) {    // so, we use -ve sign to reverse the sort order
  taken[vtx] = 1;
  for (int j = 0; j < (int)graph[vtx].size(); j++) {
    ii v = graph[vtx][j];
    if (!taken[v.first]) pq.push(ii(-v.second, -v.first));
  }
}                                // sort by (inc) weight then by (inc) id

int prims(vector<vii> &graph, vi &taken, priority_queue<ii> &pq){
  process(0, graph, taken, pq);   // take vertex 0 and process all edges incident to vertex 0
  int mst_cost = 0, u, w;
  while (!pq.empty()) {  // repeat until V vertices (E=V-1 edges) are taken
    ii front = pq.top(); pq.pop();
    u = -front.second, w = -front.first;  // negate the id and weight again
    if (!taken[u])                 // we have not connected this vertex yet
      mst_cost += w, process(u, graph, taken, pq); // take u, process all edges incident to u
  }                                        // each edge is in pq only once!
  return mst_cost;
}




int main(){
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  int n, k, m, u, v, w, cost, tmp;
  bool first = true;
  while (scanf("%d",&n) != EOF){
    if(!first){
      printf("\n");
    }
    first = false;
    vector<vii> graph(n);
    vi taken(n);
    priority_queue<ii> pq;
    int total_k = 0, new_k;

    // The set T of previously chosen high-speed lines
    for (int i = 0; i < n-1; ++i){
      scanf("%d %d %d", &tmp, &tmp, &cost);
      total_k += cost;
    }
    // The number K of new additional lines
    scanf("%d", &k);
    for (int i = 0; i < k; ++i){
      scanf("%d %d %d", &u,&v,&w);
      u--;v--;
      graph[u].push_back(ii(v, w));
      graph[v].push_back(ii(u, w));
    }
    // The number M of originally available high-speed lines
    scanf("%d", &m);
    for (int i = 0; i < m; ++i){
      scanf("%d %d %d", &u,&v,&w);
      u--;v--;
      graph[u].push_back(ii(v, w));
      graph[v].push_back(ii(u, w));
    }
    new_k = prims(graph, taken, pq);

    printf("%d\n%d\n",total_k, new_k);
  }

 return 0;
}