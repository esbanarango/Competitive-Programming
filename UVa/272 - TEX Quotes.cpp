/*
  272 - TEX Quotes
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<iostream>
#include<string>

using namespace std;

int main(){
    
   string frase;
   string str1="``"; 
   string str2="''";
   bool primero=true; 
    while(getline (cin,frase)) {      
            for(int i=0;i<frase.size();i++){
                  if(frase[i]=='"'){
                        if(primero){
                            frase.erase(i,1);
                            frase.insert(i,str1);       
                            primero=false;        
                        }else{
                            frase.erase(i,1);
                            frase.insert(i,str2);
                            primero=true; 
                        }                  
                  }      
            }   
            cout<<frase<<endl;
   }  
 return 0;   
}
