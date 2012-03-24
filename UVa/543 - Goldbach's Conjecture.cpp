/*
  543 - Goldbach's Conjecture
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE=1000001;

bool criba[SIZE+1];

void buildCriba(){
     memset(criba,true,sizeof(criba));
     
     criba[0]=criba[1]=false;
     for(int i=4; i<SIZE; i+=2){
           criba[i]=false;
     }
     for(int i=3;i*i<=SIZE;i+=2){
        if(criba[i]){
             for(int j=i*i;j<=SIZE;j+=i){
                 criba[j]=false;  
             }
        }   
     }
}

int main(){
    int n;
    buildCriba();
    while(scanf("%d",&n) && n ){
               int cont=0,i;
               for(i=3;i<=n/2;i+=2){
                     if(criba[i] && criba[n-i]){
                                  printf("%d = %d + %d\n",n,i,n-i);
                                  break;               
                     }  
               }       
    }
    return 0;               
}





