/*
  627 - The Net
  UVa Online Judge
  Esteban Arango Medina

  Solution.
    BFS, printing the Single-Source Shortest Paths (SSSP). "To reconstruct the actual shortest path we can do a simple
    recursive backtracking from the last vertex until we hit the source vertex"(Competitive Programming 2).
    The reading it isn't classic cause you have to deal with strings. I used stringstream to split it.

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

map <int,int> visited;
map<int,int> route;

int bfs(int a, int b, map<int,vector<int> > graph){
  queue<int>s;
  s.push(a);
  visited[a]=1;
  while(s.empty()==false){
    int top = s.front();
    s.pop();
    if(top == b)
      return visited[top];
    int size = graph[top].size();
    for(int i=0;i<size;i++){
        int n =graph[top][i];  
        if(!visited.count(n)){         //I've been here before?.
            visited[n]=visited[top]+1; //Number of moves until here + 1, not necesary in this problem :P
            route[n]=top;              //Addtion: The parent of n is top.
            s.push(n);
        }
    }
  }
  return -1;
}

//From Competitive Programming 2 :)
void printpath(int a, int b){
  if(a==b){printf("%d",b);return;}
  printpath(route[a],b);
  printf(" %d",a);
}

vector<int> getNodes(string s){
  vector<int> r;
  stringstream ss(s);
  string tmp;
  while (getline(ss, tmp, ',')) {
    r.push_back(atoi(tmp.c_str()));
  }
  return r;
}

int main(){
  int n,m,a,b;size_t pos1;
  while(scanf("%d",&n) != EOF){
    
    map<int,vector<int> > graph;
    string s;
    for (int i = 0; i < n; ++i)
     {
        cin>>s;
        pos1 = s.find("-");
        graph[atoi(s.substr(0,pos1).c_str())] = getNodes(s.substr(pos1+1));

     } 
     printf("-----\n");
     scanf("%d",&m);
     for (int i = 0; i < m; ++i)
     {
        visited.clear();route.clear();
        scanf("%d %d",&a,&b);
        if(bfs(a,b,graph)!=-1)
          printpath(b,a);
        else
          printf("connection impossible");
        printf("\n");
     }
     /*
     cout<<"Pillate el grafo:"<<endl;
     map<int,vector<int> >::const_iterator itr;
     for(itr = graph.begin(); itr != graph.end(); ++itr){ //Imprimir grafo
        cout<<endl<<(*itr).first<<" -> ";
        for (int j = 0; j <(*itr).second.size(); ++j)
         {
             cout<<(*itr).second[j]<<" ";
         }
      }
      */
  }
  return 0;
}