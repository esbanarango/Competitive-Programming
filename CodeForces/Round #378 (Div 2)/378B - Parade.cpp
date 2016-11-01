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
#define SWAP(a,b) {int t=a; a=b; b=t;}

int main(){
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  int n,l,r,k=0;
  ll current_max=0,total_l=0,total_r=0;
  scanf("%d",&n);
  vi L(n),R(n);
  for(int i = 0; i < n; ++i){
    scanf("%d %d",&L[i],&R[i]);
    total_l += L[i];
    total_r += R[i];
  }
  current_max = abs(total_l - total_r);
  for (int i = 0; i < n; ++i){
    ll new_max = abs((total_l-L[i]+R[i])-(total_r-R[i]+L[i]));
    if(new_max>current_max){
      current_max=new_max;
      k=i+1;
    }
  }
  printf("%d\n",k);
  return 0;
}