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
typedef unsigned long long ull;
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

ull cdn(ull c, ull d, ull n)  // work out c^d mod n
{
  ull value = 1;
  while (d > 0) {
    value *= c;
    value %= n;
    d--;
  }
  return value;
}

ull power(ull x, ull y, ull p) {
  ull res = 1;  // Initialize result

  // Update x if it is more than or
  // equal to p
  x = x % p;

  while (y > 0) {
    // If y is odd, multiply x with the result
    if (y & 1)
      res = (res * x) % p;

    // y must be even now
    y = y >> 1;  // y = y/2
    x = (x * x) % p;
  }
  return res;
}

int main() {
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  int t;
  string b_s;
  scanf("%d", &t);
  while (t--) {
    ull b;
    cin >> b;
    b--;
    // scanf("%d", &n);
    // String input as b is very large
    // string b = "100000000000000000000000000";
    b_s = to_string(b);
    ull remainderB = 0;
    ull MOD = 1000000007;

    // Reduce the number B to a small number
    // using Fermat Little
    for (int i = 0; i < b_s.length(); i++)
      remainderB = (remainderB * 10 + b_s[i] - '0') % (MOD - 1);
    cout << (power(2, remainderB, MOD) * 10) % MOD << endl;
    // cout << "n:" << b + 1 << " - " << power(2, remainderB, MOD) << '0' << endl;
    // ull b_num = cdn(2, n - 1, MOD);
    // cout << "n; " << n << " -> " << b_num % MOD << "0" << endl;
    // if (n == 1) {
    //   printf("10\n");
    // } else {
    //       int n = 123;
    // std::string str = std::to_string(n);
    // std::cout << n << " ==> " << str << std::endl;
    // ull total = 0, k = pow(10, n);
    // vector<string> nums;
    // for (size_t i = 0; i < k; i++) {
    //   string str_l = to_string(i);
    //   string str_r = to_string(k - i - 1);
    //   nums.push_back(str_l + str_r);
    // }

    // for (auto x : nums) {
    //   set<char> seen;
    //   for (size_t i = 0; i < x.size(); i++) {
    //     seen.insert(x[i]);
    //   }
    //   if (seen.size() == 2) total++;
    //   // cout << x << endl;
    // }

    // cout << "n:" << n << " - total: " << total << endl;

    // string s = "1";
    // for (size_t i = 1; i < n; i++) {
    //   s += "0";
    // }
    // cout << s << endl;
    // }
  }
  return 0;
}