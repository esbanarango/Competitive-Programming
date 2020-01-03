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
#include <tuple>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;
int main() {
	  #ifdef LOCAL_PROJECT
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
  #endif
	int n;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector <int> ans;
	map <int, bool > visited;
	map<int, bool> has_parent;
	vector<int> to;
	queue<int> q;
	int nz = 0;
	vector<pair< int,  int>> seg;
	to.push_back(-1);
	for (int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		to.push_back(tmp);
		if (tmp == 0) {
			nz++;
		} else {
			has_parent[tmp] = true;
		}
	}
	for (int i=1; i<=n; i++) {
		if (visited[i] ) continue;
		if (to[i] != 0) {
			if (!has_parent[i]) {
				visited[i] = true;
				int ini = i;
				int cur = i;
				while (to[cur] != 0) cur = to[cur], visited[cur] = true;;
				seg.push_back({ini, cur});
			}
		}
	}

	for (int i=1; i<=n; i++ ){
		if (to[i] == 0 && !visited[i]) seg.push_back({i, i});
	}
	for (int i=0; i<seg.size(); i++) {
		to[seg[i].second] = seg[(i+1) % (int)(seg.size())].first;
	}
	for (int i=1;i <=n ; i++ ){
		cout << to[i] << " \n"[i==n];
	}
	return 0;
}
