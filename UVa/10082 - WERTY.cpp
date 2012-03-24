/*
  10082 - WERTYU
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/
#include<iostream>

using namespace std;

char cambio (char letra){
     
     string fila1 = "`1234567890-=";
     string fila2 = "QWERTYUIOP[] ";
     string fila3 = "ASDFGHJKL;'  ";
     string fila4 = "ZXCVBNM,./   ";
     
     bool encontro = false;
     
     char newLetra = ']';
     
     for(int i = 0 ; (i < 13) && (!encontro) ; i++){
             
             if(letra == fila1.at(i)){
                      encontro=true;
                      newLetra = fila1.at(i-1);
                              
             }
             else if(letra == fila2.at(i)){
                  encontro=true;
                  newLetra = fila2.at(i-1);
                              
             }
             else if(letra == fila3.at(i)){
                  encontro=true;
                  newLetra = fila3.at(i-1);
                              
             }
             else if(letra == fila4.at(i)){
                  encontro=true;
                  newLetra = fila4.at(i-1);
                              
             }
     }
     
     return newLetra;
}


int main(int argc, char *argv[]){

    char letra;
    
    string frase;
    
    while(getline (cin,frase)) {

    for(int i = 0; i < frase.size(); i++){
            
            letra = frase.at(i);
            
            if (letra == ' '){
                      cout<<" ";
            }else{ cout<<cambio(letra);}
        
    }
    cout<<endl;
}
    return 0;
     
}
