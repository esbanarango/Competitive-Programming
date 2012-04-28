/*

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
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,int> si;
typedef pair<int,ii> iii;
typedef vector <si> vsi;
typedef vector <ii> vii;
typedef vector <int> vi;
typedef vector <char> vc;
#define INF 1000000000

int friends[2001][2001]={-1};

int main(){
	int n,k,m;
	scanf("%d",&n);
	scanf("%d",&k);
	vector<vi> friends(n+1);
	for (int i = 1; i <= k; ++i)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	scanf("%d",&m);
	for (int i = 1; i <= m; ++i)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		for(int j = 0;j<friends[a].size();j++){
			vi::iterator it;
			it = find (friends[b].begin(), friends[b].end(), friends[a][j]);
			if(it!=friends[b].end()){
				friends[b].erase (it);
				friends[a].erase (friends[a].begin()+j);
				j--;
			}
		}
	}
	int maxResp=0;
	//Real conection
	for (int i = 1; i <= n; ++i)
	{
		maxResp=max(maxResp,(int)friends[i].size());
	}
	printf("%d\n",maxResp+1);

 return 0;   

}