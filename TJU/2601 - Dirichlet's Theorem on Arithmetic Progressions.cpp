/*
  2601 - Dirichlet's Theorem on Arithmetic Progressions
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/
#include<iostream>
#include<math.h>

using namespace std;

//Prime function with sqrt.
int PN(int num){
    int div, prime;
    prime=1;
    div=2;
    if(num!=1){
        while (div<=sqrt(num) && prime==1){
              if (num % div==0)
                 prime=0;
              else
                 prime=1;
                 div++;
        }
        return(prime);
    }else{
     return 0;
    }
}

int main(){
    
    long long int a,b,n,j,num,primes;
    
    while(cin>>a>>b>>n && a && b && n){
                       
             primes=0;          
            //sequence
            for(int i=0;n>0;i++){  
               num=a+b*i;
               //prime or not prime
               if(PN(num)==1){n--;}
            } 
            cout<<num<<endl;                    
    }   
 return 0;   
}
