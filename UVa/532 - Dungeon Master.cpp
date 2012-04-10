/*
  532 - Dungeon Master
  UVa Online Judge
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

int positionsX[6]= {0,0,0,-1,0,1};
int positionsY[6]= {0,0,-1,0,1,0};
int positionsL[6]= {1,-1,0,0,0,0};

typedef struct edge{
  int l,r,c;
}edge;

int L,R,C;
int visited[30][30][30];

bool validPosition(int l, int r, int c, vector<vector<vector<char> > > *graph){
    if((l<L && l>=0) && (r<R && r>=0) && (c<C && c>=0))
        return (graph->at(l)[r][c]=='.'||graph->at(l)[r][c]=='E')?true:false;
    else
        return false; 
}

int bfs(edge start, edge end, vector<vector<vector<char> > > *graph){
    queue<edge> s;
    s.push(start);
    visited[start.l][start.r][start.c]=0;
    while (s.empty() == false) {
      edge top = s.front();
      s.pop();
      if(end.l==top.l && end.r==top.r && end.c==top.c)
        return visited[top.l][top.r][top.c];
      for (int i = 0; i < 6; ++i){
        int newl=top.l+positionsL[i],newr=top.r+positionsX[i],newc=top.c+positionsY[i];
        if(validPosition(newl,newr,newc,graph)){
          if(visited[newl][newr][newc]==-1){
            visited[newl][newr][newc]=visited[top.l][top.r][top.c]+1;
            edge node = {newl,newr,newc};
            s.push(node);
          }
        }
      }
    }
    return -1;
}

int main(){
  char po;
  edge start,end;
  while(scanf("%d %d %d",&L,&R,&C) && L && R && C){
    //Reading the Graph :)
      memset (visited,-1,sizeof(visited));
      vector<vector<vector<char> > > graph;
      for (int i = 0; i < L; ++i)
      { 
        vector< vector<char> > level;
        for (int j = 0; j < R; ++j)
        {
          vector<char> row;
          for (int k = 0; k < C; ++k)
          {
            cin>>po;
            if(po=='S'){start.l=i;start.r=j;start.c=k;}
            else if(po=='E'){end.l=i;end.r=j;end.c=k;}
            row.push_back(po);
          }
          level.push_back(row);
        }
        graph.push_back(level);
      }
      int result = bfs(start,end,&graph);
      (result == -1)?printf("Trapped!\n"):printf("Escaped in %d minute(s).\n",result);
  }
  return 0;
}