/*
  1527 - Euchre Results
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/

#include<iostream>

using namespace std;

struct player{
      int wins;
      int loses; 
       };
       
int main(){
    player betty;
    player cindy;
    player zelda;
    player anna;
    
    int totalGames=0;
    int totalWins=0;
    int totalLoses=0;
    
    
    while(cin>>betty.wins>>betty.loses>>cindy.wins>>cindy.loses>>zelda.wins>>zelda.loses){
                                                                                          
             if (!betty.wins && !betty.loses && !cindy.wins && !cindy.loses && !zelda.wins && !zelda.loses)
			    break;   
                
             
             totalWins=betty.wins+cindy.wins+zelda.wins;
             totalLoses=betty.loses+cindy.loses+zelda.loses;
             
             totalGames=(betty.wins+betty.loses)*4;
             
             anna.wins = (totalGames/2)-totalWins; 
             anna.loses = (totalGames/2)-totalLoses;
         
        cout<<"Anna's won-loss record is "<<anna.wins<<"-"<<anna.loses<<"."<<endl;             
    }

 return 0;   
}
