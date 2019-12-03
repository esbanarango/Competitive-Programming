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

  ll T, A, B;
  scanf("%lld\n",&T);

  while(T--) {
    scanf("%lld %lld\n",&A,&B);
    if(A > B) { swap(A,B); }
    if((A+B)%3 ==0 && A*2 >= B ) { cout<<"YES"<<endl; continue; }
    cout<<"NO"<<endl;
  }
  return 0;
}