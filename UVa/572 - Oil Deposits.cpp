/*
  572 - Oil Deposits
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include <iostream>

using namespace std;
       
char matriz [100][100];
int fila=0;
int columna=0;

//backtraking
void confirmar(int x, int y){
     if(x+1<fila && matriz[x+1][y]=='@'){matriz[x+1][y]='*';confirmar(x+1,y);}
     if(x-1>=0 && matriz[x-1][y]=='@'){matriz[x-1][y]='*';confirmar(x-1,y);}
     if(y+1<columna && matriz[x][y+1]=='@'){matriz[x][y+1]='*';confirmar(x,y+1);}
     if(y-1>=0 && matriz[x][y-1]=='@'){matriz[x][y-1]='*';confirmar(x,y-1);}
     //Diagonal
     if(x-1>=0 && y-1>=0 && matriz[x-1][y-1]=='@'){matriz[x-1][y-1]='*';confirmar(x-1,y-1);}
     if(x-1>=0 && y+1<columna && matriz[x-1][y+1]=='@'){matriz[x-1][y+1]='*';confirmar(x-1,y+1);}
     if(x+1<fila && y-1>=0 && matriz[x+1][y-1]=='@'){matriz[x+1][y-1]='*';confirmar(x+1,y-1);}
     if(x+1<fila && y+1<columna && matriz[x+1][y+1]=='@'){matriz[x+1][y+1]='*';confirmar(x+1,y+1);}
     
     
}


int main(){
    scanf("%d %d", &fila,&columna);
    while(fila!=0){
          
          int resp=0;                      
          for(int i=0;i<fila;i++){
             for(int j=0;j<columna;j++){  
                cin>>matriz[i][j];         
                }        
             }
          
          for(int i=0;i<fila;i++){
             for(int j=0;j<columna;j++){  
                if(matriz[i][j]=='@'){
                      matriz[i][j]=='*';
                      resp++;                      
                      confirmar(i,j);         
                }        
             }
          }  
          printf("%d\n",resp);
          scanf("%d %d", &fila,&columna);  
    }
 return 0;   
}
