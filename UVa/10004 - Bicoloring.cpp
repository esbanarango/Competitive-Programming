/*
  10004 - Bicoloring
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
bool resp;

void dfs(int start, int color, int * colors, vector<int> * graph){ 
     if(colors[start] != 0){ 
           if(!(color == colors[start])){resp=false;}
     }else{
           colors[start]=color;             
           for(int i=0;i<graph[start].size();i++){
                 int color2 = (color == 1) ? 2 : 1;
                 dfs(graph[start][i],color2,colors,graph);
           }
     }
}



int main(){
    int nods,edges,a,b;
    while(scanf("%d",&nods) && nods){
             scanf("%d",&edges);
             vector <int> graph[nods];
             int colors[nods];
             memset(colors,0,sizeof colors);
             for(int i=0;i<edges;i++){
                     scanf("%d%d",&a,&b);
                     graph[a].push_back(b);
                     graph[b].push_back(a);
             }
             resp=true;
             dfs(0,1,colors,graph);
             if(resp){printf("BICOLORABLE.\n");} 
             else {printf("NOT BICOLORABLE.\n");}                       
    }

 return 0;   
}
