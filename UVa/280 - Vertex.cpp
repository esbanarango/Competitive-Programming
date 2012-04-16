/*
  280 - Vertex
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

void dfs(int start,vector<int> *visited, vector< vector<int> > *graph){
  for (int i = 0; i < graph->at(start).size(); ++i)
  {
    if(visited->at(graph->at(start)[i]) == 0){
      visited->at(graph->at(start)[i])=1;
      dfs(graph->at(start)[i],visited,graph);
    }
  }
}
bool counted (int i) { return i==0; }
int main(){

  int nodes;
  while(scanf("%d",&nodes) && nodes){
    vector< vector<int> > graph(nodes+1);
    int parent;
    while(scanf("%d",&parent) && parent){
      int node;
      while(scanf("%d",&node) && node){
        graph[parent].push_back(node);
      }
    }
    int q,qN;scanf("%d",&qN);
    while(qN--){
      scanf("%d",&q);
      
      vector<int> visited(nodes+1,0);
      dfs(q,&visited,&graph);
      int count =  ((int) count_if (visited.begin(), visited.end(), counted))-1;
      printf("%d",count);
      for (int i = 1,inCount=0; i <= nodes && inCount<count; ++i)
      {
        if(visited[i]==0){
          inCount++;
          printf(" %d",i);
        }
      }
      printf("\n");
    }

  }
  return 0;
}