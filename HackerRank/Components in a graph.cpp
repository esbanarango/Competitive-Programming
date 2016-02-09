/*
  Components in a graph (50 Points)
  HackerRank
  Esteban Arango Medina

  Solution:
    A small change when initializing the `setSize` array of the UFDS data structure.
    We need to set it to -1 in order to properly get the smallest connected component.

  Notes.
    The Kadane's algorithm
      http://codeforces.com/blog/entry/13713
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
typedef map <string,string> mss;
#define INF 1000000000

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {
private:
  vi p, rank, setSize;
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, -1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (setSize[x] == -1) setSize[x] = 1;
    if (setSize[y] == -1) setSize[y] = 1;
    if (rank[x] > rank[y]) {
      p[y] = x; setSize[x] += setSize[y];
    }else{
      p[x] = y; setSize[y] += setSize[x];
      if (rank[x] == rank[y]) rank[y]++; }
    }
  }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main() {
  // freopen("in.in", "r", stdin);
  int smallest, largest, g, b, sizeG, sizeB, n, sz;
  smallest = INF;
  largest = 0;
  UnionFind UF(31000);
  scanf("%d",&n);
  for (int i = 0; i < n; ++i){
    scanf("%d %d", &g, &b);
    UF.unionSet(g, b);
  }
  for (int i = 1; i < (n*2)+1; ++i){
    sz = UF.sizeOfSet(i);
    if(sz != -1){
      largest = max(largest,sz);
      smallest = min(smallest,sz);
    }
  }

  printf("%d %d", smallest, largest);
  return 0;
}
