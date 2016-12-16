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

int main() {
  // freopen("in.in", "r", stdin);
  vi tring1(3), tring2(3);
  scanf("%d %d %d",&tring1[0], &tring1[1], &tring1[2]);
  scanf("%d %d %d",&tring2[0], &tring2[1], &tring2[2]);
  sort(tring1.begin(), tring1.end());
  sort(tring2.begin(), tring2.end());
  bool result = ((tring1[2] * tring1[2]) == (tring1[0] * tring1[0]) + (tring1[1] * tring1[1]));
  if(result && tring1[0] == tring2[0] && tring1[1] == tring2[1] && tring1[2] == tring2[2]){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;
}