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
typedef map <string,string> mss;
#define INF 1000000000

ll solve(ll n, ll k){
  ll middle = (ll)pow(2, n) / 2;
  if(k == middle){
    return n;
  }else{
    if(k > middle)
      k -= middle;
    n--;
    return solve(n,k);
  }
}

int main(){
  // freopen("in.in", "r", stdin);
  ll n,k;
  cin>>n>>k;
  cout<<solve(n,k)<<endl;
  return 0;
}