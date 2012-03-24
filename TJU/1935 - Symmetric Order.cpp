/*
  1935 - Symmetric Order
  TJU Online Judge
  Esteban Arango Medina
  
  Solution:
    Read the input, if i is even, then save it into 'ses' array otherwise print it, then print 'ses' array.
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
	int set=1;
    while(scanf("%d",&n) && n!=0){
    	printf("SET %d\n",set);
    	string s;
    	vector<string> ses;
    	for (int i = 1; i <= n; ++i){
    		cin>>s;
    		if(i%2==0)
    			ses.push_back(s);
    		else
    			cout<<s<<endl;
    	}
    	for (int i = (n/2)-1; i >= 0; --i)
    	{
    		cout<<ses[i]<<endl;
    	}
    	set++;
    }
    return 0;
}