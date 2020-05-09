/*
  Esteban Arango Medina
*/
#include <bits/stdc++.h>

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
#define printArray(arr) for(auto x: arr) { cout<<x<<" "; }
#define printMatrix(mat) for(auto x: mat) { cout<<" "; printArray(x); cout<<endl; }
#define printMap(mmap) for(auto p: mmap) { cout<< p.first<<": "<<p.second<<endl; }

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); // Fast input
  #ifdef LOCAL_PROJECT
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
  #endif

  int T = 1; cin>>T;
  while(T--) {
    int n0, n1, n2;
    cin>>n0>>n1>>n2;
    string s;
    // Handle n0
    if(n0 > 0) {
      s += "00";
      rep(i, 0, n0-1) { s+= "0";}
    }
    // Handle n2
    if(n2 > 0) {
      s += "11";
      rep(i, 0, n2-1) { s+= "1"; }
    }

    string s01;
    if(n1 > 0) {
      if(n0 == 0){
        s01 = "0";
        int totalExtra = n2 > 0 ? n1-1 : n1;
        rep(i, 0, totalExtra) {
          s01 += (s01.back() == '1') ? "0" : "1";
        }
      } else {
        if(n2 == 0 || n1 > 1) {
          s01 = "1";
          int totalExtra = n2 > 0 ? n1-2 : n1-1;
          rep(i, 0, totalExtra) {
            s01 += (s01.back() == '1') ? "0" : "1";
          }
        }
      }
    }
    reverse(all(s01));
    cout<<s01<<s<<endl;
  }
  return 0;
}