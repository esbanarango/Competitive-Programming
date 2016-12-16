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
typedef long double ld;
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
#define EPS 1e-9

bool AreSame(ld a, ld b){
    return fabs(a - b) < EPS;
}

int main(){
  // freopen("in.in", "r", stdin);
  int n,x,y,z; scanf("%d",&n);
  x = n;
  z = n+1;
  y = z*z - z;

  ld left = (ld)2/(ld)n;

  ld right = ((ld)1/(ld)x) + ((ld)1/(ld)z) + ((ld)1/(ld)y);

  // cout<< left<< " - "<<right<<endl;
  // cout<< AreSame(left,right) <<endl;
  // printf("%d %d %d\n",x,z,y);

  if(AreSame(left,right) && z!=y && y != x && x!=z){
    printf("%d %d %d\n",x,z,y);
  }else{
    printf("-1\n");
  }

  return 0;

}