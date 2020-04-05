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

struct Segment { int asc = 0, desc = 0, L, R; };

bool hasExtraAsc(const vi &A, int lIdx, int rIds, bool single) {
  return (A[lIdx] < A[rIds]) &&
      (single ||
        (
          (lIdx == 0 || A[lIdx - 1] > A[lIdx]) &&
          (rIds == A.size() - 1 || A[rIds + 1] < A[rIds])
        )
      );
}

bool hasExtraDesc(const vi &A, int lIdx, int rIds, bool single) {
  return (A[lIdx] > A[rIds]) &&
      (single ||
        (
          (lIdx == 0 || A[lIdx - 1] < A[lIdx]) &&
          (rIds == A.size() - 1 || A[rIds + 1] > A[rIds])
        )
      );
}

Segment checkEquality(const vi &A, int L, int R, Segment nL, Segment nR) {
  Segment current;
  current.L = L; current.R = R;
  // deb(node);
  // deb(st[node].L);deb(st[node].R);
  // deb(nL); deb(nR);
  // deb(st[nL].R); deb(st[nR].L);
  int extraAsc = 0, extraDesc = 0;
  if(A[nL.R] != A[nR.L]){
    int lIdx = nL.R, rIds = nR.L;
    int single = abs(current.L - current.R) == 1;
    // cout<<"oeoeoe";
    // deb(lIdx);deb(rIds);
    // deb(A[lIdx]);deb(A[rIds]);
    if(hasExtraAsc(A, lIdx, rIds, single)) { extraAsc++; }
    if(hasExtraDesc(A, lIdx, rIds, single)) { extraDesc++; }
  }

  current.asc = nL.asc + nR.asc + extraAsc;
  current.desc = nL.desc + nR.desc + extraDesc;
  return current;
  // cout<<"----"<<endl;
}

void buildSegmentTree(vector<Segment> &st, const vi &A, int node, int L, int R) {
  st[node].L = L; st[node].R = R;
  if (L != R) {
    int nL = node<<1, nR = (node<<1) + 1;
    int middle = (L + R) / 2;
    buildSegmentTree(st, A, nL, L, middle);
    buildSegmentTree(st, A, nR, middle + 1, R);
    st[node] = checkEquality(A, L, R, st[nL], st[nR]);
  }
}

Segment querySegmentTree(vector<Segment> &st, const vi &A, int node, int L, int R, int i, int j) {
  // cout<<"--------"<<endl;
  // deb(L); deb(R);
  // deb(i); deb(j);
  // cout<<"--------"<<endl<<endl;

  if (L >= i && R <= j) return st[node];            // inside query range
  int middle = (L + R) / 2;
  if (middle >= j) {
     return querySegmentTree(st, A, 2 * node, L, middle, i, j);
  }
  if (i >= middle + 1) {
    return querySegmentTree(st, A, 2 * node + 1, middle + 1, R, i, j);
  }
  return checkEquality(A, L, R,
    querySegmentTree(st, A, 2 * node, L, middle, i, middle),
    querySegmentTree(st, A, 2 * node + 1, middle + 1, R, middle + 1, j)
  );
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
    rep(i, 0, N) { cin>>A[i]; }
    vector<Segment> st(4*N); buildSegmentTree(st, A, 1, 0, N - 1); // recursive build
    rep(i, 0, 24){
      cout<<"["<<st[i].L<<","<<st[i].R<<"]: ";
      cout<<"Asc: "<<st[i].asc<<", Desc: "<<st[i].desc<<endl;
    }
    while(Q--){
      int L, R;
      cin>>L>>R;
      L--, R--;
      Segment tmp = querySegmentTree(st, A, 1, 0, N - 1, L, R);
      deb(tmp.asc);
      deb(tmp.desc);

      tmp.asc == tmp.desc ? cout<<"YES" : cout<<"NO";
      cout<<endl;
    }
  }
  return 0;
}