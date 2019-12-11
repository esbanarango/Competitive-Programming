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
  ll T;
  scanf("%lld\n",&T);
  while(T--) {
    string s;
    cin>>s;
    for(int i = 0; i < s.size(); i++){
      if(s[i] == '?') {
        if(i-1 >= 0 && i + 1 < s.size()){
          char left = s[i-1]; char right = s[i+1];
          if((left == '?' || left == 'a') && (right == '?' || right == 'b')) { s[i] = 'c'; continue;}
          if((left == '?' || left == 'a') && (right == '?' || right == 'c')) { s[i] = 'b'; continue;}

          if((left == '?' || left == 'b') && (right == '?' || right == 'a')) { s[i] = 'c'; continue;}
          if((left == '?' || left == 'b') && (right == '?' || right == 'c')) { s[i] = 'a'; continue;}

          if((left == '?' || left == 'c') && (right == '?' || right == 'a')) { s[i] = 'b'; continue;}
          if((left == '?' || left == 'c') && (right == '?' || right == 'b')) { s[i] = 'a'; continue;}
        }
        if(i + 1 < s.size()){
          char right = s[i+1];
          if(right == '?') { s[i] = 'a'; continue;}
          if(right == 'b') { s[i] = 'a'; continue;}
          if(right == 'c') { s[i] = 'a'; continue;}
          if(right == 'a') { s[i] = 'b'; continue;}
        }
        if(i-1 >= 0){
          char left = s[i-1];
          if(left == '?') { s[i] = 'a'; continue;}
          if(left == 'b') { s[i] = 'a'; continue;}
          if(left == 'c') { s[i] = 'a'; continue;}
          if(left == 'a') { s[i] = 'b'; continue;}
        }
        s[i] = 'a';
      }
    }
    bool valid = true;
    // Check if valid
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == s[i+1]) { valid = false; break; }
    }
    cout<<((valid) ? s : "-1" )<< endl;
  }
  return 0;
}