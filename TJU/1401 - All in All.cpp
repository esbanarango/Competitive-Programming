/*
  1401 - All in All
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<iostream>
#include<string>

using namespace std;

int main(){
    
    string s,t;
    while(cin>>s>>t){      
                 int tamS=s.size();
                 int tamT=t.size();
                 int i=0,j=0;
                 while(j<tamT){    
                         if(s[i]==t[j]){
                                i++;
                                j++;        
                         }else{j++;}
                 }
                 if(i==tamS){cout<<"Yes"<<endl;}
                 else{cout<<"No"<<endl;} 
    }                      
 return 0;   
}
