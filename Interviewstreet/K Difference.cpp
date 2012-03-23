/*
  K Difference (50 Points)
  Interviewstreet Challenge
  Esteban Arango Medina
  
  Solution:
    Easy one, just make sure to 'break' the inner 'for' when you find one pair that satisfies the condition.
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
	int n,k,total=0;
	vector<int> nums;
	scanf("%d %d",&n,&k);
	while(n--){
		int num;
		scanf("%d",&num);
		nums.push_back(num);
	}
	for (int i = 0; i <nums.size()-1; ++i)
	{
		for (int j = i+1; j < nums.size(); ++j)
		{	
			if(abs(nums[i]-nums[j])==k){
				total++;
				break;
			}					
		}
	}
	printf("%d",total);
    return 0;
}
