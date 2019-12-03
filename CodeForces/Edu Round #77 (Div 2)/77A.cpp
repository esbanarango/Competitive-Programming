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

int main() {
  // freopen("in.in", "r", stdin);

  ll N, C, SUM;
  scanf("%lld\n",&N);

  while(N--) {
    ll ans = 0;
    scanf("%lld %lld\n",&C,&SUM);
    if(C >= SUM) {
      cout<<SUM<<endl;
      continue;
    }
    ll sim = SUM/C;
    ll first = (SUM - (sim * C));
    ll rem = SUM%C;

    if(rem == 0){
      ans = (C * (sim * sim));
    } else {
      ll toAdd = rem / first;

      ans = ((C - first) * (sim * sim)) + (first * ((sim + toAdd) * (sim + toAdd)));
    }
    cout<<ans<<endl;
  }

  return 0;
}