/*
  22775 - Bee Tree  
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/

#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    int cases;
    
    cin>>cases;
    //scanf("&d",&cases);
    
    while(cases--){
           
           int n;

           cin>>n;
           //scanf("%d",&n);
           
           vector <int> fib;
           fib.push_back(0);
           fib.push_back(1);

           for (int i = 2; i < n+3; i++){
                   fib.push_back(fib[i-1] + fib[i-2]);
           }
           cout<<fib[n+1]<<" "<<fib[n+2]<<endl;
    }
    return 0;
}
