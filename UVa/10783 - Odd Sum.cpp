/*
  10783 - Odd Sum
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
    int cases,cace=1;
    scanf("%d",&cases);
    while(cases--){
            int a,b;scanf("%d\n%d",&a,&b);
            int total =0;
            for(int i =a;i<b+1;i++){
                if(i%2!=0)
                    total+=i;
            }
            printf("Case %d: %d\n",cace,total);
            cace++;
    }

 return 0;   
}
