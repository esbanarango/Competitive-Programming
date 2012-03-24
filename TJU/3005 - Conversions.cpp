/*
  3005 - Conversions 
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    
    int n,cas=1;
    double num;
    string tp;
    scanf("%d",&n);
    while(n--){
          cin>>num>>tp;
          if(tp=="kg"){cout<<fixed<<setprecision(4)<<cas<<" "<<(num*2.2046)/1.000<<" lb"<<endl;}
          else if(tp=="l"){cout<<fixed<<setprecision(4)<<cas<<" "<<(num*0.2642)/1.0000<<" g"<<endl;}
          else if(tp=="lb"){cout<<fixed<<setprecision(4)<<cas<<" "<<(num*0.4536)/1.0000<<" kg"<<endl;}
          else{cout<<setprecision(4)<<cas<<" "<<(num*3.7854)/1.0000<<" l"<<endl;}
          cas++;            
    }   
 return 0;   
}
