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
  int t;
  string n;
  scanf("%d", &t);
  while (t--) {
    ll sum = 0;
    cin >> n;
    for (size_t i = 0; i < n.size(); i++) {
      sum += (int)n[i] - 48;
    }
    int mod_10 = sum % 10;
    if (mod_10 == 0) {
      cout << n << "0" << endl;
    } else {
      cout << n << 10 - mod_10 << endl;
    }
  }
  return 0;
}