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
typedef map <char,int> mci;
typedef map <int,int> mii;
typedef map <string,string> mss;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define endl '\n' // Normal `cout << endl` flushes the output every time wich hit performance badly
#define INF 1000000000
#define deb(x) cout<<#x<<": "<<x<<endl;
#define printArray(arr) for(auto x: arr) { cout<<x<<", "; }
#define printMatrix(mat) for(auto x: mat) { cout<<" "; printArray(x); cout<<endl; }
#define printMap(mmap) for(auto p: mmap) { cout<< p.first<<": "<<p.second<<endl; }

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); // Fast input
  #ifdef LOCAL_PROJECT
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
  #endif

  int T = 1; //cin>>T;
  while(T--){
    ll N; cin>>N;
    vector<ll> NUMS(N+2,0);

    vector<ll> F(N,0);
    map<ll,ll> missing;
    map<ll,ll> positions;

    rep(i, 0, N) {
      cin>>F[i];
      if(F[i] == 0) {
        positions[i] = i;
      } else {
        NUMS[F[i]] = 1;
      }
    }
    rep(i, 1, N+1) {
      if(NUMS[i] == 0) { missing[i] = i; }
    }
    // cout<<endl;
    // cout<<endl;
    // printArray(NUMS);
    // cout<<endl;
    // printMap(missing);cout<<endl;
    // printMap(positions);
    auto pos = positions.begin();
    while(!missing.empty()) {
      auto toAdd = missing.end();
      auto toPrev = missing.end();
      toAdd--;
      toPrev--;

      auto toPrevPos = pos;
      toPrevPos++;
      // deb(toAdd->first);
      // deb(pos->second + 1);
      if(toAdd->first != (pos->second + 1)
        && (toPrev == missing.begin() || toPrevPos == positions.end() ||
          (--toPrev)->first != toPrevPos->second + 1
        )
      ){
        F[pos->second] = toAdd->first;
      } else {
        toAdd--;
        F[pos->second] = toAdd->first;
      }
      // printArray(F);cout<<endl;
      missing.erase(toAdd);
      // printMap(missing);
      pos++;
    }
    rep(i, 0, N){
      cout<<F[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}