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

  int T = 1; cin>>T;
  while(T--) {
    int n, k; cin>>n>>k;
    vector<vector<vector<int>>> oddAndEven(2);
    vi nums(n+1);
    vector<bool> visited(n+1, false);
    rep(i, 1, n+1) { cin>>nums[i]; }
    // Build the graphs and put them on the right bucket
    rep(i, 1, n+1) {
      int j = nums[i];
      if(j != i && !visited[j]) {
        visited[i] = true; visited[j] = true;
        vector<int> lizt;
        lizt.pb(i); lizt.pb(j);
        while(!visited[nums[j]]) {
          lizt.pb(nums[j]);
          j = nums[j];
          visited[j] = true;
        }
        if(lizt.size() % 2 == 0) { oddAndEven[1].pb(lizt); } else { oddAndEven[0].pb(lizt);}
      }
    }

    if(oddAndEven[1].size() % 2 != 0) { cout<<-1<<endl; continue; }
    vector<vi> moves;
    int ans = 0;
    // Process all evens
    while(oddAndEven[1].size() >= 2) {
      auto lizt1 = oddAndEven[1][0];
      auto lizt2 = oddAndEven[1][1];
      moves.pb({lizt1[0], lizt2[0], lizt2[1]}); ans++;
      if(ans > k) { break; }
      lizt2.pb(lizt2[0]);
      lizt2.erase(lizt2.begin(),lizt2.begin()+2);
      lizt2.insert(lizt2.begin(),lizt1[0]);

      lizt1.erase(lizt1.begin());
      lizt2.insert(lizt2.end(), lizt1.begin(), lizt1.end());
      oddAndEven[0].pb(lizt2);
      oddAndEven[1].erase(oddAndEven[1].begin(),oddAndEven[1].begin()+2);
    }
    if(ans > k) { cout<<-1<<endl; continue; }
    // Process all odds
    for(auto lizt: oddAndEven[0]) {
      if(lizt.size() == 3){ moves.pb(lizt); ans++; continue; }
      while(lizt.size() > 4) {
        auto it = lizt.begin();
        moves.pb({*it, *(it+1), *(it + 2)});
        lizt.erase(lizt.begin()+1,lizt.begin()+3);
        ans++;
      }
      moves.pb(lizt); ans++;
      if(ans > k) { break; }
    }
    if(ans > k) {
      cout<<-1<<endl;
    } else {
      cout<<ans<<endl;
      for(const auto move: moves) {
        cout<<move[0]<<" "<<move[1]<<" "<<move[2]<<endl;
      }
    }
  }
  return 0;
}