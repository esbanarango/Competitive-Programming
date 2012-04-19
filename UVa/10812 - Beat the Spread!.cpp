/*
  10812 - Beat the Spread!
  UVa Online Judge
  Esteban Arango Medina

    Solution.
      Ad-hoc. 
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
typedef long long ll;
typedef pair<int,int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;
#define INF 1000000000


int main(){
    int n;scanf("%d",&n);
    while(n--){
        int s,t,x,y;
        scanf("%d %d",&s,&t);
        y=abs(s-t)/2;
        x=s-y;
        if((x+y==s) && (abs(x-y)==t))
            printf("%d %d\n",max(x,y),min(x,y));
        else
            printf("impossible\n");

    }

 return 0;   

}