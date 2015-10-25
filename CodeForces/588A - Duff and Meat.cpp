/*
  173A - Duff and Meat
  CodeForces
  A. Duff and Meat
  Codeforces Round #326 (Div. 2)
  Esteban Arango Medina

  Solution.


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
  // freopen("in.in", "r", stdin);
  int n,a,p;
  int money = 0, price = 101;
  scanf("%d",&n);
  while(n--){
    scanf("%d %d",&a,&p);
    if(price > p){ price = p; }
    money += price * a;
  }
  printf("%d",money);
 return 0;
}