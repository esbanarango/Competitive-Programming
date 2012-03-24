/*
  2637 - Red and Black 
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/
#include<iostream>

using namespace std;
       
int cont=0;
char matriz [20][20];
int fila=0;
int columna=0;

void confirmar(int x, int y){
     /*//Imprimir tablero
     for(int i=0;i<fila;i++){
             for(int j=0;j<columna;j++){  
                cout<<matriz[i][j];        
                } 
                cout<<endl;       
     }*/
     if(x+1<fila && matriz[x+1][y]=='.'){matriz[x+1][y]='x';cont++;confirmar(x+1,y);}
     if(x-1>=0 && matriz[x-1][y]=='.'){matriz[x-1][y]='x';cont++;confirmar(x-1,y);}
     if(y+1<columna && matriz[x][y+1]=='.'){matriz[x][y+1]='x';cont++;confirmar(x,y+1);}
     if(y-1>=0 && matriz[x][y-1]=='.'){matriz[x][y-1]='x';cont++;confirmar(x,y-1);}
}

int main(){
    scanf("%d %d", &columna,&fila);
    while(fila!=0){
                   
          cont=0;         
          int x;
          int y;
                   
          for(int i=0;i<fila;i++){
             for(int j=0;j<columna;j++){  
                cin>>matriz[i][j];
                if(matriz[i][j]=='@'){      
                             x=i,
                             y=j;         
                }        
             }
          }
          confirmar(x,y);
          printf("%d\n",cont+1);
          scanf("%d %d", &columna,&fila);  
    }
 return 0;   
}


