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
typedef map <int,int> mii;
typedef map <string,string> mss;
#define INF 1000000000

int main() {
  // freopen("in.in", "r", stdin);
  int t, n, m, ice, id_1, id_2; scanf("%d",&t);

  for(int test = 0; test < t; test++) {
    scanf("%d",&m);
    scanf("%d",&n);
    mii seen;
    for (int i = 0; i < n; i++){
      scanf("%d", &ice);
      if(seen.count(m-ice)){
        id_1 = i + 1;
        id_2 = seen[m-ice];
        if(id_2 < id_1)
          swap(id_1,id_2);
        printf("%d %d\n", id_1, id_2);
      }else{
        seen[ice] = i + 1;
      }
    }
  }
  return 0;
}