/*
  492 - Pig-Latin
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<string>
#include<iostream>

using namespace std;

int main(){
    
    string line;
    string vowels = "aeiou";
    
    while(getline (cin,line)) {
                  int tam = line.size();
                  int j=0;
                  char temp;
                  bool yes=false;;
                  size_t found;
                  for(int i=0;i<tam;){
                        found=vowels.find_first_of(tolower(line[i]));
                        if(found!=string::npos){
                                cout<<line[i];
                                for(j=i+1;line[j]!=' ' && j<tam && isalpha(line[j]);j++){
                                          cout<<line[j];
                                }
                                cout<<"ay";
                                if(j<tam){cout<<line[j];}
                                i+=(j-i)+1;    
                        }else{   
                                if(isalpha(line[i])){
                                        temp=line[i];
                                        for(j=i+1;line[j]!=' ' && j<tam && isalpha(line[j]);j++){
                                          cout<<line[j];
                                        }
                                        cout<<temp;
                                        cout<<"ay";
                                        if(j<tam){cout<<line[j];}
                                        i+=(j-i)+1; 
                                }else{
                                      cout<<line[i];
                                      for(j=i+1;line[j]!=' ' && j<tam && !isalpha(line[j]);j++){
                                          cout<<line[j];
                                      }
                                      i+=(j-i); 
                                }
                                 
                              
                        }
                  }
                  cout<<endl;
    }
    
 return 0;   
}
