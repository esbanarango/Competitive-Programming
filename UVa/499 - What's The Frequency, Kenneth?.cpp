/*
  499 - What's The Frequency, Kenneth?
  UVa Online Judge
  Esteban Arango Medina

  Solution.
    Ad-hoc, make sure to count only alphabetical charecters. I used map to save it.

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
  while(getline(cin,s)){
    map<char, int> each;
    int size = s.size(),top=0;
    for (int i = 0; i < size; ++i)
    {
      if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
        each[s[i]]++;
        top = max(top,each[s[i]]);
      } 
    }
    map<char,int>::const_iterator itr;
    for(itr = each.begin(); itr != each.end(); ++itr){
      if((*itr).second == top)cout<<(*itr).first;
    }
    printf(" %d\n",top);
  }
    
 return 0;  
}
