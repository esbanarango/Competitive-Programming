/*
  10035 - Primary Arithmetic
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    string num1,num2;
    cin>>num1>>num2;
    
    while(num1!="0" || num2!="0"){
                  int tam1,tam2;
                  int carries=0;
                  int carry = 0;
                  int aux=0;
                  if(num1.size()>num2.size()){
                        tam1=num1.size();
                        tam2=num2.size();                   
                  }
                  else{
                       tam1=num2.size();
                       tam2=num1.size();
                       string temp=num1;
                       num1=num2;
                       num2=temp;
                  }
                  
                  for(int i = tam1-1, j=tam2-1;i> -1;i--){
                        num1[i]= ((num1[i] - '0') + carry)+'0';
                        if(j>-1){
                            aux= (num1[i]- '0') + (num2[j]- '0');
                            j--;
                        }else{
                            aux= (num1[i]- '0');  
                        }
                        if(aux>=10){
                               num1[i]=(aux-10)+'0';
                               carries++;
                               carry=1;
                        }else{
                               num1[i]=aux+'0';
                               carry=0;  
                        }
                        
                  }
                  if(carries>1){cout<<carries<<" carry operations."<<endl;}
                  else if(carries==1){cout<<carries<<" carry operation."<<endl;}
                  else{cout<<"No carry operation."<<endl;}
               
          cin>>num1>>num2;     
    }
    
    
 return 0;   
}
