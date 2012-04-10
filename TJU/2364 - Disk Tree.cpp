/*
  2364 - Disk Tree
  TJU Online Judge
  Esteban Arango Medina
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;




//Beautifull DFS!! :)
void dfs(int priEsp,string spaces, string conToda, map<string,set<string> > vamos){
  set<string>::iterator setit;
  string print = conToda;
  if(priEsp++==1)
    cout<<spaces<<print.erase(print.length() -1);
  else
    cout<<endl<<spaces<<print.erase(print.length() -1);
  if(vamos.count(conToda)>0){
    spaces+=" ";
    for (setit=vamos[conToda].begin(); setit!=vamos[conToda].end(); ++setit)
     {
       dfs(priEsp,spaces,*setit,vamos);
     }
  }
}

int main(){
  //freopen("entrada.out", "w", stdout);
  int n;scanf("%d",&n);
  map<string,map<string,set<string> > > paths;
    size_t pos1;
  while(n--){
    string s;
    cin>>s;
    pos1 = s.find("\\");
    char prof = '1';
    if(pos1!=string::npos){
      string parent = s.substr(0,pos1);
      parent +=prof;
      stringstream ss(s.substr(pos1+1));
      string tmp;
      string pp = parent;
      while (getline(ss, tmp, '\\')) {
        prof++;
        paths[parent][pp].insert(tmp+prof);
        pp=tmp+prof;
      }
    }else{
      paths[s+prof];
    }
  }
  
  /*Imprimirlo*/
   /*map<string,map<string,set<string> > >::const_iterator itr;
   map<string,set<string> >::const_iterator itin;
   set<string>::iterator setit;
     for(itr = paths.begin(); itr != paths.end(); ++itr){ //Imprimir grafo
        cout<<endl<<(*itr).first<<" -> "<<endl;
        for (itin = (*itr).second.begin(); itin!=(*itr).second.end(); ++itin)
         {
             cout<<"papa: "<<(*itin).first<<" ";
             for (setit=(*itin).second.begin(); setit!=(*itin).second.end(); setit++)
             {
               cout<<*setit<<" ";
             }
             
         }
      }
      cout<<endl;
      cout<<"  ----  "<<endl;
      */
      
  map<string,map<string,set<string> > >::const_iterator itr;
  map<string,set<string> >::const_iterator itin;
  int priEsp =1;
  for(itr = paths.begin(); itr != paths.end(); ++itr,priEsp++){
    string pp =(*itr).first;
    string spaces ="";
    dfs(priEsp,spaces,pp,(*itr).second);
  }
    return 0;
}