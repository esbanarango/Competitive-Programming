/*
  5932 - Refrigerator Magnets
  ACM-ICPC Live Archive
  Esteban Arango Medina

	Solution.
		String manipulation.
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
	string s;
	getline(cin,s);
	getline(cin,s);
	while(s != "END"){
		string mostrar = s;
		sort(s.begin(),s.end());
		int size = s.size();
		bool valid =true;
		for (int i = 1; i < size; ++i)
		{	
			if(s[i-1]!=' ' && s[i]!=' ' && s[i-1]==s[i]){
				valid=false;
				break;
			}
		}
		if(valid)
			cout<<mostrar<<endl;
		getline(cin,s);
	}
	return 0;
}