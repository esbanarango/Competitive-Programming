/*
  10361 - Automatic Poetry
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/
#include<iostream>
#include<string>

using namespace std;

int main(){
    string line1,line2;
    bool primero=true;
    int cases;
    scanf("%d",&cases);
    getline(cin,line1);
    while(cases--){
            string s2="",s3="",s4="",s5="";       
            getline(cin,line1);
            getline(cin,line2);
            int tam=line1.size();
            for(int i=0;i<tam;i++){
                  if(line1[i]!='<' && line1[i]!='>'){
                           cout<<line1[i];        
                  }
            }
            cout<<endl;
            for(int i=0;i<tam;i++){
                  if(line1[i]=='<' && primero){
                           for(int j=i+1;line1[j]!='>';j++){
                                 s2+=line1[j];
                                 i+=j-i;
                           }
                           for(int j=i+2;line1[j]!='<';j++){
                                 s3+=line1[j];
                                 i+=j-i;
                           }
                           primero=false;       
                  }else if(line1[i]=='<' && !primero){
                           for(int j=i+1;line1[j]!='>';j++){
                                 s4+=line1[j];
                                 i+=j-i;
                           }
                           for(int j=i+2;j<tam;j++){
                                 s5+=line1[j];
                           }
                  }
            }
            line2.erase(line2.size()-3,3); 
            cout<<line2;
            cout<<s4<<s3<<s2<<s5;        

            cout<<endl;
            primero=true;
    }
 return 0;   
}
