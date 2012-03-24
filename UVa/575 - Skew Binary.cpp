/*
  575 - Skew Binary
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main(){
     string number;
     
     cin>>number;
       
     while(number!="0"){
                       
            int tam=number.size();
            int exp=tam;
            int num;
            long long int resp=0;
            for(int i=0;i<tam;i++){
                    num = int(number[i]-48);
                    resp+= int (num * ( pow(2,exp) - 1 ));   
                    exp--; 
            }           
            cout<<resp<<endl;           
            cin>>number;           
     }
 
 return 0;   
}
