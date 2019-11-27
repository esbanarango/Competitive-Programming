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
typedef map <string,string> mss;
#define INF 1000000000

int main(){
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  int T, n, m, ans;
  scanf("%d\n",&T);
  while(T--) {
    ans = 0;
    scanf("%d %d\n",&n,&m);
    vii a(n);
    for(int i = 1; i <= n; i++) {
      ii fridge = {0, i};
      cin>>fridge.first;
      a[i-1] = fridge;
    }
    if(n>m || n == 2) { cout<<"-1"<<endl; continue; }
    sort(a.begin(), a.end());
    // Connect them all
    ans += a[0].first + a[n-1].first;
    for(int i = 1; i < n; i++) { ans += a[i-1].first + a[i].first; }
    // Remaining chains
    int missing = m - n;
    ans += (a[0].first + a[1].first) * missing;
    cout<<ans<<endl;

    for(int i = 1; i < n; i++) { cout<< a[i-1].second<<" "<<a[i].second<<endl; }
    cout<<a[n-1].second<<" "<<a[0].second<<endl;
    for(int i = 0; i < missing; i++) { cout<<a[0].second<<" "<<a[1].second<<endl; }
  }
  return 0;
}