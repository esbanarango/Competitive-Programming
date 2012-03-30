/*
  10038 - Jolly Jumpers
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

#define MAX 30005

bool seq[MAX];

int main(){
    int n;  
    while (scanf("%d",&n) != EOF){
      int pre,currentNum,total; 
      scanf("%d",&currentNum);
      memset(seq, false, sizeof(seq));
      pre = currentNum;
      bool es =true; 
      for (int i =1; i < n; ++i)
      { 
        scanf("%d",&currentNum);
        total = abs(pre-currentNum);
        if(total <=0 || total>n-1){
          es =false;
        }else if(seq[total]){ //Already set
          es = false;
        }
        seq[total]=true;
        pre = currentNum; 
      }
      if(es)
        printf("Jolly\n");
      else
        printf("Not jolly\n");
    }
    return 0;
}
