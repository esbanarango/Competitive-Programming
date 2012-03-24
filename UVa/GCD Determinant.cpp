
#include <iostream>
#include <cstdio>
#include <algorithm>


using namespace std;

//typedef long long int bigint;

int GCD(int a,int  b) { 
  while (b > 0) { 
    a = a % b; 
    a ^= b;
    b ^= a;
    a ^= b;
  }
  return a; 
}

int main(){
    
    int s;
    
    while (scanf("%d",&s)!=EOF){

          int matriz [s][s];
          int deter=0;
          int vector [s];
          int num;
          for(int i=0;i<s;i++){
                scanf("%d",&num);
                vector[i]=num;              
          }
          
          for(int i=0;i<s;i++){
                  for(int j=0;j<s;j++){
                          matriz[i][j]=GCD(vector[i],vector[j]);
                  }
          }
          for(int k=0; k<s-1; k++){
            for(int i=k+1; i<s; i++){
                for(int j=k+1; j<s; j++){
                        if(matriz[k][k]!=0){
                              matriz[i][j] = matriz[i][j] - ((matriz[i][k]*matriz[k][j])/matriz[k][k]);
                    }
                }
            }
        }
        deter=matriz[0][0];
       for(int i=1; i<s; i++){
            deter=deter*matriz[i][i];
        }
        //bigint resp = deter%1000000007;
        if(deter < 1000000007){
                printf("%d\n", deter);
              } else {
                printf("%d\n", deter % 1000000007);
        }
        //cout<<deter<<endl;
          
    }
   
 return 0;   
}
