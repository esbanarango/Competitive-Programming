/*TIME LIMIT*/

using namespace std;
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
 
 
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(){
	int numS=0; scanf("%d",&numS);
	int res=numS;
	vector<string> strings;
	vector<string> superEse;
	string sTemp;
	//Data
	while(res--){
		cin>>sTemp;
		strings.push_back(sTemp);
	}
	int sizeSuperS = 0;
	int iSize = strings.size();
	//Generating substrings
	for (int i = 0; i < iSize; ++i)
	{
		int tamS=strings[i].size();
		//cout<<endl<<"El string: "<<strings[i]<<" ";
		int tamHasta = tamS*(tamS+1)/2;
		for(int k=0,m=0,n=1,c=tamS;k<tamHasta;++k){
			string subSTemp = strings[i].substr(m,n);
		//	cout<<subSTemp<<" "<<m<<"-"<<n;
			if(find(superEse.begin(), superEse.end(), subSTemp)==superEse.end())
				superEse.push_back(subSTemp);
			n++;
			if(n>c){
				c--;
				m++;
				n=1;
			}
			/*for (int k = j,p=1; k < strings[i].size(); ++k,++p)
			{
				string subSTemp = strings[i].substr(j,p);
				if(find(superEse.begin(), superEse.end(), subSTemp)==superEse.end())
					superEse.push_back(subSTemp);
			}*/
		}
	}
	qsort (superEse, superEse.size(), sizeof(string), compare);
	//sort(superEse.begin(),superEse.end());
	/*vector<string>::iterator it;
	it = unique (superEse.begin(), superEse.end());
	superEse.resize( it - superEse.begin() ); */
 
	/*for (int i = 0; i < superEse.size(); ++i)
	{
		cout<<"-"<<superEse[i];
	}*/
	int q;scanf("%d",&q);
	while(q--){
		int k;
	 	scanf("%d",&k);
	 	if(k-1>=superEse.size())
	 		printf("INVALID\n");
	 	else
	 		cout<<superEse[k-1]<<endl;
	}
 
    return 0;
}
