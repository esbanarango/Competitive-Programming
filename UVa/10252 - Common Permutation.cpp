/*
  10252 - Common Permutation
  UVa Online Judge
  Esteban Arango Medina

  Solution.
    Organize both strings and compare them, if a[i]==b[j] add it to the string 'k' (response), if not, 
    then increment the string where a[i]<b[j] or viceversa.

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


int main(){
    string a,b;
    
    while(getline (cin,a)){
          getline (cin,b);        
          int tamA=a.size();
          int tamB=b.size();
          sort(a.begin(), a.end());
          sort(b.begin(), b.end());
          if (a == b){
             cout << a << endl;
             continue;
          }
          string k="";
          for(int i=0, j=0;i<tamA && j<tamB;){
            if(a[i]==b[j]){
                     k+= a[i];
                     i++;
                     j++;
            }else{
                  while (a[i] < b[j]){
                        ++i;
                        if (i == tamA) break;
                  }
                  while (b[j] < a[i]){
                        ++j;
                        if (j == tamB) break;
                  }
            }
          }
          cout<<k<<endl; 
    }
  
 return 0;   
}
