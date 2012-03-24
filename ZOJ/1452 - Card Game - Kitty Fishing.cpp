/*
  1452 - Card Game - Kitty Fishing
  ZOJ Problem Set
  Esteban Arango Medina
  marranoparael31@gmail.com

*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int esta(vector <int> table, int card){
    
    int noEsta=-1;
    
    for(int i=0;i<table.size();i++){
            if(table[i]==card)
               return i;     
    }
    return noEsta;      
}


int main(){
    int turns;
    int caso=1;
    
    cin>>turns;
    
    while(turns != 0){
                
         queue <int> A;
         queue <int> B;
         vector <int> table;
         int card;
         int posicion;
         
         //Reading the decks  
         cin >> card;       
         do {
            A.push(card);
            cin >> card;
         } while (card != 0);
         
         cin >> card;       
         do {
            B.push(card);
            cin >> card;
         } while (card);
         
         while(!A.empty() && !B.empty() && turns){
              
              posicion=esta(table, A.front());
              table.push_back(A.front());
              A.pop();          
              if(posicion!=-1){
                   for(int i=table.size()-1; i>=posicion;i--){            
                               A.push(table[i]);
                               table.pop_back();               
                  }
              }
              turns--;
              if(!A.empty() && turns){
                     posicion=esta(table, B.front());          
                     table.push_back(B.front());
                     B.pop();          
                     if(posicion!=-1){
                           for(int i=table.size()-1; i>=posicion;i--){            
                                    B.push(table[i]);
                                    table.pop_back();               
                           }
                     }
                     turns--;  
              }                         
         }
         
         //OUTPUT
         
         cout<<"Case "<<caso<<":"<<endl;
         
         if(A.empty()){cout<<"B";}
         else if(B.empty()){cout<<"A";}
         else{
              if(!A.empty()){
                cout<<A.front();
                A.pop();           
                while(!A.empty()){
                   cout<<" "<<A.front();
                   A.pop();            
                }
              }
              cout<<endl;
              if(!B.empty()){
                cout<<B.front();
                B.pop();
                while(!B.empty()){
                   cout<<" "<<B.front();
                   B.pop();            
                }
              }
              cout<<endl;
              if(table.size()>0){
                   cout<<table[0];              
                   for(int i=1; i<table.size();i++){
                           cout<<" "<<table[i];
                 }              
              }else{cout<<"NULL";}  
         }
         cout<<endl;
         cin>>turns; 
         caso++;           
    }
  
 return 0;   
}
