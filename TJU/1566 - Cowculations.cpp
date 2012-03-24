/*
  1566 - Cowculations
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<iostream>
#include<string>

using namespace std;

string num1,num2,result;

void operation(char op){
     
     char carry='x';
     int tam1 = num1.size();
     int tam2 = num2.size();
     string temp1=num1;
     
     if(op == 'R'){
           num2=num2.substr(0,num2.size()-1);
           num2.insert(0,"V");
           tam2 = num2.size(); 
              
     }else if(op == 'L'){
           num2.push_back('V');
           tam2 = num2.size();
           
     }else if(op == 'A'){
           
           for(int i=tam1-1, j=tam2-1; i>-1; i--,j--){   
               if(carry != 'x'){
                      if(temp1[i]=='U'){
                                    temp1[i]= 'C';
                                    carry='x';
                       }else if(temp1[i]=='C'){
                                    temp1[i]= 'D';
                                    carry='x';
                       }else if(temp1[i]=='D'){
                                    temp1[i]= 'V';
                                    carry='U';
                       }else if(temp1[i]=='V'){
                                    temp1[i]= 'U';
                                    carry='x';
                       }
               }
                   if(temp1[i]=='V'){
                         //equal                  
                   }else{
                       if(temp1[i]=='U' && num2[j]=='U'){num2[j]= 'C';}
                       else if((temp1[i]=='U' && num2[j]=='C')||(num2[j]=='U' && temp1[i]=='C')){num2[j]= 'D';}
                       else if((temp1[i]=='U' && num2[j]=='D')||(num2[j]=='U' && temp1[i]=='D')){
                                    num2[j]= 'V';
                                    carry='U';
                       }else if(temp1[i]=='C' && num2[j]=='C'){
                                    num2[j]= 'V';
                                    carry='U';
                       }else if((temp1[i]=='C' && num2[j]=='D')||(num2[j]=='C' && temp1[i]=='D')){
                                    num2[j]= 'U';
                                    carry='U';
                       }else if(temp1[i]=='D' && num2[j]=='D'){
                                    num2[j]= 'C';
                                    carry='U';
                       }else if(num2[j]=='V'){num2[j]=temp1[i];}  
                   }      
           }
           if(carry != 'x'){num2.insert(0,"U");}
     }else{
           //null operation
     }
}

int main(){
    int cases;
    char op;
    
    cout<<"COWCULATIONS OUTPUT"<<endl;

    cin>>cases;
    
    while(cases--){
         cin>>num1;
         cin>>num2;          
         cin>>op;
         operation(op);
         cin>>op;
         operation(op);
         cin>>op;
         operation(op);
         cin>>result;
         
         //if the num2 doesn't have 8 characters
         if(num2.size()<8){
              for(int i=0;i < (10-num2.size());i++){
                      num2.insert(0,"V");
              }             
         }  
         
         if(result==num2){cout<<"YES"<<endl;}
         else{cout<<"NO"<<endl;}             
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;    
}
