/*
  2791 - Bovine Latin 
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/
#include<iostream>
#include<string>

using namespace std;

int main(){
    int cases;
    string word;
    string vowels = "aeiou";
    scanf("%d",&cases);
    while(cases--){
            cin>>word;
            size_t found;
            found=vowels.find_first_of(word[0]);
            if(found!=string::npos){
                      cout<<word<<"cow"<<endl;             
            }else{
                  word.push_back(word[0]);
                  word.erase(0,1);
                  cout<<word<<"ow"<<endl;
            }
    }
    
    
 return 0;   
}
