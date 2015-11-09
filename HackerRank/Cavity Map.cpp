/*
  Cavity Map (30 points)
  HackerRank
  Esteban Arango Medina
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
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
int adjacent_x[4]= {0,-1,0,1};
int adjacent_y[4]= {-1,0,1,0};

int main() {
	freopen("in.in", "r", stdin);
	int n; scanf("%d",&n);
	int cavity_map[n][n];
	vector<string> fila(n);
	vector< vector<string> > result_map(n,fila);
	for(unsigned i = 0; i < n; ++i) for(unsigned j = 0; j < n; ++j) {
		scanf("%1d",&cavity_map[i][j]); result_map[i][j] = SSTR(cavity_map[i][j]);
	}
	// Process
	if(n > 2) {
		bool deeper = true;
		for(unsigned i = 1; i < n-1; ++i) for(unsigned j = 1; j < n-1; ++j) for(unsigned k=0, deeper = true;k<4 && deeper; k++){
			if(cavity_map[i][j] <= cavity_map[i+adjacent_x[k]][j+adjacent_y[k]])
				deeper = false;
			if(k==3 && deeper)
				result_map[i][j] = 'X';
		}
	}
	for(unsigned i = 0; i < n; ++i, printf("\n")) for(unsigned j = 0; j < n; ++j) {
		cout<<result_map[i][j];
	}
  return 0;
}