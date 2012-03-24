/*
  483 - Word Scramble
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<string>
#include<iostream>

using namespace std;

int main(){
    
    string line;
    
    while(getline (cin,line)) {
                  int tam = line.size();
                  int cont;
                  string sub;
                  for(int i=0;i<tam;i++){
                       cont=0;
                       if(line[i]!=' '){     
                                while(line[i+cont]!=' ' && i+cont<tam){
                                       cont++;          
                                }
                                for(int j=(i+cont)-1;i<=j && j<tam;j--){
                                          cout<<line[j];
                                }     
                                i+=cont-1;   
                       }else{
                            cout<<line[i]; 
                       }
                  }
                  cout<<endl;
    }
    
 return 0;   
}
