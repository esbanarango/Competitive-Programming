/*
  10013 - Super long sums
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(int argc, char *argv[]){
    
    int cases = 0;//número de casos.
    int length = 0;//Tamañno de los númeors a sumar.
    int aux1 = 0;//Auxiliar para ir metiendo los números al vetor1.
    int aux2 = 0;//Auxiliar para ir metiendo los números al vetor2.
    string vacio;
    
    scanf("%d",&cases);
    
    while(cases--){
      
      vector <int> numero1;
      vector <int> numero2;             
      cin>>length;
      
      //Se ingresan los números a los vectores.
      for (int i = 0;i< length;i++){
               scanf("%d %d",&aux1,&aux2);
               numero1.push_back(aux1);
               numero2.push_back(aux2);
      }
      
      int carried=0;
      int aux;
      
      for (int i = length-1;i> -1;i--){
          
               numero1[i]+= carried;
               aux= numero1[i] + numero2[i];
               if(aux>=10){
                    numero1[i]=aux-10;
                    carried=1;
               }else{
                   numero1[i]=aux;
                   carried=0;  
               }
      }
      
      if (carried == 1){
      printf("%d", 1);
      }                         
      
      
      for (int i = 0;i< length;i++){
          printf("%d", numero1[i]);
      }
      cout<<endl;
      
      if(cases!=0){
            printf("\n");
      }            
                   
    }
 return 0;   
}
