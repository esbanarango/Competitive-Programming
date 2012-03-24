/*
  113 - Power of Cryptography
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/


#include<iostream>
#include<math.h>
#include <iomanip>


using namespace std;

int main(){
    
    long double n,p;
    
    while(cin>>n>>p){       
            cout<<setprecision(0);
            cout<<fixed<<(long double)pow(2.71828182845904523536,(long double)log(p)/n)<<endl;
    }
   
 return 0;   
}
