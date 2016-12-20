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

int main(){
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  int n; scanf("%d",&n);
  int ds = 0, rs = 0, vd = 0, vr = 0;
  string s;
  cin>>s;
  for (int i = 0; i < n; ++i){
    (s[i] == 'D') ? ds++ : rs++;
  }
  while(ds > 0 && rs > 0){
    for (int i = 0; i < n; ++i){
      // cout<<"Evaluating: "<<s[i]<<"RS & VR: "<<rs<<","<<vr<<". DS & VD"<<ds<<","<<vd<<endl;
      if(s[i] == 'X') continue;
      // Depublicans
      if(s[i] == 'D' && vr > 0){
        vr--; ds--; s[i] = 'X';
      }else if(s[i] == 'D'){
        vd++;
      }else if(s[i] == 'R' && vd > 0){
        // Remocrats
        vd--; rs--; s[i] = 'X';
      }else{
        vr++;
      }
    }
  }
  // cout<<"RS: "<<rs<<" DS"<<ds<<endl;
  (rs > 0) ? printf("R\n") : printf("D\n") ;
  return 0;
}