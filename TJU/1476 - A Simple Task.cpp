/*
  1476 - A Simple Task
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/
#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int n,d,num;
    cin>>d;
    while(d--){
         cin>>n;
         num = 0;
         if ( n%2 != 0 ){cout<<n<<" "<< "0"<<endl;}
         else{
            for(;n%2==0;num++){
                  n/=2;             
            }
            cout<<n<<" "<<num<<endl;
         }                        
    }
  
 return 0;   
}
