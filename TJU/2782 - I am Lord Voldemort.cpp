/*
  2782.   I am Lord Voldemort 
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/
#include<iostream>
#include<string>


using namespace std;

int main(int argc, char *argv[]){
    int cases;
    int caso=1;
    
    scanf("%d",&cases);
    
    while(cases--){
           string word1;
           string word2;
           int sum1=0;
           int sum2=0;
           char c;
                     
           cin>>word1 >>word2;
           
           if(word1.size()!=word2.size()){
                  cout<<"No"<<endl;                     
           }else{
                  for(int i =0; i<word1.size();i++){
                          c=word1[i];
                          c=tolower(c);
                          sum1+=c;
                          
                          c=word2[i];
                          c=tolower(c);
                          sum2+=c;    
                  }
                  if(sum1==sum2)
                      cout<<"Yes"<<endl;
                  else
                      cout<<"No"<<endl;           
           }
       
    }
    return 0; 
}
