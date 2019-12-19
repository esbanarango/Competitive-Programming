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
typedef map <char,int> mci;
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
  int t; cin>>t;
  string one = "one", two = "two";
  while(t--) {
    string s; cin>>s;
    vi ind;
    int o = 0, t = 0;
    rep(i, 0, s.size()) {
      if(s[i] == one[o]) { o++; } else { o = 0; if(s[i] == one[o]) { o++; } }
      if(s[i] == two[t]) { t++; } else { t = 0; if(s[i] == two[t]) { t++; } }
      if(o == 3 || t == 3) {
        if(i+1 < s.size() && s[i] != s[i+1]){ // Make sure to delete the correct one
          ind.pb(i+1);
        } else {
          ind.pb(i);
        }
        o=0; t=0;
      }
    }
    cout<<ind.size()<<endl;
    rep(i, 0, ind.size()) { cout<<ind[i]<<" "; }
    cout<<endl;
  }
  return 0;
}