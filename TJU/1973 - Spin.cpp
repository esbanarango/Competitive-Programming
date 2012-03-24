/*
  1973 - Spin
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/

#include<iostream>
#include<string>

using namespace std;


int main (){

    string temp;
    int num1;
    int num[10];

    getline (cin,temp);
    
    int tam=temp.size();
    
    for(int i = 0; i < tam; i++){
            num[i]=int(temp[i]-48);
    }
    while(getline (cin,temp)) {

        for(int i = 0; i < tam; i++){
                if(temp[i]!='0'){
                                 
                    num1 = int(temp[i]-48);
                    num1+=num[i];

                    if((10-num1)>0){ num[i]=num1;}
                    else{
                          num1-=10;
                          num[i]=num1;
                    }
                }
        } 
    }
    for(int i = 0; i < tam; i++){
            cout<<num[i];
    }
    cout<<endl;
   return 0; 
}
