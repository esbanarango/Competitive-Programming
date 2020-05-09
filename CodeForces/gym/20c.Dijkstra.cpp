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

using ll=long long;
#define int ll

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
typedef map <char,int> mci;
typedef map <int,int> mii;
typedef map <string,string> mss;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define endl '\n' // Normal `cout << endl` flushes the output every time wich hit performance badly
#define INF 1000000000
#define deb(x) cout<<#x<<": "<<x<<endl;
#define printArray(arr) for(auto x: arr) { cout<<x<<", "; }
#define printMatrix(mat) for(auto x: mat) { cout<<" "; printArray(x); cout<<endl; }
#define printMap(mmap) for(auto p: mmap) { cout<< p.first<<": "<<p.second<<endl; }

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); // Fast input
  #ifdef LOCAL_PROJECT
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
  #endif

  int T = 1; //cin>>T;
  while(T--) {
    int n, m; cin>>n>>m;
    map<int,vector<ii>> graph;
    rep(i, 0, m) {
      int a, b, w; cin>>a>>b>>w;
      graph[a-1].pb({w, b-1});
      graph[b-1].pb({w, a-1});
    }
    vector<bool> visited(n);
    vi distances(n, -1);
    vi path(n);
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push({0, 0});
    distances[0] = 0;
    while(!pq.empty()) {
      ii current = pq.top(); pq.pop();
      int d = current.first, u = current.second;
      if(visited[u]) { continue; }
      visited[u] = true;
      for(const auto node: graph[u]){
        if(distances[node.second] == -1 || d + node.first < distances[node.second]) {
          distances[node.second] = d + node.first;
          path[node.second] = u;
          pq.push({distances[node.second], node.second});
        }
      }
    }
    if(distances[n-1] == -1) { cout<<-1<<endl; continue; }
    vi ans;
    int parent = path[n-1];
    ans.pb(n-1);
    ans.pb(parent);
    while(parent != 0){
      parent = path[parent];
      ans.pb(parent);
    }
    per(i, 0, ans.size()){
      cout<<ans[i]+1<<" ";
    }
    cout<<endl;
  }
  return 0;
}