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
  int n,i=1;
  scanf("%d",&n);
  while(n--){
    vi salaries(3);
  	scanf("%d %d %d", &salaries[0], &salaries[1], &salaries[2]);
    sort(salaries.begin(), salaries.end());
    printf("Case %d: %d\n",i++,salaries[1]);
  }
 return 0;

}