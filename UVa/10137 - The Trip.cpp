/*
  10137 - The Trip
  UVa Online Judge
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
  int n;
  double amount;
  while(scanf("%d",&n) && n!=0){
    vector<double> money;
    double amount,total=0,respPos=0,respNeg=0;
    for (int i = 0; i < n; ++i)
    {
      scanf("%lf",&amount);
      total += amount;
      money.push_back(amount);
    }
    total /= n;
    for (int i = 0; i < n; ++i)
    {
      double dif =(double) (long) ((money[i]-total) * 100.0) / 100.0;
      if(dif>0)
        respPos+=dif;
      else
        respNeg+=dif;
    }
    double resp = (-respNeg > respPos) ? -respNeg : respPos;
    resp = (resp<0)?-resp:resp;
    printf("$%.2lf\n",resp);
  }

 return 0;  
}
