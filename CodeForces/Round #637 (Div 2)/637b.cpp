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
    int n, k;
    cin>>n>>k;
    vi mon(n);
    vi peaks(n, 0);
    rep(i, 0, n) { cin>>mon[i]; }
    rep(i, 1, n-1) {
      if(mon[i] > mon[i+1] && mon[i] > mon[i-1]) { peaks[i] = 1;}
    }
    int totalPeaks = 0, ansTotal = 0, ansL = 0;
    int l = 0, r = k-1;

    // Initial window
    rep(i, l, r) { totalPeaks += peaks[i]; }
    l++;
    ansTotal = totalPeaks;
    rep(i, r+1, n) {
      if(peaks[i-1] == 1) { totalPeaks++;}
      if(peaks[l] == 1) { totalPeaks--;}
      if(totalPeaks > ansTotal) {
        ansTotal = totalPeaks;
        ansL = l;
      }
      l++;
    }
    cout<<ansTotal+1<<" "<<ansL+1<<endl;
  }
  return 0;
}