/*
  Esteban Arango Medina
*/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef pair<int, ii> iii;
typedef vector<si> vsi;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef map<string, vs> msvs;
typedef map<string, int> msi;
typedef map<string, string> mss;
#define INF 1000000000

int main() {
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  int a, b;
  scanf("%d %d", &a, &b);
  if (a == b) {
    printf("%d1 %d2", a, b);
  } else if (b - a == 1) {
    printf("%d9 %d0", a, b);
  } else if (a - b == 8) {
    printf("%d %d0", a, b);
  } else {
    printf("-1");
  }

  return 0;
}