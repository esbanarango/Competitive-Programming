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
#define INF 10000000000

int main(){
  freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);

  ll n, a, b, c, k, min_r;
  cin>>n>>a>>b>>c;
  if(n%4 == 0)
    printf("0\n");
  else{
    for (k = 1; (n+k)%4 != 0; ++k);
    printf("k: %lld\n", k);
    min_r = k * a;
    if(k == 2)
      min_r = min(min_r,b);
    if(k == 3)
      min_r = min(min_r, min(b+a,c));
    cout<<min_r;
  }
  return 0;
}