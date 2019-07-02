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

int findDigits(int n) {
  int total = 0;
  int initial_number = n;
  while(n > 0) {
    int current_dig = n % 10;
    if (current_dig != 0 && initial_number % current_dig == 0) {
      total++;
    }
    n /= 10;
  }
  return total;
}

int main(){
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++){
    int current;
    scanf("%d", &current);
    printf("%d\n", findDigits(current));
  }

  return 0;
}