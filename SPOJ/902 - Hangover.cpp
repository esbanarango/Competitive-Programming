/*
  902 - Hangover
  Sphere Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include <cstdio>

int main (){
    double num,temp;
    while(scanf("%lf",&num) && num ){
            temp=0;
            int resp=1;
            while(temp<=num){
                    temp+=(double) 1/(resp+1);
                    resp++;         
            }            
            printf("%d card(s)\n",resp-1);
    }   
    
 return 0;   
}
