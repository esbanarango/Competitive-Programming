/*
  10696 - f91
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<iostream>

using namespace std;

int main(){
    int n;
    while(scanf("%d",&n) && n){
        if(n>100){     
               printf("f91(%d) = %d\n", n,n-10);
        }else{
               printf("f91(%d) = %d\n", n,91);   
        }  
    }
 return 0;   
}
