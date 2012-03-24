/*
  11541 - Decoding
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<iostream>
using namespace std;

int main(){
    int n,cases=1;
    string line;
    scanf("%d",&n);
    getline(cin,line);
    while(n--){
          getline(cin,line);
          cout<<"Case "<<cases<<": ";
          cases++;
          int tam=line.size();
          for(int i=0;i<tam;){
                char let;
                let=line[i];
                i++;
                int num=0;
                while(isdigit(line[i])){
                        num= (10 * num) + (line[i]-'0');
                        i++;         
                }
                for(int j=0;j<num;j++){
                      cout<<let;
                }   
          }
          cout<<endl;
            
    }
  
 return 0;   
}
