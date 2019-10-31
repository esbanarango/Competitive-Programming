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
  int t, d, needed, total_present = 0, changed = 0;
  string s;
  scanf("%d", &t);
  while (t--) {
    int total_present = 0, changed = 0;
    scanf("%d", &d);
    needed = ceil(d * 0.75);
    cin >> s;
    for (size_t i = 0; i < d; i++) {
      if ('P' == s[i]) total_present++;
    }
    needed -= total_present;
    // Fiends can mark him as present by proxy on this day only if he was present
    // (if he was really present, not just marked as present) on at least one of
    // the previous two days, i.e. days d−1 and d−2, and on at least one of the
    // following two days, i.e. days d+1 and d+2.
    for (int i = 2; i < d - 2 && needed > 0; i++) {
      if (s[i] == 'A' &&
          ((s[i - 1] == 'P' || s[i - 2] == 'P') &&
           (s[i + 1] == 'P' || s[i + 2] == 'P'))) {
        changed++;
        needed--;
      }
    }
    (needed <= 0) ? printf("%d\n", changed) : printf("-1\n");
  }
  return 0;
}