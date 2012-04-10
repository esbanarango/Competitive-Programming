/*
  458 - The Decoder
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    
   string frase;
   while(getline (cin,frase)) {
            int tam = frase.size();
            char c;
            int num;      
            for(int i=0;i<tam;i++){
                 num=frase[i];
                 c=num-7;   
                 cout<<c;   
            }      
            cout<<endl;  
   }

return 0;
} 
