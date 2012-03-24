/*
  3007 - Decoding 
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/
#include <iostream>

using namespace std;

int toInt (string bin){

  int  b, k, m, n;
  int  len, sum = 0;
  len = bin.size() - 1;
  for(k = 0; k <= len; k++){
    n = (bin[k] - '0');
    for(b = 1, m = len; m > k; m--) {b *= 2;}
    sum = sum + n * b;
  }
  return(sum);
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
               char matrix[r][c];
               int tam = word.size();
               //lleno la matriz de la forma normal
               for(int i =0,v=0;i<r;i++){
                     for(int j=0;j<c;j++){
                             matrix[i][j]=word[v];
                             v++;
                     }   
               }
               string binaryNums="";
               //Recorrido de la matriz en espiral
               int valor=0,fijo,toperD=c,inicio=0,toperA=r;
               while(valor<r*c){
                       toperA--;
                       toperD--;
                       fijo=inicio;
                       if(valor<r*c){
                           for(int i=inicio;i<=toperD;i++){
                                 binaryNums+=matrix[fijo][i];
                                 valor++;
                           }
                       }
                       fijo=toperD;
                       if(valor<r*c){
                           for(int i=inicio+1;i<=toperA;i++){
                                 binaryNums+=matrix[i][fijo];
                                 valor++;
                           }
                       }
                       fijo=toperA;
                       if(valor<r*c){
                           for(int i=toperD-1;i>=inicio;i--){
                                 binaryNums+=matrix[fijo][i]; 
                                 valor++;
                           }
                       }
                       fijo=inicio;
                       inicio++;
                       if(valor<r*c){
                           for(int i=toperA-1;i>=inicio;i--){
                                 binaryNums+=matrix[i][fijo];
                                 valor++;
                           }
                       }       
               }
               string resp="";
               for(;binaryNums.size()>=5;){
                     string temp= binaryNums.substr(0,5);
                     binaryNums.erase(0,5);
                     int num = toInt(temp);
                     if(num == 0){  
                           resp+=' ';
                     }else{
                           
                           resp +=num+'A'-1;
                     }
               }
               //The solution to the fucking presentantion error is here.!!!!!
               //La respuesta no puede tener espacios al final. :S
               while(resp[resp.size()-1]==' '){resp.erase(resp.size()-1,1);}
               cout<<cont<<" "<<resp.c_str()<<endl;
               cont++;

    }
 return 0;   
}
