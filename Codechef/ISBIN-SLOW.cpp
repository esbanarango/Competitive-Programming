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
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define endl '\n' // Normal `cout << endl` flushes the output every time wich hit performance badly
#define INF 1000000000
#define deb(x) cout<<#x<<": "<<x<<endl;
#define printArray(arr) for(auto x: arr) { cout<<x<<", "; }
#define printMatrix(mat) for(auto x: mat) { cout<<" "; printArray(x); cout<<endl; }
#define printMap(mmap) for(auto p: mmap) { cout<< p.first<<": "<<p.second<<endl; }

void checkEquality(vi* A, int L, int R) {
  int totalInc = 0, totalDec = 0;
  // Increasing
  int p = L, q = L;
  while(q < R){
    if(A->at(q) < A->at(q+1)) { q++; continue; }
    if(p != q &&
      (p <= L || A->at(p) < A->at(p-1)) &&
      (q+1 >= R || A->at(q) > A->at(q+1))
    ) { totalInc ++; }
    q++;
    p = q;
  }
  // deb(p); deb(q);
  if(p != q &&
    (p <= L || A->at(p) < A->at(p-1)) &&
    (q+1 >= R || A->at(q) > A->at(q+1))
  ) { totalInc ++; }

  p = L, q = L;
  while(q < R){
    if( A->at(q) > A->at(q+1)) { q++; continue; }
    if(p != q &&
      (p <= L || A->at(p) > A->at(p-1)) &&
      (q+1 >= R || A->at(q) < A->at(q+1))
    ) { totalDec ++; }
    q++;
    p = q;
  }
  if(p != q &&
    (p <= L || A->at(p) > A->at(p-1)) &&
    (q+1 >= R || A->at(q) < A->at(q+1))
  ) { totalDec ++; }

  // deb(L); deb(R);
  // deb(totalInc); deb(totalDec);
  totalInc == totalDec ? cout<<"YES" : cout<<"NO";
  cout<<endl;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); // Fast input
  #ifdef LOCAL_PROJECT
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
  #endif

  int T = 1; //cin>>T;
  while(T--) {
    int N, Q;
    cin>>N>>Q;
    vi A(N);
    rep(i, 0, N) { cin>>A[i];}
    while(Q--){
      int L, R;
      cin>>L>>R;
      L--, R--;
      checkEquality(&A, L, R);
    }
  }
  return 0;
}