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


int main(){
	int n,m,c;scanf("%d %d %d",&n,&m,&c);
	vi N(n);
	vi M(m);
	vi result(n);
	int steps=(n-m+1);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&N[i]);
		result[i]=N[i];
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&M[i]);
	}
	for (int i = 0; i < steps; ++i)
	{
		
		for (int j = 0,k=i; j < m; ++j,k++)
		{
			result[k]=(M[j]+result[k])%c;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d",result[i]);
		if(i+1<n)
			printf(" ");
	}
	printf("\n");
 return 0;   

}