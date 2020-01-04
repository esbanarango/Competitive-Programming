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
    map<pair<int, int>, int> times;
    int n, ans = 0, ascents = 0;
    cin>>n;
    rep(xx, 0, n) {
      bool ascent = false;
      int l, num, prev, maxx, minn;
      cin>>l;
      cin>>prev;
      maxx = prev;
      minn = prev;
      rep(i, 1, l) {
        cin>>num;
        if(prev < num) { ascent = true; }
        prev =  num;
        maxx = max(maxx, num);
        minn = min(minn, num);
      }
      if(ascent) {
        ans += n;
        ascents++;
      } else {
        times[{maxx, minn}]++;
        // if(minn != maxx){
        //   times[{minn, maxx}]++;
        // }
      }
    }
    deb(ans);
    deb(ascents);
    int i = 1;
    for(auto p: times){
      ans += (times.size() - i) * p.second;
      ans += ascents * p.second;
      if(p.first.first != p.first.second){
        ans += p.second;
      }
      i++;
      cout<< "{"<< p.first.first<<","<< p.first.second<<"} : "<<p.second<<endl;
    }
    cout<<ans<<endl;
  }
  return 0;
}