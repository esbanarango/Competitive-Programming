/*
  3006 - Encoding 
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/
#include <iostream>

using namespace std;

string toBinary (int num){
     string numB="00000"; 
     int cont=4;  
     while (num != 0){
             numB[cont]=(num % 2) + '0';
             num = num /2;
             cont--;
     } 
     return numB;
}


int main(){
    int n,cont=1;
    string line;
    scanf("%d",&n);
    getline(cin,line);
    while(n--){
               int r=0,c=0;
               string word="";
               getline(cin,line);
               int k=0;
               //Aqui se saca la información
               while(isdigit(line[k])){
                   r= (10 * r) + (line[k]-'0');
                   k++;         
               }
               k++;
               while(isdigit(line[k])){
                   c= (10 * c) + (line[k]-'0');
                   k++;         
               }
               k++;
               for(int i=k;i<line.size();i++){
                       word+=line[i];
               }
               
               int tam = word.size();
               string binaryNums="";
               
               for(int i=0;i<tam;i++){
                     if(word[i] == ' '){  
                           binaryNums +=toBinary(0);
                     }else{
                           binaryNums +=toBinary(word[i]-'A'+1);
                     }
               } 
               while (binaryNums.size()<r*c){binaryNums+='0';}

               int tam2 = binaryNums.size();

               char matrix[r+1][c+1];
               memset(matrix,'x',sizeof(matrix));
               int i,j,sup=0,inf=r+1,izq=0,der=c+1,rec=0;
               //Recorrido matriz en espipral. UN POCO ADVERSO EL RECORRIDO, PERO ME TOCÓ
               //HACERLE BASTANTES CAMBIOS PARA PORDER QUE LLENARA BIEN LA MATRIZ.
               while(sup+1<inf || izq+1<der){
                             i=sup+1;
                             j=izq+1;
                             while(j<der-1){ 
                                  if(matrix[i][j]=='x'){
                                         matrix[i][j]=binaryNums[rec];
                                         rec++;
                                  }
                                   j++;     
                                         
                             } 
                             while(i<inf-1){
                                    if(matrix[i][j]=='x'){
                                         matrix[i][j]=binaryNums[rec];
                                         rec++;
                                    }
                                    i++;
                                                 
                             } 
                             while(j>izq+1){
                                    if(matrix[i][j]=='x'){
                                         matrix[i][j]=binaryNums[rec];
                                         rec++;
                                   }
                                    j--; 
                                               
                             } 
                             while(i>sup+1){
                                    if(matrix[i][j]=='x'){
                                         matrix[i][j]=binaryNums[rec];
                                         rec++;
                                    }
                                    i--;
                                                 
                             }
                             izq++;
                             sup++;
                             der--;
                             inf--;              
                             
               }
               //En algunos casos no me recorre la matriz completamente entonces me tocó hacer este if.
               //No pude encontra la razon FUCK!!!!!
               if(rec<tam2){
                      matrix[i][j]=binaryNums[rec];      
               }
               cout<<cont<<" ";
               cont++;
               for(int i =1;i<r+1;i++){
                     for(int j=1;j<c+1;j++){
                             cout<<matrix[i][j];
                     }   
               }
               cout<<endl;
               
    }
 return 0;   
}
