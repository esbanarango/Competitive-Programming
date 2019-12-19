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
  int q; cin>>q;
  mci pos = { {'U',0}, {'D',1}, {'R',2}, {'L',3}};
  while(q--) {
    string s;
    cin>>s;
    vi directions (4,0);
    for(const char c: s) { directions[pos[c]]++; }
    directions[0] = min(directions[0], directions[1]);
    directions[1] = directions[0];

    directions[2] = min(directions[2], directions[3]);
    directions[3] = directions[2];


    if(directions[0] > 0 && directions[1] > 0 && directions[2] > 0 && directions[3] > 0) {
      cout<<(min(directions[0], directions[1]) * 2) + (min(directions[2], directions[3])*2)<<endl;
      cout<<"U"; directions[0]--;
      rep(i, 0, directions[2]){ cout<<"R"; }
      rep(i, 0, directions[1]){ cout<<"D"; }
      rep(i, 0, directions[3]){ cout<<"L"; }
      rep(i, 0, directions[0]){ cout<<"U"; }
      cout<<endl;
    } else if((directions[0] > 0 && directions[1] > 0) || (directions[2] > 0 && directions[3] > 0)) {
      cout<<2<<endl;
      (directions[0] > 0) ? cout<<"UD"<<endl : cout<<"RL"<<endl;
    } else {
      cout<<0<<endl<<endl;
    }
  }
  return 0;
}