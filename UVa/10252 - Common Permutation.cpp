/*
  10252 - Common Permutation
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/


#include<iostream>
#include <algorithm>
#include<string>
#include<vector>

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
