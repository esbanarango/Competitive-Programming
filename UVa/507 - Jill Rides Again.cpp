/*
  Esteban Arango Medina
  Tricky tests cases:
  https://gist.github.com/esbanarango/4ddb4b0e419aa10d3ab6
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
#include <bitset>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,int> si;
typedef pair<int,ii> iii;
typedef vector <si> vsi;
typedef vector <ii> vii;
typedef vector <int> vi;
typedef vector <char> vc;
typedef vector <string> vs;
typedef map <string,vs> msvs;
typedef map <string,int> msi;
typedef map <string,string> mss;
#define MAX 20001


int main(){
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  int routes; scanf("%d",&routes);
  for (int r = 1; r <= routes; ++r){
    int total_stops, total_sum, current_sum, current_index, best_begin, best_end, equal_sum, equal_total_sum;
    equal_sum = 0;
    scanf("%d",&total_stops);
    current_sum = total_sum = equal_total_sum = -1 * MAX;
    for (int stop, i = 0; i < total_stops - 1; ++i,++equal_sum){
    	scanf("%d",&stop);
			equal_total_sum += stop;
    	if ((current_sum + stop) > stop){
    		current_sum = current_sum + stop;
    	}else{
				if(current_sum < 0)
    			current_index = i+1;
    		current_sum = stop;
    	}
    	if(current_sum > total_sum) {
    		equal_sum = 0;
    		total_sum = current_sum;
    		best_begin = current_index;
    		best_end = i+2;
    		equal_total_sum = total_sum;
    	}else if(equal_total_sum == total_sum && equal_total_sum == current_sum){
    		// If there is bigger sub array
				best_end += equal_sum;
				equal_sum = 0;
    	}
    }
    if(total_sum <= 0){
    	printf("Route %d has no nice parts\n", r);
    }else{
    	// Only one route
    	if(best_begin == best_end)
    		best_end++;
    	printf("The nicest part of route %d is between stops %d and %d\n",r,best_begin,best_end);
    }
  }

 return 0;

}