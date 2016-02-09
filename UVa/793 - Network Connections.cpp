/*
  793 - Network Connections
  UVa Online Judge
  Esteban Arango Medina

    Solution.
        Perfect use case for Union-Find Disjoint Sets.

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
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main(){
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);

  int cases, computers, c1, c2, sucess, fail;
  string line;

  scanf("%d",&cases);
  while(cases--) {
    sucess = fail = 0;
    scanf("\n%d\n",&computers);
    UnionFind UF(computers+1);
    char ch;
    while(true){
      if(!getline(cin,line) || line.empty()) break;
      sscanf(line.c_str(),"%c %d %d",&ch,&c1,&c2);
      if(ch == 'c') {
        UF.unionSet(c1, c2);
      }else {
        UF.isSameSet(c1, c2) ? sucess++ : fail++;
      }
    }
    printf("%d,%d\n", sucess, fail);
    if(cases != 0) printf("\n");
  }
  return 0;
}