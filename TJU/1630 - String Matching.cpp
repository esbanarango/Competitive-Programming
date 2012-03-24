/*
  1630 - String Matching  
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/
#include<iostream>
#include<string>
using namespace std;

int GCD(int a,int b) { 
  while (b > 0) { 
    a = a % b; 
    a ^= b;
    b ^= a;
    a ^= b;
  }
  return a; 
}

int main(){
    string a,b;
    while(cin>>a && a !="-1"){
                cin>>b;
                int tamA = a.size();
                int tamB = b.size();
                int aprox=0,temp,coci,deno,tempApr=0;
                for(int i=0; i<tamA; i++){
                      for(int j=0;j<tamB;j++){
                              int x=i,y=j;
                            while(x<tamA && y<tamB){
                                      if(a[x]==b[y]){
                                            tempApr++;         
                                      } 
                                      x++;
                                      y++;  
                            }
                            if(tempApr>aprox){aprox=tempApr;}
                            tempApr=0;
                            
                      }     
                } 
                temp = GCD(aprox*2,tamA+tamB);
                coci= ((aprox*2) / temp);
                deno= ((tamA+tamB) / temp);
                if(aprox==0){cout<<"appx("<<a<<","<<b<<") = 0"<<endl;}
                else if(coci==1 && deno==1){cout<<"appx("<<a<<","<<b<<") = 1"<<endl;}
                else{cout<<"appx("<<a<<","<<b<<") = "<<coci<<"/"<<deno<<endl;}
    }  
 return 0;   
}
