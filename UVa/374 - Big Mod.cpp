/*
  374 - Big Mod
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include <iostream>

using namespace std;

int main(){
 long b,p,m;
 
 while(cin>>b>>p>>m){
         long mask = 1;
         long pow2 = b % m;
         long r = 1;
         while (mask){
              if (p & mask)
                    r = (r * pow2) % m;
                    pow2 = (pow2*pow2) % m;
                    mask <<= 1;
         }
         cout<<r<<endl;
         
 }   
    
 return 0;   
}
