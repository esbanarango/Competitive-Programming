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
#define printArray(arr) for(auto x: arr) { cout<<x<<" "; }
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
    if(k > n) { cout<<"NO"<<endl; continue; }
    if(n%k == 0) {
      cout<<"YES"<<endl;
      int ans = n/k;
      rep(i, 0, k) { cout<<ans<<" "; }
      cout<<endl;
    } else {
      int odd = (n - (k-1));
      int even = (n - (2 *(k-1)));
      // deb(odd);deb(even);
      if(odd > 0 && odd % 2 != 0){
        cout<<"YES"<<endl;
        cout<<odd<<" ";
        rep(i, 0, k-1) { cout<<1<<" "; }
      }else if(even > 0 && even % 2 == 0){
        cout<<"YES"<<endl;
        cout<<even<<" ";
        rep(i, 0, k-1) { cout<<2<<" "; }
      } else{
        cout<<"NO";
      }
      cout<<endl;
    }

  }
  return 0;
}