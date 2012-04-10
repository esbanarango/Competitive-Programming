/*
  158A - Next Round
  CodeForces
  Esteban Arango Medina

  Solution.
    Ad-hoc, just do what they want.

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
  int participants[55];
  int n,k,max;scanf("%d %d",&n,&k);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d",&participants[i]);
    if(i+1==k)
      max= participants[i];
  }
  int count=0;
  for (int i = 0; i < n; ++i)
  {
    if(participants[i]>=max && participants[i] > 0)
      count++;
  }
  printf("%d",count);

 return 0;  
}
