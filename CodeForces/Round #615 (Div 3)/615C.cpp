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
#include <tuple>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

using ll=long long;
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,int> si;
typedef pair<int,ii> iii;
typedef vector <si> vsi;
typedef vector <ii> vii;
typedef vector <int> vi;
typedef vector <char> vc;
typedef vector <string> vs;
typedef map <string,vs> msvs;
typedef map <string,int> msi;
typedef map <char,int> mci;
typedef map <int,int> mii;
typedef map <string,string> mss;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define endl '\n' // Normal `cout << endl` flushes the output every time wich hit performance badly
#define INF 1000000000
#define deb(x) cout<<#x<<": "<<x<<endl;
#define printArray(arr) for(auto x: arr) { cout<<x<<", "; }
#define printMatrix(mat) for(auto x: mat) { cout<<" "; printArray(x); cout<<endl; }
#define printMap(mmap) for(auto p: mmap) { cout<< p.first<<": "<<p.second<<endl; }


mii totals;
mii factors;

void setCorrect(int num){
  factors[num]++;
  // printMap(factors);cout<<"------"<<endl;
}

void getFactors(int n) {
  while (n % 2 == 0) {
    setCorrect(2);
    n = n/2;
  }
  // n must be odd at this point. So we can skip
  // one element (Note i = i +2)
  for (int i = 3; i <= sqrt(n); i = i + 2){
    // While i divides n, print i and divide n
    while (n % i == 0) {
      setCorrect(i);
      n = n/i;
    }
  }

  if (n > 2){
    setCorrect(n);
  }

}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); // Fast input
  #ifdef LOCAL_PROJECT
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
  #endif
  // sieve();
  int T; cin>>T;
  while(T--) {
    factors.clear();
    int n;
    cin>>n;
    getFactors(n);
    vi realFactors;
    // process factors
    for(auto p: factors) {
      if(p.second == 1){
        realFactors.pb(p.first);
      }else{
        int times = 2;
        int num = pow(p.first, times);
        realFactors.pb(num);
        p.second -= times;
        while(p.second>1){
          times++;
          num = pow(p.first, times);
          p.second -= times;
          realFactors.pb(num);
        }
        if(p.second == 1){
          realFactors.pb(p.first);
        }
      }
    }
    printMap(factors);
    printArray(realFactors);cout<<endl;
    sort(rall(realFactors));
    while(realFactors.size() > 3){
      realFactors[1] = realFactors[0] * realFactors[1];
      realFactors.erase (realFactors.begin());
    }

    if(realFactors.size() == 3){
      cout<<"YES"<<endl;
      cout<<realFactors[0]<<" "<<realFactors[1]<<" "<<realFactors[2]<<endl;
    }else {
      cout<<"NO"<<endl;
    }

  }
  return 0;
}