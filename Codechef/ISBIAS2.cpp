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

struct Segment {
  bool single = true;
  int asc = 0, desc = 0;
  vi L = vi(2, 0), R = vi(2, 0);
};

Segment checkEquality(const vi &A, Segment nL, Segment nR) {
  Segment current;
  current.single = false;
  if(nL.single && nR.single) {
    (nL.R[1] > nR.L[0]) ? current.desc++ : current.asc++;

    current.L[0] = nL.R[1];
    current.L[1] = nR.L[0];
    current.R[0] = current.L[0];
    current.R[1] = current.L[1];
  } else if(nL.single){
    if (nR.L[1] > nR.L[0]) {
      current.desc = nR.desc;
      current.asc = nR.asc;
      if (nL.L[0] < nR.L[0]) { current.desc++; }
    } else {
      current.desc = nR.desc;
      current.asc = nR.asc;
      if (nL.L[0] < nR.L[0]) { current.asc++; }
    }
    current.L[1] = nR.L[0];
    current.L[0] = nL.L[0];
    current.R[0] = nR.R[0];
    current.R[1] = nR.R[1];
  } else if(nR.single){
    if (nL.R[1] > nL.R[0]) {
      current.desc = nL.desc;
      current.asc = nL.asc;
      if (!(nR.L[0] > nL.R[1])) {current.desc++;}
    } else {
      current.desc = nL.desc;
      current.asc = nL.asc;
      if (nR.L[0] > nL.R[1]) { current.asc++; }
    }

    current.L[0] = nL.L[0];
    current.L[1] = nL.L[1];
    current.R[0] = nL.R[1];
    current.R[1] = nR.L[0];
  } else {
    if (nL.R[1] > nL.R[0]  && nR.L[1] > nR.L[0]) {
      if (nR.L[0] > nL.R[1]) {
        current.desc = nL.desc + nR.desc;
        current.asc = nL.asc + nR.asc - 1;
      } else {
        current.desc = nL.desc + nR.desc + 1;
        current.asc = nL.asc + nR.asc;
      }
    } else if (nL.R[1] > nL.R[0] && !(nR.L[1] > nR.L[0])) {
        current.desc = nL.desc + nR.desc;
        current.asc = nL.asc + nR.asc;
    } else if (!(nL.R[1] > nL.R[0]) && nR.L[1] > nR.L[0]) {
        current.desc = nL.desc + nR.desc;
        current.asc = nL.asc + nR.asc;
    } else if (!(nL.R[1] > nL.R[0]) && !(nR.L[1] > nR.L[0])) {
        if (nR.L[0] < nL.R[1]) {
            current.desc = nL.desc + nR.desc - 1;
            current.asc = nL.asc + nR.asc;
        } else {
            current.desc = nL.desc + nR.desc;
            current.asc = nL.asc + nR.asc + 1;
        }
    }

    current.L[0] = nL.L[0];
    current.L[1] = nL.L[1];

    current.R[0] = nR.R[0];
    current.R[1] = nR.R[1];
  }
  return current;
}

void buildSegmentTree(vector<Segment> &st, const vi &A, int node, int L, int R) {
  if (L == R) {
    st[node].L[0] = A[L]; st[node].R[1] = A[L];
  } else {
    int nL = node<<1, nR = (node<<1) + 1;
    int middle = (L + R) / 2;
    buildSegmentTree(st, A, nL, L, middle);
    buildSegmentTree(st, A, nR, middle + 1, R);

    st[node] = checkEquality(A, st[nL], st[nR]);
  }
}

Segment querySegmentTree(vector<Segment> &st, const vi &A, int node, int L, int R, int i, int j) {
  // cout<<"--------"<<endl;
  // deb(L); deb(R);
  // deb(i); deb(j);
  // cout<<"--------"<<endl<<endl;

  if (L== i && R == j) return st[node];            // inside query range
  int middle = (L + R) / 2;
  if (middle >= j) {
     return querySegmentTree(st, A, 2 * node, L, middle, i, j);
  }
  if (i >= middle + 1) {
    return querySegmentTree(st, A, 2 * node + 1, middle + 1, R, i, j);
  }
  return checkEquality(A,
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
    while(Q--){
      int L, R;
      cin>>L>>R;
      L--, R--;
      Segment tmp = querySegmentTree(st, A, 1, 0, N-1, L, R);
      deb(tmp.asc);
      deb(tmp.desc);

      tmp.asc == tmp.desc ? cout<<"YES" : cout<<"NO";
      cout<<endl;
    }
  }
  return 0;
}