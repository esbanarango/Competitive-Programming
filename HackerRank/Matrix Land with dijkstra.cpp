#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vivi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vivii;

map<int, int> route;

#define INF 1000000000

void printpath(int a, int b) {
  if (a == b) {
    printf("%d", b);
    return;
  }
  printpath(route[a], b);
  printf(" %d", a);
}

int main() {
  freopen("in.in", "r", stdin);
  int n, m, result, k, s, t;
  scanf("%d %d", &n, &m);
  // cout<<n<<" "<<m<<endl;
  vivii matriz(n, vii(m));
  vivii AdjList;

  k = 1;
  // read data
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j, ++k) {
      scanf("%d", &matriz[i][j].first);
      matriz[i][j].first *= -1;
      matriz[i][j].first += 251;
      matriz[i][j].second = k;
    }
  }

  // build the graph
  int V, vertex, weight;
  V = (n * m) + 2;
  s = 0;
  t = V - 1;

  AdjList.assign(V, vii());
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      weight = matriz[i][j].first;
      k = matriz[i][j].second;
      // cout<<"I'm in: "<<k<<"("<<weight<<")"<<endl;
      if (i + 1 < n) {
        vertex = matriz[i + 1][j].second;
        AdjList[k].push_back(ii(vertex, weight));
      }
      if (j + 1 < m) {
        vertex = matriz[i][j + 1].second;
        AdjList[k].push_back(ii(vertex, weight));
      }
      if (j - 1 >= 0) {
        vertex = matriz[i][j - 1].second;
        AdjList[k].push_back(ii(vertex, weight));
      }
    }
  }
  // add fake source
  for (int j = 0; j < m; ++j) {
    vertex = matriz[0][j].second;
    AdjList[0].push_back(ii(vertex, 0));
  }
  // add fake t
  for (int j = 0; j < m; ++j) {
    vertex = matriz[n - 1][j].second;
    AdjList[vertex].push_back(ii(t, 0));
  }

  // print graph
  for (int i = 0; i < V; ++i) {
    printf("\nOne node %d: \n", i);
    for (int j = 0; j < AdjList[i].size(); ++j) {
      printf(" %d - (%d)", AdjList[i][j].first, AdjList[i][j].second);
    }
  }

  // Dijkstra routine
  vi dist(V, INF);
  dist[s] = 0;  // INF = 1B to avoid overflow
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  pq.push(ii(0, s));
  // ^to sort the pairs by increasing distance from s
  while (!pq.empty()) {  // main loop
    ii front = pq.top();
    pq.pop();  // greedy: pick shortest unvisited vertex
    int d = front.first, u = front.second;
    if (d > dist[u]) continue;  // this check is important, see the explanation
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      ii v = AdjList[u][j];  // all outgoing edges from u
      if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second;  // relax operation
        route[v.first] = u;
        pq.push(ii(dist[v.first], v.first));
      }
    }
  }  // note: this variant can cause duplicate items in the priority queue

  for (int i = 0; i < V; i++)  // index + 1 for final answer
    printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);

  printpath(21, 0);
  return 0;
}
