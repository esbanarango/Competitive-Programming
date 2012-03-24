/*
  591 - Box of Bricks
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    int n;
    int set=1;

    while(scanf("%d",&n) && n){
           
           vector <int> bricks;
           int brick;
           int media=0;
           int moves=0;
           
           for(int i=0;i<n;i++){
                 int brick;
                 scanf("%d",&brick);
                 media+=brick;
                 bricks.push_back(brick);
           }
           media/=n;
           for(int i=0;i<n;i++){
                 if(bricks[i]>media){
                     moves += bricks[i]- media;               
                 }  
           } 
           printf("Set #%d\n", set);
           printf("The minimum number of moves is %d.\n\n", moves);
           set++;
           
    }
    
    
 return 0;   
}
