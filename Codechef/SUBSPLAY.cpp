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
typedef map<int, int> mii;
typedef map<string, string> mss;
#define endl '\n'  // Normal `cout << endl` flushes the output every time wich hit performance badly
#define INF 1000000000
#define deb(x) cout << #x << ": " << x << endl;
#define printArray(arr) \
  for (auto x : arr) {  \
    cout << x << ", ";  \
  }
#define printMatrix(mat) \
  for (auto x : mat) {   \
    cout << " ";         \
    printArray(x);       \
    cout << endl;        \
  }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  int T, N;
  cin >> T;
  while (T--) {
    int ans = 0;
    cin >> N;
    string s;
    cin >> s;
    vector<vi> DP(N + 1, vi(N + 1, 0));
    for (int i = 1; i < N + 1; i++) {
      for (int j = 1; j < N + 1; j++) {
        if (s[i - 1] == s[j - 1]) {
          DP[i][j] = DP[i - 1][j - 1] + 1;
        } else {
          DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
      }
    }
    for (int i = 1; i < N + 1; i++) {
      for (int j = 1; j < N + 1; j++) {
        ans = max(ans, DP[i][j]);
      }
    }
    cout << ans << endl;
  }

  return 0;
}