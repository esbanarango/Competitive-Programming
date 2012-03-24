/*
  10189 - Minesweeper
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/
#include<iostream>

using namespace std;


int main(){
    int fila=0;
    int columna=0;
    
    int cont=0;
    int contCase=1;
    
    cin>>fila>>columna;
    while(fila!=0){
                   
          char matriz [fila][columna]; //se crea la matriz
          //Se ingresa el tablero
          for(int i=0;i<fila;i++){
             for(int j=0;j<columna;j++){
                cin>>matriz[i][j];        
             }
          }
          //se cuentan las minas adyacentes         
          for(int i=0;i<fila;i++){
               for(int j=0;j<columna;j++){
                      if(matriz[i][j] != '*'){
                        for(int k=0;k<3;k++){
                                for(int l=0;l<3;l++){ 
                                        if(((i+k-1)<fila) && ((j+l-1)<columna)){
                                                    if(((i+k-1)>-1) && ((j+l-1)>-1)){
                                                        if((matriz[i+k-1][j+l-1] == '*') && !((i+k-1)== i  && (j+l-1)==j)){
                                                            cont++;
                                                        }       
                                                    } 
                                        }
                                }
                        }
                        matriz[i][j]='0' + cont;              
                      }
                      cont=0;                        
               }
          }
          //se imprime la matriz
          cout<<"Field #"<<contCase<<":"<<endl;
          for(int i=0;i<fila;i++){
               for(int j=0;j<columna;j++){
                       cout<<matriz[i][j];
               }
               cout<<endl;
          }
          cin>>fila>>columna;
	      if(fila){
          	cout<<endl;
	       }      
          contCase++;         
    }

 return 0;   
}
