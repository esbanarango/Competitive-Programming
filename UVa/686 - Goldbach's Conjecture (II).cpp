/*
  686 - Goldbach's Conjecture (II)
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE=1000000;

bool criba[SIZE+1];

void buildCriba(){
     memset(criba,false,sizeof(criba));
     
     criba[0]=criba[1]=true;
     for(int i=4; i<SIZE; i+=2){
           criba[i]=true;
     }
     for(int i=3;i*i<=SIZE;i+=2){
        if(!criba[i]){
             for(int j=i*i;j<=SIZE;j+=i){
                 criba[j]=true;  
             }
        }   
     }
}

int main(){
    int n;
    buildCriba();
    scanf("%d",&n);
    while(n){
             int cont=0;
               for(int i=3;i<n/2;i+=2){
                     if(criba[i]==false){
                                 for(int j=i;j<=n;j+=2){
                                       if((criba[j]==false) && (j + i ==n)){cont++;}  
                                 }       
                     } 
               }    
               printf("%d\n",cont); 
               scanf("%d",&n);   
    }
    return 0;               
}





