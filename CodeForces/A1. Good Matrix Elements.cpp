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
	int n;scanf("%d",&n);
	int cNum,sum=0;
	int middle=(n-1)/2,lDiag=0,rDiag=n-1;
	for (int i = 0; i < n; ++i,rDiag--,lDiag++)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&cNum);
			if(i==middle){
				sum+=cNum;
			}else if(j==middle){
				sum+=cNum;
			}else if(j==lDiag && j==rDiag){
				sum+=cNum;
			}else if(j==lDiag || j==rDiag){
				sum+=cNum;
			}
				
		}
	}
	printf("%d\n",sum);

 return 0;   

}