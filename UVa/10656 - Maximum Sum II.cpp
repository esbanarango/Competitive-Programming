/*
  10656 - Maximum Sum (II)
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)&& n){
                int num;  
                bool print =true; 
                vector <int> nums;      
                for(int i=0;i<n;i++){
                      scanf("%d",&num);
                      if(num!=0){ nums.push_back(num); }
                      if(!num==0){
                           print=false;     
                      }
                }
                if(!print){printf("%d",nums[0]);
                for(int i=1;i<nums.size();i++){
                      printf(" %d",nums[i]); 
                }  
                printf("\n"); 
                }else{
                     printf("0\n"); 
                }                        
    }
 
 return 0;   
}
