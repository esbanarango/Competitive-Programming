/*
ID: marrano1
PROG: ride
LANG: C++
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
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string a, b;
    cin >> a >> b;
    int sizeA=a.length(),sizeB=b.length();
    long sumA=1,sumB=1;
    for (int i = 0; i < sizeA; ++i){sumA *= (a[i]-'A')+1;}
    for (int i = 0; i < sizeB; ++i){sumB *= (b[i]-'A')+1;}
    ((sumA%47) == (sumB%47))?printf("GO\n"):printf("STAY\n");
    return 0;
}