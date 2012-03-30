

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

#define MAX 52


long fib[MAX];

int main()
{
    fib[1] = fib[2] = 1;
    for(long i = 3; i < MAX; i++)
        fib[i] = fib[i-2] + fib[i-1];
    int n;
    while(scanf("%d",&n) && n!=0){
    	printf("%ld\n",fib[n+1]);
    }
    return 0;
}