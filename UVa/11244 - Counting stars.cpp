/*
  11244 - Counting Stars
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/
#include<iostream>

using namespace std;

int main(){   
    int f;
    int c;
    int stars;
    bool star=true;

   cin>>f>>c;
   
   while(f!=0){
               
   stars = 0;
   
   char matriz [f][c];
   
   for(int i=0;i<f;i++){
         for(int j=0;j<c;j++){
               
               cin>>matriz[i][j];        
               
               
               }

         }
         
    for(int i=0;i<f;i++){
         for(int j=0;j<c;j++){
               
               if(matriz[i][j] == 42){
                        for(int k=0;k<3;k++){
                                for(int l=0;l<3;l++){
                                        
                                        if(((i+k-1)<f) && ((j+l-1)<c)){
                                                    if(((i+k-1)>-1) && ((j+l-1)>-1)){
               
                                                        if((matriz[i+k-1][j+l-1] == 42) && !((i+k-1)== i  && (j+l-1)==j)){
                                                            star = false;
                                                        }       
                                                    } 
                                        }
               
                                 }

                        }                
                
                if(star == true){
                     stars++;
               }                        
               }
               star= true;        
               }

         }
    
    cout<<stars<<endl;
    cin>>f>>c;
         }  
 return 0;   
}
