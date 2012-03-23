/*
  3108 - Common item
  TJU Online Judge
  Esteban Arango Medina
  
  Solution:
  	Sort, unique, print. 
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
	int cases;
	scanf("%d",&cases);
	while(cases--){
		int m1,m2;scanf("%d %d",&m1,&m2);
		vector<int> mv1;
		vector<int> mv2;
		vector<int>::iterator it;


		for (int i = m1,num; i--; scanf("%d",&num),mv1.push_back(num));
		for (int i = m2,num; i--; scanf("%d",&num),mv2.push_back(num));
		sort(mv1.begin(),mv1.end());
		sort(mv2.begin(),mv2.end());
		it = unique (mv1.begin(), mv1.end()); 
  		mv1.resize( it - mv1.begin() ); 
  		it = unique (mv2.begin(), mv2.end()); 
  		mv2.resize( it - mv2.begin() );
  		int siz =mv1.size();
  		for (int i = 0; i < siz; ++i)
  		{
  		 	if(find (mv2.begin(), mv2.end(), mv1[i])!=mv2.end())
  		 		(i!=0)?printf(" %d",mv1[i]):printf("%d",mv1[i]);
  		}
  		printf("\n");
		
	}	
    return 0;
}
