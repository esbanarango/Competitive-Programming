/*
  3059 - Rock, Paper, or Scissors?
  TJU Online Judge
  Esteban Arango Medina
  
  Solution:
  	Simple simulation. 
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

	map<char,char> rules;
    rules['P']='R';
	rules['R']='S';
	rules['S']='P';

	int cases;
	scanf("%d",&cases);
	while(cases--){
		int numP,p1 = 0,p2 =0;
		string temp;
		char p1R,p2R;
		scanf("%d",&numP);
		while(numP--){
			getline(cin,temp);
			scanf("%c %c",&p1R,&p2R);
			if(!(p1R == p2R)){
				(rules.find(p1R)->second == p2R)?p1++:p2++;
			}
		}
		if(p1 == p2)
			printf("TIE\n");
		else
			(p1>p2)?printf("Player 1\n"):printf("Player 2\n");
	}	
    return 0;
}
