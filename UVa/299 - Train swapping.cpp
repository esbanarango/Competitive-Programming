/*
  299 - Train Swapping
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/
#include <iostream>

using namespace std;


int swap(int lista[], int tam){
      
      int TAM=tam;
      int temp=0;
      int cont= 0;
      
      for (int i=1; i<TAM; i++){
          for (int j=0 ; j<TAM - 1; j++){
              if (lista[j] > lista[j+1]){
                           cont++; 
                       temp = lista[j];
                       lista[j] = lista[j+1];
                       lista[j+1] = temp;
              }
          }      
      }
      return cont;
}


int main(){
    
    int sc;
    cin>>sc;
    while (sc) {
          
        int tam;  
        cin>>tam;
        int train[tam];
        
        for(int i = 0; i < tam;i++){cin>>train[i];}
        int resp;
        resp = swap(train,tam);
        
        cout<<"Optimal train swapping takes "<<resp<<" swaps."<<endl;
        sc--;
    }
    
}


