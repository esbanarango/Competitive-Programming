/*
  4233  - Cryptoquote
  ACM-ICPC Live Archive
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<iostream>
#include<string>

using namespace std;

int main(){
    int cases;
    int cont=1;
    
    string message;
    string alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string newAlphabet;
     
    cin>>cases;
    getline(cin,message);
    
    while(cases){
         getline(cin,message);
         getline(cin,newAlphabet);
         for(int i=0;i < message.size();i++){
                 for(int j=0;j<26;j++){
                         if(message[i]==alphabet[j]){                     
                                  message[i]=newAlphabet[j];               
                                  break;                   
                         }
                 } 
         } 
         cout<<cont<<" "<<message<<endl;
         cont++;
         cases--;            
    }
  
 return 0;   
}
