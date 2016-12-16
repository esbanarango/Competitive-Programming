
/*
  Esteban Arango Medina
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
typedef map <int,int> mii;
typedef map <string,string> mss;
#define INF 1000000000

#define DFS_WHITE -1 // normal DFS, do not change this with other values (other than 0), because we usually use memset with conjunction with DFS_WHITE
#define DFS_BLACK 1

vector<vii> AdjList;
vi dfs_num, dfs_low;
vi S, visited, clyces;
int numSCC, dfsNumberCounter;
bool valid = true;

void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  S.push_back(u);           // stores u in a vector based on order of visitation
  visited[u] = 1;
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE)
      tarjanSCC(v.first);
    if (visited[v.first])                                // condition for update
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
  }

  if (dfs_low[u] == dfs_num[u]) {         // if this is a root (start) of an SCC
    int total = 0;
    // printf("SCC %d:", ++numSCC);            // this part is done after recursion
    while (1) {
      total++;
      int v = S.back(); S.pop_back(); visited[v] = 0;
      // printf(" %d", v);
      if (u == v){
        if(total == 1 && AdjList[u][0].first != u){
          valid = false;
        }
        break;
      }
    }
    // printf(" TOTAL: %d \n", total);
    clyces.push_back(total % 2 == 0 ? total/2 : total);
  }
}

int gcd(int x, int y){
  while(x > 0 && y > 0){
    if(x > y)x %= y; else y %= x;
  }
  return x + y;
}

int lcm(int x, int y){
  return x * y / gcd(x, y);
}

int main(){
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);

  int V,id; scanf("%d",&V);
  V++;
  AdjList.assign(V, vii());
  for (int i = 1; i < V; ++i){
    scanf("%d", &id);
    AdjList[i].push_back(ii(id, 0));
  }

  dfs_num.assign(V, DFS_WHITE); dfs_low.assign(V, 0); visited.assign(V, 0);
  dfsNumberCounter = numSCC = 0;
  for (int i = 1; i < V && valid; i++)
    if (dfs_num[i] == DFS_WHITE)
      tarjanSCC(i);

  if(valid){
    int total = clyces[0];
    for (int i = 1; i < clyces.size(); ++i){
      total = lcm(total, clyces[i]);
    }
    printf("%d\n", total);
  }else{
    printf("-1\n");
  }

  return 0;

}