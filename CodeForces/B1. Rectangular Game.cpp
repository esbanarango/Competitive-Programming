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
typedef map<int, int> mii;
#define INF 1000000000

int posibles(long n){
	long hasta = n>>1;
	for (long i = 2; i <= hasta; ++i)
	{
		if(n%i==0)
			return i;
	}
	return n;
}

long maxDivied(long n, long tempMax){
	if(n==1) return tempMax;
	long menor = posibles(n);
	long nuevo=n/menor;
	tempMax+=nuevo;
	return maxDivied(nuevo,tempMax);
}

int main(){
	long n;scanf("%ld",&n);
	long maxResp=n+1;
	long menor = posibles(n);
	long tempMax=0;
	long nuevo=n/menor;
	tempMax=n+nuevo;
	maxResp=max(maxResp,maxDivied(nuevo,tempMax));
	printf("%ld\n",maxResp);
 return 0;   

}