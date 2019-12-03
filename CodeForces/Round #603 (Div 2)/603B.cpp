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
#define deb(x) cout<<#x<<": "<<x<<endl;
#define printArray(arr) for(auto x: arr) { cout<<x<<", "; }
#define printMatrix(mat) for(auto x: mat) { cout<<" "; printArray(x); cout<<endl; }
#define printMap(mmap) for(auto p: mmap) { cout<< p.first<<": "<<p.second<<endl; }


int main(){
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  ll T, N;
  scanf("%lld\n",&T);
  while(T--) {
    scanf("%lld\n",&N);
    vector<string> cards(N);
    int toChange = 0;
    map<string,int> haveSeen;
    for(int i = 0; i < N; i++) {
      cin>>cards[i];
      if(haveSeen[cards[i]]) { toChange ++;}
      haveSeen[cards[i]]++;
    }
    cout<<toChange<<endl;
    // printMap(haveSeen);
    for(int i = 0; i < N; i++) {
      string card = cards[i];
      if(haveSeen[card] == 1) { continue; }
      string tmp = card;
      int c = '0';
      while(haveSeen[tmp] > 0) { tmp[0] = c; c++; }
      haveSeen[cards[i]]--;
      haveSeen[tmp]++;
      cards[i] = tmp;
    }
    for(auto card: cards){
      if(card.size() < 4){
        int missing = 4 -card.size();
        while(missing--){cout<<'0';}
      }
      cout<<card<<endl;
    }
  }
  return 0;
}