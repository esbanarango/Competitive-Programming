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
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define endl '\n' // Normal `cout << endl` flushes the output every time wich hit performance badly
#define INF 1000000000
#define deb(x) cout<<#x<<": "<<x<<endl;
#define printArray(arr) for(auto x: arr) { cout<<x<<", "; }
#define printMatrix(mat) for(auto x: mat) { cout<<" "; printArray(x); cout<<endl; }
#define printMap(mmap) for(auto p: mmap) { cout<< p.first<<": "<<p.second<<endl; }

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  int T; cin>>T;
  while(T--) {
    int N, g, s, b;
    cin>>N;
    int totalMedals = N/2;
    vi p(N);
    vi order, medals(3, 0);
    mii total;
    rep(i, 0, N) {
      cin>>p[i];
      total[p[i]]++;
      if(total[p[i]] == 1) { order.pb(p[i]); }
    }
    // deb(totalMedals);
    for(int medal = 0, i = 0; i < order.size() && totalMedals > 0; i++) {
      if(totalMedals - total[order[i]] >= 0 ){
        medals[medal] += total[order[i]];
      }
      totalMedals -= total[order[i]];
      if(medal == 1 && medals[0] >= medals[1]) { continue; } // Keep adding to silver until it's greater than gold
      if(medal < 2) { medal++; }
    }
    if((medals[0] != 0 && medals[1] != 0 && medals[2] != 0) && (medals[0] < medals[1] && medals[0] < medals[2])) {
      cout<<medals[0]<<" "<<medals[1]<<" "<<medals[2]<<endl;
    } else {
      cout<<"0 0 0"<<endl;
    }
    // printArray(medals);
    // cout<<"-----------"<<endl;
    // printArray(order);
    // cout<<endl;
    // printMap(total);
    // cout<<endl;
  }

  return 0;
}