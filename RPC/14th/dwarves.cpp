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
typedef map <int,vi> mivi;
typedef map <string,string> mss;
#define INF 1000000000
#define DFS_WHITE -1 // normal DFS, do not change this with other values (other than 0), because we usually use memset with conjunction with DFS_WHITE
#define DFS_BLACK 1
mivi grap;
vi dfs_num, dfs_low, visited, S;
int dfsNumberCounter, numSCC;

bool cycle = false;

void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  S.push_back(u);           // stores u in a vector based on order of visitation
  visited[u] = 1;
  for (int j = 0; j < (int)grap[u].size(); j++) {
    int v = grap[u][j];
    if (dfs_num[v] == DFS_WHITE)
      tarjanSCC(v);
    if (visited[v])                                // condition for update
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  if (dfs_low[u] == dfs_num[u]) {         // if this is a root (start) of an SCC
    int total = 0;
    while (1) {
      total++;
      int v = S.back(); S.pop_back(); visited[v] = 0;
      if (u == v || total > 1) break;
    }
    if(total > 1) cycle = true;
  }
}

int main(){
  // freopen("in.in", "r", stdin);
  int n; scanf("%d",&n);
  string d1,symbol,d2,temp;
  msi numbers;
  int i = 0;
  // Read the graph
  while(n--) {
    cin>>d1>>symbol>>d2;
    if(symbol == "<"){
      temp = d1;
      d1 = d2;
      d2 = temp;
    }
    if(!numbers.count(d1))
      numbers[d1] = ++i;
    if(!numbers.count(d2))
      numbers[d2] = ++i;
    if(!grap.count(numbers[d1])){
      vi nodes;
      grap[numbers[d1]] = nodes;
    }
    grap[numbers[d1]].push_back(numbers[d2]);
  }
  dfs_num.assign(numbers.size()+1, DFS_WHITE); dfs_low.assign(numbers.size()+1, 0); visited.assign(numbers.size()+1, 0);
  dfsNumberCounter = numSCC = 0;
  for (msi::iterator it=numbers.begin(); it!=numbers.end(); ++it)
    if (dfs_num[it->second] == DFS_WHITE && !cycle)
      tarjanSCC(it->second);

  if(cycle)
    printf("impossible\n");
  else
    printf("possible\n");

  return 0;
}