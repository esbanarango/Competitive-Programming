/*
  3507 - Judging Olympia
  PKU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/
#include<iostream>

using namespace std;

int main(){
    int grades[6];
    bool fin=false;
    while(!fin){
                int max=0,min=11,total=0;
                for(int i=0;i<6;i++){
                        cin>>grades[i];
                        if(grades[i]>max){max=grades[i];}
                        if(grades[i]<min){min=grades[i];}
                        total+=grades[i];
                }
                if(total!=0){cout<<(double)(total-min-max)/4<<endl;}
                else{fin=true;}
    }
 return 0;   
}
