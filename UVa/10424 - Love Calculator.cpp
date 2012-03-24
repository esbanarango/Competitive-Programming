/*
  10424 - Love Calculator
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string>
#include <vector>
#include <stdio.h>


using namespace std;

int main(){
   char  letras[26];
   string a,b;
   for (int i = 0; i<26;i++){
        letras[i] =(char)('A' + i);
   }
   while(getline(cin,a) && getline(cin,b)){
           int tamA = a.size();
           int tamB = b.size();
           int sumA=0,sumB=0;
           
           for(int i=0;i<tamA;i++){
                 a[i]=toupper(a[i]);
                 for(int j=0;j<26;j++){
                         if(a[i]==letras[j]){
                             sumA+=j+1;
                             break;               
                         }  
                 }
           }
           for(int i=0;i<tamB;i++){
                 b[i]=toupper(b[i]);
                 for(int j=0;j<26;j++){
                         if(b[i]==letras[j]){
                             sumB+=j+1;
                             break;                
                         }  
                 }
           }
           int tempA=0,tempB=0;
           //shit!!!!!!!!!!!!!!!!!!!
           while(sumA > 0){
                   tempA+=sumA%10;   
                   sumA  /= 10;
           }
           tempA+=sumA;
           while(sumB > 0){
                   tempB+=sumB%10;   
                   sumB  /= 10;
           }
           tempB+=sumB;
           
           sumA=tempA;
           sumB=tempB;

           while(sumA >= 10){
                     int temp = sumA; 
                     sumA = 0;
                     while(temp != 0){
                                sumA += temp % 10;
                                temp /= 10;
                     }
           }
           while(sumB >= 10){
                     int temp = sumB; 
                     sumB = 0;
                     while(temp != 0){
                                sumB += temp % 10;
                                temp /= 10;
                     }
           }
           if(sumA  < sumB )  swap(sumA , sumB);
           cout.precision(2); 
           cout<<fixed<< (double) sumB* 100.0 / sumA<<" %"<<endl;
           
   } 
    
 return 0;   
}
