#include<iostream>
#include<queue>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


using namespace std;

struct Tparent{
       int i,j;
       Tparent(int i, int j) : i(i), j(j) {}
       Tparent(){};
       bool operator == (const  Tparent &uni){
            return(i==uni.i && j==uni.j);
       }
       
};

struct Tpuerta{
       int i,j;
       double prob;
       Tpuerta(int i, int j, double prob) : i(i), j(j), prob(prob) {}
       Tpuerta(int i, int j) : i(i), j(j), prob(0) {}
       Tpuerta(){};
       bool operator == (const  Tpuerta &uni){
            return(i==uni.i && j==uni.j);
       }
       
};

char grid[20][20];
bool visited[20][20];
Tparent parent[20][20];
Tpuerta puertas[10];
int arr[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1,};
int n;
int steps=0;



void bfs(int start_i, int start_j){
     queue <Tparent> q;
     q.push(Tparent(start_i,start_j));
     visited[start_i][start_j] = true;
     
     while(!q.empty()){
          Tparent v = q.front();
          q.pop();
          for(int k=0; k < 4; k++){
                  int ti = v.i + arr[k][0];
                  int tj = v.j + arr[k][1];
                  
                  if(ti>=0 && ti<n && tj>=0 && tj<n){
                          if(!visited[ti][tj]){
                               visited[ti][tj] = true;
                               if(grid[ti][tj]=='.'){
                                    q.push(Tparent(ti,tj));
                                    parent[ti][tj]= Tparent(v); 
                                    //cout<<v.i<<" "<<v.j<<" is parent of "<< ti << " "<<tj<<endl; 
                               }else if(isdigit(grid[ti][tj])){
                                     parent[ti][tj]= Tparent(v);
                               }
                                           
                          } 
                  }
          }    
     }
     
}

void shortest_path(Tparent start, Tparent end){
    if(start == end || end == Tparent(-1,-1)){          
    }else{
          steps++; 
       shortest_path(start, parent[end.i][end.j]); 
        
    }
    
}

int main(){
    int cases;
    int nPuerta;
    int bomberX;
    int bomberY;
    
    cin>>cases;
    while(cases--){
            cin>>n;
            for(int i=0;i<n;i++){
                  for(int j=0;j<n;j++){
                          char c;
                          cin>>c;
                        if(c=='B'){
                              bomberX=i;
                              bomberY=j;     
                        }else if(isdigit(c)){
                              int puert= c - '0';
                              //cout<<puert<<" ";
                              puertas[puert]=Tpuerta(i,j);           
                        }
                        grid[i][j] = c;
                        visited[i][j]=false;
                        parent[i][j]=Tparent(-1,-1);
                  }
            }
            bfs(bomberX,bomberY);
             
            cin>>nPuerta;
            for(int i=0;i<nPuerta;i++){
                  cin>>puertas[i].prob;
            }
            double sum=0;
            for(int i=0; i<nPuerta;i++){
                  steps=0;
                  shortest_path(Tparent (bomberX,bomberY), Tparent (puertas[i].i,puertas[i].j));
                  sum+=(double)(steps * (puertas[i].prob * 0.01));
            }
            cout.precision(2);
            cout<<fixed<<sum<<endl;
            
    }
    
    
    
    
    return 0;
}
