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
typedef map<char, int> mci;
typedef map<int, int> mii;
typedef map<string, string> mss;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define endl '\n'  // Normal `cout << endl` flushes the output every time wich hit performance badly
#define INF 1000000000
#define deb(x) cout << #x << ": " << x << endl;
#define printArray(arr) \
  for (auto x : arr) cout << x << ", ";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vi a(n), b(n);
  rep(i, 0, n) { cin >> a[i]; }
  rep(i, 0, n) { cin >> b[i]; }
  sort(b.begin(), b.end());
  int ans = INF;
  rep(i, 0, n) {
    int x = (((b[0] - a[i]) % m) + m) % m;
    vi c = a;
    rep(j, 0, n) {
      c[j] += x;
      c[j] %= m;
    }
    sort(c.begin(), c.end());
    if (c == b) {
      ans = min(ans, x);
    }
  }
  cout << ans << endl;
  return 0;
}