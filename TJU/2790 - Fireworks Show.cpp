/*
  2790 - Fireworks Show  
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main(){
    unsigned long int c,n,cann,cont=0;
    vector <unsigned long int> times;
    cin>>c>>n;
    for(int i=0;i<c;i++){
          cin>>cann;
          int sum=cann;
          while(sum<=n){
                int it;
                it = (int) count (times.begin(), times.end(), sum);
                if(it==0){
                          times.push_back(sum);
                          cont++;
                }
                sum+=cann;
          }
    }
    cout<<cont;
 return 0;   
}
