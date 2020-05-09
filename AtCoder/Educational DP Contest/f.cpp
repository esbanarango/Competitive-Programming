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

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); // Fast input
  #ifdef LOCAL_PROJECT
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
  #endif

  int T = 1; //cin>>T;
  while(T--) {
    string s, t;
    cin>>s;
    cin>>t;
    int n = s.size(), m = t.size();
    vector<vi> DP(n, vi(m, 0));
    DP[0][0] = s[0] == t[0] ? 1 : 0;
    rep(i, 1, n) { DP[i][0] = (s[i] == t[0]) ? 1 : DP[i-1][0]; }
    rep(j, 1, m) { DP[0][j] = (s[0] == t[j]) ? 1 : DP[0][j-1]; }

    rep(i, 1, n) {
      rep(j, 1, m) {
        DP[i][j] = (s[i] == t[j]) ? DP[i-1][j-1] + 1 : max(DP[i-1][j], DP[i][j-1]);
      }
    }
    // printMatrix(DP);
    string ans;
    int i = n-1, j = m-1;
    while(ans.size() < DP[n-1][m-1] && i >= 0 && j >= 0) {
      if(s[i] == t[j]) { ans.pb(s[i]); i--; j--; continue; }
      if(i - 1 >= 0 && DP[i-1][j] >= DP[i][j-1]) { i--; } else { j--; }
    }
    reverse(all(ans));
    cout<<ans;
  }
  return 0;
}