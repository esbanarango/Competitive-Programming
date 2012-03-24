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


int LCS(string X,string Y)
{
     if (Y.length() > X.length())
        swap(X,Y);
     int m = X.length(),n=Y.length();
     vector< vector<int> > c(2, vector<int>(n+1,0));
     int i,j;
     for (i=1;i<=m;i++)
     {
         for (j=1;j<=n;j++)
         {
             if (X[i-1]==Y[j-1])
                c[1][j]=c[0][j-1]+1;
             else
                 c[1][j]=max(c[1][j-1],c[0][j]);
         }
    	 for (j=1;j<=n;j++)
    		 c[0][j]=c[1][j];
     }
     return (c[1][n]);
}


int main(){
   string s1,s2;
   cin>>s1;
   cin>>s2;

   cout<<LCS(s1,s2);
}