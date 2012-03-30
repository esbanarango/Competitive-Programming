/*
  10420 - List of Conquest
  UVa Online Judge
  Esteban Arango Medina

  Solution.
    Take advantage of the map and set, in a map when you print the keys (string) it will 
    be sorted lexicographically and with set you can't have repeat elements

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
  int n;scanf("%d",&n);
  string line;
  getline (cin,line);
  map <string,set<string> > combos;
  //size_t pos;
  while(n--){
    getline (cin,line);
    int pos = line.find(' ');
    combos[line.substr(0,pos)].insert(line.substr(pos+1,line.size()-pos));
  }

  map <string,set<string> >::const_iterator itr;
  for(itr = combos.begin(); itr != combos.end(); ++itr){ 
    cout<<(*itr).first<<" "<<(*itr).second.size()<<endl;
  }
 return 0;  
}
