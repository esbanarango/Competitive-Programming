


#include <iostream>
#include <string>

using namespace std; 

void cryptanalysis(int numero);
void organizar();

typedef struct Tletras
      {
      char letraM;
      char letram;
      int veces;
      };
      
struct Tletras letras [26];

void cryptanalysis(int numero){
     char txt[100];
     txt[0]=getchar();
     
     for(int i=0; i<numero; i++){
             for(int n=0;(txt[n]=getchar()) != '\n';++n){
                     for(int i=0;i<26;i++){
                             if(txt[n]==letras[i].letraM || txt[n]==letras[i].letram){
                                      letras[i].veces = letras[i].veces + 1;                   
                                      i=i+26;
                             }
                     } 
             }  
     }  
     
}

void organizar(){
      
      int TAM=26;
      struct Tletras temp;
      
      for (int i=1; i<TAM; i++){
          for (int j=0 ; j<TAM - 1; j++){
              if (letras[j].veces < letras[j+1].veces){
                       temp = letras[j];
                       letras[j] = letras[j+1];
                       letras[j+1] = temp;
              }
          }
      }
}


int main(int argc, char *argv[]){
    
    int numero=0;
    
    for (int i = 0; i<26;i++){
        letras[i].letraM = (char)('A' + i);
        letras[i].letram = (char)('a' + i);
        letras[i].veces = 0;
    }
    
    cin>>numero;
    
    cryptanalysis(numero);
    organizar();
    
    
    for (int i = 0; i<26;i++){
        if(letras[i].veces != 0){
               cout<<letras[i].letraM<<" "<<letras[i].veces<<endl;
        }
    }
    return 0;
     
}
