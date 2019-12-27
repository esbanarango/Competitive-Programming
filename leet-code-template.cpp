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

class Solution {
 public:
  int name(vector<int>& nums) {
    int n = nums.size();

    int mod_arr[n], result = 0;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
      curr_sum += nums[i];

      mod_arr[i] = (curr_sum % 3) + 3;
    }

    for (int i = 0; i < n; i++) {
      if (mod_arr[i] == 0) {
        result = max(result, sum_arr[i]);
      }
    }
    return result;
  }
};

int main() {
  Solution solution;
  cout << solution.name("aaa") << endl;
  return 0;
}
