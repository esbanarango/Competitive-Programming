/*
  591 - Geometry Made Simple
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/
#include<iostream>
#include <math.h>
//a*a+b*b=c*c
int main(){
    
    int cases=1;
    double a,b,c;
    
    while(scanf("%lf%lf%lf",&a,&b,&c) && a && b && c){
            if(a==-1){
                      
                      if((c-b)<0){
                            printf("Triangle #%d\n",cases);
                            cases++;
                            printf("Impossible.\n\n");
                      }else{
                            a=sqrt((c*c)-(b*b));
                            printf("Triangle #%d\n",cases);
                            printf("a = %.3lf\n\n",a);
                            cases++;
                      }
            }
            else if(b==-1){

                      if((c-a)<0){
                            printf("Triangle #%d\n",cases);
                            cases++;
                            printf("Impossible.\n\n");
                      }else{
                            b=sqrt((c*c)-(a*a));
                            printf("Triangle #%d\n",cases);
                            printf("b = %.3lf\n\n",b);
                            cases++;
                      }
                 
            }else{
                      c=sqrt((b*b)+(a*a));
                      printf("Triangle #%d\n",cases);
                      printf("c = %.3lf\n\n",c);
                      cases++;
            }    
    }   
 return 0;   
}
