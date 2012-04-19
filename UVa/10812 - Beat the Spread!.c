/*
  10812 - Beat the Spread!
  UVa Online Judge
  Esteban Arango Medina

    Solution.
      Ad-hoc. 

    ANSI C Version.

*/

#include <stdio.h>
#include <math.h>
#define min(a, b) (((a) < (b)) ? (a) : (b)) 
#define max(a, b) (((a) > (b)) ? (a) : (b)) 
int main(){
    int n;scanf("%d",&n);
    while(n--){
        int s,t,x,y;
        scanf("%d %d",&s,&t);
        y=fabs(s-t)/2;
        x=s-y;
        if((x+y==s) && (fabs(x-y)==t))
            printf("%d %d\n",max(x,y),min(x,y));
        else
            printf("impossible\n");
    }
 return 0;   
}