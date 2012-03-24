/*
  1196 - Web Navigation 
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/

#include<iostream>
#include<string>
#include <stack>


using namespace std;

int main(){
    
    stack<string> pageForward;
    stack<string> pageBack;
    
    string line;
    string url;
    string current("http://www.acm.org/");
    
    getline(cin,line);
    
    while(line!="QUIT"){
    
          if(line=="FORWARD"){
                if(!pageForward.empty()){
                     pageBack.push(current);
                     current=pageForward.top();
                     pageForward.pop();
                     cout<<current<<endl;
                }else{
                     cout<<"Ignored"<<endl; 
                }              
          
          }else if (line=="BACK"){
                
                if(!pageBack.empty()){
                     pageForward.push(current);
                     current=pageBack.top();
                     pageBack.pop();
                     cout<<current<<endl;
                }else{
                     cout<<"Ignored"<<endl; 
                }
          
          }else{
                  pageBack.push(current);   
                  url = line.substr (6);
                  current=url;
                  while(!pageForward.empty()){
                     pageForward.pop();
                  }
                  cout<<url<<endl;
                  
          }
          getline(cin,line);                    
    }

 return 0;   
}
