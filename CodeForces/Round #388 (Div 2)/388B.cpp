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
  int a1,a2,b1,b2,c1,c2;
  scanf("%d %d",&a1,&a2);
  scanf("%d %d",&b1,&b2);
  scanf("%d %d",&c1,&c2);

  printf("3\n");

  printf("%d %d\n",a1-b1+c1,a2-b2+c2);
  printf("%d %d\n",b1-a1+c1,b2-a2+c2);
  printf("%d %d\n",a1-c1+b1,a2-c2+b2);

  return 0;
}