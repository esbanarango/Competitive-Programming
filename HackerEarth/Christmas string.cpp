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
  int n, uneded = 0, res = 0, initial_l, changed_position;
  string initial, current;
  cin>>initial; cin>>n;
  initial_l = initial.size();
  vi totals(n);
  for (int i = 0; i < n; ++i){
    cin>>current;
    bool used = false;
    changed_position = -1;
    for (int j = 0; j < initial_l; ++j){
      if(initial[j] == '*' || current[j] == initial[j]) continue;
      if(!used){
        changed_position = j;
        used = true;
      }else{
        changed_position = -1;
        break;
      }
    }
    if(!used){
      uneded++;
    }else if(changed_position != -1){
      totals[changed_position]++;
      res = max(res,totals[changed_position]);
    }
  }
  res += uneded;
  cout<<res<<endl;

  return 0;

}