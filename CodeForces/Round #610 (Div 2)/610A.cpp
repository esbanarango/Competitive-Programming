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
#define pb push_back
#define mp make_pair
#define endl '\n' // Normal `cout << endl` flushes the output every time wich hit performance badly
#define INF 1000000000
#define deb(x) cout<<#x<<": "<<x<<endl;
#define printArray(arr) for(auto x: arr) { cout<<x<<", "; }
#define printMatrix(mat) for(auto x: mat) { cout<<" "; printArray(x); cout<<endl; }
#define printMap(mmap) for(auto p: mmap) { cout<< p.first<<": "<<p.second<<endl; }

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  int T; cin>>T;
  while(T--) {
    ll a, b, c, r;
    cin>>a>>b>>c>>r;
    if(a>b) { swap(a,b); }
    ll d = abs(a-b);
    ll rRight = c+r; // -> 0
    ll rleft = c-r; // -> -4

    // deb(d);
    // deb(rRight);
    // deb(rleft);
    if(rleft <= a &&  rRight >= b){
      cout<<0<<endl;
    }else{
      if((rRight >= a && rRight <= b) && (rleft >= a && rleft <= b) ){
        d -= r*2;
      } else {
        if(rRight >= a && rRight <= b){ d -= abs(a - rRight);}
        if(rleft >= a && rleft <= b){ d -= abs(b - rleft);}
      }
      cout<<d<<endl;
    }
  }
  return 0;
}