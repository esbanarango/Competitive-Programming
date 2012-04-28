/*
  2637 - WorstWeather Ever	
  Esteban Arango Medina
  Peking University Online Judge
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
typedef map <int,int> mii;
#define INF 1000000000

/**************************Segment Tree***************************************************/
void st_build(vi &st, const vi &A, int vertex, int L, int R) {
  if (L == R)                              
    st[vertex] = L;                                      
  else {   
    int nL = vertex<<1, nR = (vertex<<1) + 1;
    st_build(st, A, nL, L              , (L + R) / 2);
    st_build(st, A, nR, ((L + R)>>1) + 1, R          );
    int lContent = st[nL]     , rContent = st[nR];
    int lValue   = A[lContent], rValue   = A[rContent];
    st[vertex] = (lValue > rValue) ? lContent : rContent;
} }

void st_create(vi &st, const vi &A) {       

  int len = (int)(2*pow(2.0, floor((log((double)A.size())/log(2.0)) + 1)));
  st.assign(len, 0); 
  st_build(st, A, 1, 0, (int)A.size() - 1);              
}

int st_rmq(vi &st, const vi &A, int vertex, int L, int R, int i, int j) {
  if (i >  R || j <  L) return -1;   
  if (L >= i && R <= j) return st[vertex];            

  int p1 = st_rmq(st, A, (vertex<<1)    , L              , (L+R)>>1, i, j);
  int p2 = st_rmq(st, A, (vertex<<1) + 1, ((L+R)>> 1) + 1, R          , i, j);

  if (p1 == -1) return p2;     
  if (p2 == -1) return p1;                                 
  return (A[p1] > A[p2]) ? p1 : p2; }

int st_rmq(vi &st, const vi& A, int i, int j) { 
  return st_rmq(st, A, 1, 0, (int)A.size() - 1, i, j); }

int st_update_point(vi &st, vi &A, int node, int b, int e, int idx, int new_value) {
  int i = idx, j = idx;
  if (i > e || j < b)
    return st[node];

  if (b == i && e == j) {
    A[i] = new_value;
    return st[node] = b;
  }

  int p1, p2;
  p1 = st_update_point(st, A, node<<1    , b              , (b + e)>>1, idx, new_value);
  p2 = st_update_point(st, A, (node<<1) + 1, ((b + e)>>1) + 1, e          , idx, new_value);

  return st[node] = (A[p1] > A[p2]) ? p1 : p2;
}

int st_update_point(vi &st, vi &A, int idx, int new_value) {
  return st_update_point(st, A, 1, 0, (int)A.size() - 1, idx, new_value); }
/*****************************************************************************************/

int main(){
	int ceros = 2;
	while(ceros){
		int n,m;
		scanf("%d",&n);
		mii lluvias;
		vi A;
		if(n){
			ceros=2;
			int y,mili;
			for (int i = 0; i < n; ++i)
			{
				scanf("%d %d",&y,&mili);
				lluvias[y]=i;
				A.push_back(mili);
			}
		}else{
			ceros--;
		}
		vi st;
		if(n)st_create(st, A);
		scanf("%d",&m);
		if (m)			
		{	ceros=2;
			if(n){
				int rr,yy;
				for (int i = 0; i < m; ++i)
				{
					scanf("%d %d",&rr,&yy);
					int posr,posy;
					if(lluvias.count(rr) && lluvias.count(yy)){
						posr=lluvias[rr];
						posy=lluvias[yy];
						if(st_rmq(st, A, posr, posy)==posr){
							if((yy-rr) == (posy-posr))
								printf("true\n");
							else
								printf("maybe\n");
						}else{
							printf("false\n");
						}
					}else{
						printf("maybe\n");
					}					
				}
			}else{
				for (int i = 0; i < m; ++i)
				{
					printf("false\n");
				}
			}
			
			
		}else{
			ceros--;
		}
		if(ceros)
			printf("\n");
	}
  


 return 0;   

}