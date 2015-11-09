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
  int n;
  while(scanf("%d",&n) && n != 0) {
    int bet,max_sum,current_sum;
    current_sum = max_sum = 0;
    while(n--) {
      scanf("%d",&bet);
      current_sum = max(0,current_sum+bet);
      max_sum = max(max_sum,current_sum);
    }
    if(max_sum == 0) {
      printf("Losing streak.\n");
    }else {
      printf("The maximum winning streak is %d.\n",max_sum);
    }
  }
 return 0;
}