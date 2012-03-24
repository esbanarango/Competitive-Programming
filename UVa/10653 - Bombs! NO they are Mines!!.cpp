/*
  10653 - Bombs! NO they are Mines!!
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<iostream>
#include <queue>

using namespace std;

struct Tparent{
       int i,j;
       Tparent(int i, int j) : i(i), j(j) {}
       Tparent(){};
       bool operator == (const  Tparent &uni){
            return(i==uni.i && j==uni.j);
       }
       
};

bool visited[1000][1000];
Tparent parent[1000][1000];
int arr[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1,};
int steps=0;
int row,column;

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
                  
                  if(ti>=0 && ti<row && tj>=0 && tj<column){
                          if(!visited[ti][tj]){
                               visited[ti][tj] = true;
                               q.push(Tparent(ti,tj));
                               parent[ti][tj]= Tparent(v); 
                                    //cout<<v.i<<" "<<v.j<<" is parent of "<< ti << " "<<tj<<endl;                 
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
    int R,r,numBoms,bomb,starI,starJ,endI,endJ;
    
    while(scanf("%d%d",&row,&column) && row){
             memset(visited, 0, sizeof(visited));
             scanf("%d",&R);
             for(int i=0;i<R;i++){
                    scanf("%d%d",&r,&numBoms);
                    for(int j=0;j<numBoms;j++){
                            scanf("%d",&bomb);
                            visited[r][bomb]=true;
                            parent[r][bomb]=Tparent(-1,-1);
                    }

             } 
             scanf("%d%d",&starI,&starJ);
             scanf("%d%d",&endI,&endJ);  
             bfs(starI,starJ);
             shortest_path(Tparent (starI,starJ), Tparent (endI,endJ));
             printf("%d\n",steps);
             steps=0;                     
     
    }
 return 0;   
}
