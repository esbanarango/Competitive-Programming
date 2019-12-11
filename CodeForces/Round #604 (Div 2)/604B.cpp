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
typedef map <int,int> mii;
typedef map <string,int> msi;
typedef map <string,string> mss;
#define INF 1000000000
#define endl '\n' // Normal `cout << endl` flushes the output every time wich hit performance badly
#define deb(x) cout<<#x<<": "<<x<<endl;
#define printArray(arr) for(auto x: arr) { cout<<x<<", "; }
#define printMatrix(mat) for(auto x: mat) { cout<<" "; printArray(x); cout<<endl; }
#define printMap(mmap) for(auto p: mmap) { cout<< p.first<<": "<<p.second<<endl; }

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  ll T, N;
  cin>>T;
  while(T--) {
    cin>>N;
    vi P(N);
    mii positions;
    string ans (N, '0');
    ans[0] = ans[N-1] = '1';
    int onePosition;
    for(int i = 0; i < N; i++) { cin>>P[i]; positions[P[i]] = i; }
    int l = positions[1], r = positions[1];
    for(int i = 2; i <= N; i++){
      l = min(l, positions[i]);
      r = max(r, positions[i]);
      if(r - l + 1 == i) { ans[i-1] = '1'; } // That range should all i numbers
    }
    cout<<ans<<endl;
  }
  return 0;
}