/*
  2636 - Hanafuda Shuffle
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/
#include<iostream>

using namespace std;

int *array1;
int *array2;

int main(){
   int cases;
   int n;
   int r;
   
   while(cin>>n>>r && n  && r){
                   
          int cards = n-1;          
                    
          array1 = new  int[n]; 
          array2 = new  int[n];
          
          for(int i=0;i<n;i++){
                  array1[i]=n-i;
                  array2[i]=0;
                
          }
          int p,c;
          
          for(int x=0;x<r;x++){
                cin>>p>>c;
                int j=0;
                
                for(int i=p-1;i<(p+c)-1;i++,j++){
                      array2[j]=array1[i];
                }
                for(int i=0;i<(p-1);i++){
                      array2[j]=array1[i];
                      j++;
                }
                for(int i=j;i<cards+1;i++){
                      array2[j]=array1[i];
                      j++;  
                }
                
                array1=array2;
                array2 = new int[n];

                             }
          cout<<array1[0]<<endl;
      
   }
    return 0;
}
