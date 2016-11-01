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

  string line;
  int min_jumps = -1, current_jump=1;
  getline(cin, line);
  int size = line.size();
  for (int i = 0; i < size; ++i){
    if(line[i] == 'A' || line[i] == 'E' || line[i] == 'I' || line[i] == 'O' || line[i] == 'U' || line[i] == 'Y'){
      min_jumps = max(current_jump,min_jumps);
      current_jump = 1;
    }else{
      current_jump++;
    }
  }
  min_jumps = max(current_jump,min_jumps);
  printf("%d\n",min_jumps);
  return 0;
}