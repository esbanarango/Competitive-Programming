/*
  11000 - Bee  
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/

#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    int n;
    
    cin>>n;
    
    while(n!=-1){
           
           vector <long long int> fib;
           fib.push_back(0);
           fib.push_back(1);

           for (int i = 2; i < n+4; i++){
                   fib.push_back(fib[i-1] + fib[i-2]);
           }
           cout<<fib[n+2]-1<<" "<<fib[n+3]-1<<endl;
           cin>>n;
    }
    return 0;
}
