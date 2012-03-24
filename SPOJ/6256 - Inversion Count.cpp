/*
  6256 - Inversion Count
  SPOJ
  Esteban Arango Medina
  
  Solution:
  	Make a new array of size 'MaxElement' of the given array, then, back to front get the sum of each until inv[i]-1 (no including i),
  	and add 1 to postion inv[i]. Then print the sum. And that's the number of inversions.
    Fenwick tree.

   Notes.
   	http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=binaryIndexedTrees
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

int get(vector<int> *tree,int i){
	int sum = 0;
	while(i>0){
		sum +=tree->at(i);
		i-=i&-i;
	}
	return sum;
}
void add(vector<int> *tree, int idx ,int val){
	while (idx < tree->size()){
		tree->at(idx) += val;
		idx += (idx & -idx);
	}
}

int main(){
	int cases;scanf("%d",&cases);
	while(cases--){
		long long n;scanf("%lld",&n);
		vector <long long> inv;
		long long total=0;
		long long size=0;
		for (long long i = n,num; i--; scanf("%lld",&num),size=max(size,num),inv.push_back(num));
		vector<int> tree (size+1,0);
		for (int i = inv.size()-1; size > 0 && i >= 0 ; --i)
		{
			total += get(&tree,inv[i]-1);
			add(&tree,inv[i],1);
		}
		printf("%lld\n",total);
	}	
    return 0;
}
