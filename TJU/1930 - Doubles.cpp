/*
  1930 - Doubles
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<iostream>
#include<vector>
#include <algorithm>


using namespace std;

int main(){
    int num;
    cin>>num;
    
    while(num!=-1){
            int cont =0;
            vector <int> doubles;
            doubles.push_back(num);
            cin>>num;
            
            while(num){
                 doubles.push_back(num);
                 cin>>num;      
            }   
                  
            int tamV=doubles.size();
            
            for(int i=0;i<tamV;i++){
                    if(!(doubles[i]&1)){
                            int  mid= doubles[i]/2;
                            int it;
                            it = (int) count (doubles.begin(), doubles.end(), mid);
                            if(it>0)cont++;
                    }  
            }
            cout<<cont<<endl;
            cin>>num; 
    }

 return 0;   
}
