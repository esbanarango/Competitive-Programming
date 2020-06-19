/*
  Esteban Arango Medina
*/
#include <bits/stdc++.h>

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
#define deb(x) cout<<#x<<": "<<x<<endl;
#define printA(arr) for(auto x: arr) { cout<<x<<" "; }
#define printMatrix(mat) for(auto x: mat) { cout<<" "; printA(x); cout<<endl; }
#define printMap(mmap) for(auto p: mmap) { cout<< p.first<<": "<<p.second<<endl; }
#define ROUNDNUM(x) ((int)(x + 0.5f))

int posX[4] = {-1,0,1,0};
int posY[4] = {0,1,0,-1};

bool IsPowerOfTwo(int x) {
  return x > 0 && (x & (x - 1)) == 0;
}


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); // Fast input
  #ifdef LOCAL_PROJECT
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
  #endif

  int T = 1; cin>>T;
  while(T--) {
    int ts; cin>>ts;
    if(ts & 1) { cout<<(ts-1)/2<<endl; continue; }
    if(IsPowerOfTwo(ts)) { cout<<0<<endl; continue; }
    while(!(ts & 1)) { ts /=2; }
    cout<<(ts-1) / 2<<endl;
  }
  return 0;
}