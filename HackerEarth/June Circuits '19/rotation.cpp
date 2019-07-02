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
  int n, max_common = 0, current_common = 0;
  scanf("%d", &n);
  string S,T;
  cin>>S>>T;

  for (int i = n-1, j = n-1; i >= 0; i--, j--) {
    if(S[j] == T[i]) {
      current_common++;
      max_common = max(max_common, current_common);
    } else {
      if(j != n - 1){
        i++;
      }
      j = n;
      current_common = 0;
    }
  }

  printf("%d", n - max_common);
  return 0;
}