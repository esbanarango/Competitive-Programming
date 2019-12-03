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
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("in.in", "r", stdin);

  long long mass, finalTotal, total;

  while(scanf("%lld\n",&mass)!=EOF){
    total = 0;
    while(true){
      mass = (mass/3) -2;
      if(mass<=0) { break; }
      total += mass;
    }
    finalTotal += total;
  }
  cout<<finalTotal<<endl;
  return 0;
}