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
typedef map <string,string> mss;
#define INF 1000000000

int main(){
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  int n, current = 1, pos = 0, a, b;
  scanf("%d\n",&n);
  map<int, int> times;
  map<int, set<int> > neighbors;
  vi ans(n,0);
  for(int i = 0; i < n-2; i++) {
    vi neighbor(3);
    // Count how many times and select any first
    for(int j = 0; j < 3; j++) { cin>>neighbor[j]; times[neighbor[j]]++;}
    for(int j = 0; j < 3; j++) {
      int parent = neighbor[j];
      vi toSet = neighbor;
      toSet.erase(remove(toSet.begin(), toSet.end(), parent), toSet.end());
      neighbors[parent].insert(toSet.begin(), toSet.end());
    } // Associate neighbors
  }
  for(auto time: times){
    current = times[current] > time.second ? time.first : current;
  }
  // Initial set up
  queue<int> q;
  ans[pos++] = current;
  times[current] = -1;
  vi currentneighbors(neighbors[current].begin(), neighbors[current].end());
  a = times[currentneighbors[0]] < times[currentneighbors[1]] ? currentneighbors[0] : currentneighbors[1];
  b = times[currentneighbors[0]] > times[currentneighbors[1]] ? currentneighbors[0] : currentneighbors[1];
  ans[pos++] = a;
  ans[pos++] = b;
  q.push(a); times[a] = -1;
  q.push(b); times[b] = -1;

  while(pos < n) {
    current = q.front(); q.pop();
    currentneighbors = vi(neighbors[current].begin(), neighbors[current].end());
    for(auto nei: currentneighbors){
      if(times[nei] != -1){
        times[nei] = -1;
        q.push(nei);
        ans[pos++] = nei;
      }
    }
  }

  for(auto num:  ans) {cout << num << " "; }
  cout<<endl;
  return 0;
}