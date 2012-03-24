/*
  10260 - Soundex
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/
#include<iostream>
#include<string>

using namespace std;

int main(){
    
    string soundex[6] = {"BFPV","CGJKQSXZ","DT","L","MN","R"};
    string word;
    
    while(getline(cin,word)){
          int actual=-1;
          int tam= word.size();
          for(int i=0;i<tam;i++){
                  for(int j=0;j<6;j++){
                         size_t found=soundex[j].find(word[i]);
                         if(found!=string::npos){ 
                                   //ask if it was not in the same subset exactly before.               
                                   if(actual!=j){                             
                                       cout<<j+1;
                                       actual=j; 
                                       break;        
                                   }else{break;}
                          //If the letter is not a soundex letter.                     
                         }else if(j+1==6){actual=-1;}
                  }
          }  
          cout<<endl;  
    }
 return 0;   
}
