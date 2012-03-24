/*
  10370 - Above Average
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/

#include<iostream>
using namespace std;
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
            int n;       
            float grade,resp=0,average=0;
            scanf("%d",&n);
            float students[n];
            
            for(int i=0;i<n;i++){
                    scanf("%f",&grade);
                    students[i]=grade;
                    average+=grade;  
            }
            average/=n;
            for(int i=0;i<n;i++){
                    if(students[i]>average){
                            resp++;                
                    }
            }
            resp/=n;
            resp*=100;
            printf("%.3lf",resp);
            cout<<"%"<<endl;     
    }

 return 0;   
}
