/*
  1644 - Reverse Text 
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/

#include<iostream>
#include<string>

using namespace std;

int main(){
    int cases;
    
    scanf("%d",&cases);
    string line;
    getline(cin,line); 
          
    while(cases--){
          getline(cin,line);          
          int tam = line.size();
          for(int i=tam-1;i>=0;i--){
                cout<<line[i];
          }
          cout<<endl;        
                   
    }   
 return 0;   
}
