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
typedef map<char, ii> mcii;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<string, string> mss;

#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define endl '\n'  // Normal `cout << endl` flushes the output every time wich hit performance badly
#define INF 1000000000
#define deb(x) cout << #x << ": " << x << endl;
#define printArray(arr) for(auto x: arr) { cout<<x<<", "; }
#define printMatrix(mat) for(auto x: mat) { cout<<" "; printArray(x); cout<<endl; }


#define M 10000

ll binAdd(bitset<M> a, bitset<M> b) {
  ll times = 0;

  bitset<M> u, v;
  while (b.count() > 0) {
    u = a ^ b;
    v = a & b;
    a = u;
    b = v << 1;
    times++;
  }
  return times;
}

// We need to find the minimum distance between two repeated characters
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  int T, N;
  cin >> T;
  while (T--) {
    string A, B;
    cin >> A; cin >> B;
    cout<<binAdd(bitset<M>(A), bitset<M>(B))<<endl;
  }

  return 0;
}