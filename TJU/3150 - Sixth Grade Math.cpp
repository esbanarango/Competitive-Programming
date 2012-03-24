using namespace std;
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

//Greatest Common Divisor (GCD)
long GCD(long a,long b) {
  while (b > 0) {
    a = a % b;
    a^=b; b^=a; a^=b; 
  } 
    return a; 
}
//Lowest Common Multiple (LCM)
long LCM (long a,long b){
   return (a * b) / GCD (a,b);
} 
//Greatest Common Factor(GCF). -> a>b
long GCF(long a, long b){
    if(a%b==0){
        return b;
    }        
    else{
       return (a-b<b)?GCF(b,a-b):GCF(a-b,b);
    }
        
}

int main(){
	int cases;scanf("%d",&cases);
    int i=1;
    while(cases--){
        long a,b;
        scanf("%ld %ld",&a,&b);
        if(b<a){
            long temp =a;
            a=b;
            b=temp;
        }
        printf("%d %ld %ld\n",i++,LCM(a,b),GCF(b,a));

    }
    return 0;
}