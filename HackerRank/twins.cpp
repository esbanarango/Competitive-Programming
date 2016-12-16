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
#include <tuple>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs;   // 10^7 should be enough for most cases
vi primes;   // compact list of primes in form of vector<int>
int major_prime = 0;

void sieve(ll lower ,ll upperbound) {          // create list of primes in [0..upperbound]
  _sieve_size = upperbound + 1;                   // add 1 to include upperbound
  bs.set();                                                 // set all bits to 1
  if(lower == 1){
    bs[0] = bs[1] = 0;                                     // except index 0 and 1
    lower = 2;
  }
  for (ll i = lower; i <= _sieve_size; i++) if (bs[i]) {
    // cross out multiples of i starting from i * i!
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((int)i);  // also add this vector containing list of primes
  }
}                                           // call this method in main method

// ll numDiv(ll N) {
//   ll PF_idx = 0, PF = primes[PF_idx], ans = 1;             // start from ans = 1
//   while (N != 1 && (PF * PF <= N)) {
//     ll power = 0;                                             // count the power
//     while (N % PF == 0) { N /= PF; power++; }
//     ans *= (power + 1);                              // according to the formula
//     PF = primes[++PF_idx];
//   }
//   if (PF > major_prime) major_prime = PF;
//   if (N != 1) ans *= 2;             // (last factor has pow = 1, we add 1 to it)
//   return ans;
// }

int main() {
  freopen("in.in", "r", stdin);
  ll n,m; scanf("%lld %lld",&n,&m);
  sieve(1,5);
  sieve(n,m);
  ll size = primes.size();
  int total = 0;
  for (ll i = 0; i < size-1; ++i){
    printf("%d ",primes[i]);

    // printf(" {%d - %d}",primes[i], primes[i+1]);
    // if(primes[i+1] - primes[i] == 2)
    //   total++;
  }
  // printf("%d\n",total);
  return 0;
}