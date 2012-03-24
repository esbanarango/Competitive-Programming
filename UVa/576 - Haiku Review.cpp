/*
  576 - Haiku Review
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<iostream>
#include<string>

using namespace std;

int main(){
    string line;
    string vowels = "aeiouy";
    
    getline(cin,line);
    while(line!="e/o/i"){
                         
          int tam=line.size();
          int syllables[3]={0};
          int pos=0;
          
          for(int i=0;i<tam;i++){
                  if(line[i]=='/'){pos++;}
                  else{
                       size_t found;
                       found=vowels.find_first_of(line[i]);
                       if(found!=string::npos){
                                syllables[pos]++;
                                found=vowels.find_first_of(line[i+1]);
                                while(found!=string::npos){
                                            i++;
                                            found=vowels.find_first_of(line[i+1]);                   
                                }                 
                       }
                  }
          }
          if(syllables[0]!=5){cout<<1<<endl;}
          else if(syllables[1]!=7){cout<<2<<endl;}
          else if(syllables[2]!=5){cout<<3<<endl;}
          else{cout<<"Y"<<endl;}
          getline(cin,line);       
    }
    
}
