/*
  3108 - Common item
  TJU Online Judge
  Esteban Arango Medina
  
  Solution:
  	Unique, sort, print. 
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
  string temp;
    int cases;scanf("%d",&cases);
    while(cases--){
      vector<int> v1,v2,result;

      int m1,m2,num;
      scanf("%d %d",&m1,&m2);

      while(m1--){scanf("%d",&num);v1.push_back(num);}
      while(m2--){scanf("%d",&num);v2.push_back(num);}
      getline(cin,temp);

      for(int i=0;i<v1.size();++i){
        for(int j=0;j<v2.size();++j){
          if(v1[i]==v2[j] && find(result.begin(), result.end(), v1[i])==result.end())
            result.push_back(v1[i]);
        }
      }
      sort (result.begin(), result.end());  
      for(int i=0;i<result.size();++i)
        (i+1<result.size())?printf("%d ",result[i]):printf("%d\n",result[i]);
      if(result.size() == 0)
        printf("\n");
    }
    return 0;
}