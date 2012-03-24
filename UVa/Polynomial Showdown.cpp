/*
  100 - The 3n + 1 problem
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/


//WHAT A UGLY CODE!!!!

#include<iostream>

using namespace std;

int main(){
    int coef;
    int i=8;
    bool primero=true;
    for(;scanf("%d",&coef)!=EOF;i--){
            if(i==0){
                   i=9;
                   if(coef>0 && primero){
                      cout<<coef<<endl;
                   }else if(coef<0 && primero){
                      cout<<coef<<endl;  
                   }else if(coef<0 && !primero){
                      coef*=-1;
                      cout<<" - "<<coef<<endl;  
                   }else if(coef>0 && !primero){
                      cout<<" + "<<coef<<endl;  
                   }else if(coef>0 && !primero){
                      cout<<" + "<<coef<<endl;  
                   }else if(coef==0 && primero){
                      cout<<coef<<endl;  
                   }else{cout<<endl;}
                   primero=true;
            }else if(i==1){
                  if(coef!=0 && coef>1 && primero){
                              cout<<coef<<"x";
                              primero=false;
                  }else if(coef!=0 && coef<-1 && primero){
                              cout<<coef<<"x";
                              primero=false;
                  }else if(coef!=0 && coef==1 && primero){
                              cout<<"x";
                              primero=false;
                  }else if(coef!=0 && coef==-1 && primero){
                              cout<<"-x";
                              primero=false;
                  }else if(coef!=0 && coef>1 && !primero){
                              cout<<" + "<<coef<<"x";
                  }else if(coef!=0 && coef<-1 && !primero){
                              coef*=-1;
                              cout<<" - "<<coef<<"x";
                  }else if(coef!=0 && coef==1 && !primero){
                              cout<<" + "<<"x";
                  }else if(coef!=0 && coef==-1 && !primero){
                              coef*=-1;
                              cout<<" - "<<"x";
                  }
                  
            }else{
                  if(coef!=0 && coef>1 && primero){
                              cout<<coef<<"x^"<<i;
                              primero=false;
                  }else if(coef!=0 && coef<-1 && primero){
                              cout<<coef<<"x^"<<i;
                              primero=false;
                  }else if(coef!=0 && coef==1 && primero){
                              cout<<"x^"<<i;
                              primero=false;
                  }else if(coef!=0 && coef==-1 && primero){
                              cout<<"-x^"<<i;
                              primero=false;
                  }else if(coef!=0 && coef>1 && !primero){
                              cout<<" + "<<coef<<"x^"<<i;
                  }else if(coef!=0 && coef<-1 && !primero){
                              coef*=-1;
                              cout<<" - "<<coef<<"x^"<<i;
                  }else if(coef!=0 && coef==1 && !primero){
                              cout<<" + "<<"x^"<<i;
                  }else if(coef!=0 && coef==-1 && !primero){
                              coef*=-1;
                              cout<<" - "<<"x^"<<i;
                  }
                  
            }
    } 
 return 0;   
}
