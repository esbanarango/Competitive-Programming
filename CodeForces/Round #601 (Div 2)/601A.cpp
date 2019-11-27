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
  ll T, a, b, tmp, ans;
  scanf("%lld\n",&T);
  while(T--) {
    ans = 0;
    scanf("%lld %lld\n",&a,&b);
    if(a == b) { cout<<ans<<endl; continue; }
    if(a > b) { swap(a,b); }
    tmp = b - a;

    ans += tmp/5; tmp %= 5;
    ans += tmp/2; tmp %= 2;
    ans += tmp/1; tmp %= 1;

    cout<<ans<<endl;
  }

  return 0;
}