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
typedef vector <ll> vll;
typedef vector <char> vc;
typedef vector <string> vs;
typedef map <string,vs> msvs;
typedef map <string,int> msi;
typedef map <string,string> mss;
#define INF 1000000000

int main() {
  // freopen("in.in", "r", stdin);
  ll n; scanf("%lld",&n);
  vll nums(n);
  for (int i = 0; i < n; ++i)
    scanf("%lld",&nums[i]);
  sort (nums.begin(), nums.end());
  ll min_sum = INF;
  for (int i = 0, j = n-1; i < j; ++i, j--)
    min_sum = min(min_sum, nums[i] + nums[j]);
  printf("%lld\n",min_sum);
  return 0;
}