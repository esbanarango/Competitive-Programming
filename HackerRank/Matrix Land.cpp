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
typedef vector<int> vi;
typedef vector<vi> vivi;
typedef pair<int,int> ii;
typedef vector <ii> vii;
typedef vector<vii> vivii;

#define MAX_V 5000000 // enough for sample graph in Figure 4.24/4.25/4.26/UVa 259
#define INF 1000000000

int res[MAX_V][MAX_V], mf, f, s, t;                          // global variables
vi p;
vivi AdjList;

void augment(int v, int minEdge) {     // traverse BFS spanning tree from s to t
  cout<<"v:"<<v<<", s:"<<s<<", p[v]"<<p[v]<<endl;
  if (v == s) { f = minEdge; return; }  // record minEdge in a global variable f
  else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v])); // recursive
                         res[p[v]][v] -= f; res[v][p[v]] += f; }       // update
}

int main() {
  freopen("in.in", "r", stdin);
  int n, m, result, k;
  scanf("%d %d", &n, &m);
  // cout<<n<<" "<<m<<endl;
  vivii matriz(n,vii(m));

  k = 1;
  // read data
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j, ++k){
      scanf("%d", &matriz[i][j].first);
      // matriz[i][j].first += 251;
      matriz[i][j].second = k;
    }
  }

  // build the graph
  int V, vertex, weight;
  V = (n*m) + 2;
  s = 0;
  t = V-1;
  // memset(res, 0, sizeof res);
  AdjList.assign(V, vi());
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      weight = matriz[i][j].first;
      k = matriz[i][j].second;
      // cout<<"I'm in: "<<k<<"("<<weight<<")"<<endl;
      if(i + 1 < n){
        vertex = matriz[i+1][j].second;
        res[k][vertex] = weight;
        AdjList[k].push_back(vertex);
      }
      if(j + 1 < m){
        vertex = matriz[i][j+1].second;
        res[k][vertex] = weight;
        AdjList[k].push_back(vertex);
      }
      if(j-1 >= 0){
        vertex = matriz[i][j-1].second;
        res[k][vertex] = weight;
        AdjList[k].push_back(vertex);
      }
    }
  }
  // add fake source
  for (int j = 0; j < m; ++j){
    vertex = matriz[0][j].second;
    res[0][vertex] = 251;
    AdjList[0].push_back(vertex);
  }
  // add fake t
  for (int j = 0; j < m; ++j){
    vertex = matriz[n-1][j].second;
    res[vertex][t] = 251;
    AdjList[vertex].push_back(t);
  }

  // print graph
  for (int i = 0; i < V; ++i){
    printf("\nOne node %d: \n", i);
    for (int j = 0; j < AdjList[i].size(); ++j){
      printf(" %d - (%d)", AdjList[i][j], res[i][AdjList[i][j]]);
    }
  }

  // edmonds karp
  mf = 0;
  while (1) {                     // now a true O(VE^2) Edmonds Karp's algorithm
    f = 0;
    bitset<MAX_V> vis; vis[s] = true;            // we change vi dist to bitset!
    queue<int> q; q.push(s);
    p.assign(MAX_V, -1);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break;
      for (int j = 0; j < (int)AdjList[u].size(); j++) {  // we use AdjList here!
        int v = AdjList[u][j];
        cout<<"El v: "<<v<<endl;
        if (res[u][v] > 0 && !vis[v])
          vis[v] = true, q.push(v), p[v] = u;
      }
    }
    cout<<"El t:"<<t<<endl;
    augment(t, INF);
    if (f == 0) break;
    mf += f;
  }
  printf("%d\n", mf);                              // this is the max flow value
  return 0;
}
