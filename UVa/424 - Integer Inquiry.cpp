/*
  424 - Integer Inquiry
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<iostream>
#include<string>

using namespace std;

int main(){
    string num1,num2;
    cin>>num1;
    cin>>num2; 
    while(num2!="0"){                   
                  int tam1,tam2;
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
                               carry=1;
                        }else{
                               num1[i]=aux+'0';
                               carry=0;  
                        }
                        
                  }
                  if (carry == 1){
                              num1.insert(0,"1");
                  } 
          cin>>num2;     
    }
    cout<<num1<<endl;
    
 return 0;   
}
