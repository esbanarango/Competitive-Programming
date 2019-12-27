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
  int T; cin>>T;
  while(T--) {
    ll n, coins, k, ans = 0;
    cin>>n>>coins>>k;

    vi goods;
    vector <pair<ll,ll> > dp(n+1);
    dp[0] = {0,0};
    rep(i, 0, n) {
      int g; cin>>g;
      if(g <= coins) { goods.pb(g); }
    }
    sort(goods.begin(), goods.end());
    rep(i, 1, goods.size()+1) {
      ll rem = coins;
      ll total = 1;
      rem -= goods[i-1];
      int canTake = k;
      int j = i;
      if(i-(k-1) > 0){
        total += k-1;
      }

      if(i-2>0 && dp[i-2].second <= rem){
        total += dp[i-2].first;
        rem -= dp[i-2].second;
      }
      // deb(total);
      if(total > dp[i-1].first){
        dp[i] = { total, coins - rem };
      }else{
        dp[i] = {dp[i-1].first, dp[i-1].second};
      }
      ans = max(ans, dp[i].first);
    }
    if(ans > goods.size()){
      ans = goods.size();
    }
    // for(auto p: dp) {  cout<< p.first<<": "<<p.second<<endl; }
    // cout<<endl;
    // printArray(goods);
    // cout<<endl;
    cout<<ans<<endl;
  }
  return 0;
}