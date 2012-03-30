/*
  336 - A Node Too Far
  UVa Online Judge
  Esteban Arango Medina

    Solution.
        This is a 'simple' BFS or 'DFS' problem, at the beginning I approached it by using DFS but I got TLE
        so I change it to BFS and result easier. First, for the read I had to use a map, cuz' the nodes could
        be greater than the total number of nodes. (Ej. 3 nodes = 20233,892832,3289), then I used another map
        to count the number of moves from the query node to every other node in the graph and finally I count
        the number of nodes where the moves are less than the 'ttl'. BUT, There could be no-connected nodes
        so you have to verify that you're counting all the nodes.

    Notes.
        http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=graphsDataStrucs2

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

void bfs(int start, map <int,vector<int> > graph) {
    queue<int> s;
    s.push(start);
    visited[start]=0;
    while (s.empty() == false) {
        int top = s.front();
        s.pop();
        int size = graph[top].size();
        for(int i=0;i<size;i++){
            int n =graph[top][i];  
            if(!visited.count(n)){ //I've already been here.
                visited[n]=visited[top]+1; //Number of moves until here + 1
                s.push(n);
            }
        }
     }
}
/* DFS = Time limit exceeded
void dfs(int start, int newStart, int ttl, map <int,vector<int> > graph){ 
       if(ttl!=0){
            if(start != newStart){
                ttl--;
            }
           if(find(visited.begin(), visited.end(), newStart)==visited.end()){
                    visited.push_back(newStart);
                    //cout<<"Metio: "<<newStart<<" y el tamanio final: "<<visited.size()<<endl;
                   int size =graph[newStart].size();
                    for(int i=0;i<size;i++){
                        dfs(start,graph[newStart][i],ttl,graph);
                    }
                }
            
        }
}*/
int main(){
    int nods,a,b,cases=1;
    while(scanf("%d",&nods) && nods){
             map <int,vector<int> > graph;  
             for(int i=0;i<nods;i++){
                     scanf("%d %d",&a,&b);
                     graph[a].push_back(b);
                     graph[b].push_back(a);
             }
             //map<int,vector<int> >::const_iterator itr;
             /*for(itr = graph.begin(); itr != graph.end(); ++itr){ //Imprimir grafo
                cout<<endl<<(*itr).first<<" -> ";
                for (int j = 0; j <(*itr).second.size(); ++j)
                 {
                     cout<<(*itr).second[j]<<" ";
                 }
            }*/
             int ttl,start;
             while(scanf("%d %d",&start,&ttl) && (start!=0 || ttl!=0)){
                map <int,int>::const_iterator itr;
                visited.clear();
                bfs(start,graph);
                int result = 0;
                 for(itr = visited.begin(); itr != visited.end(); ++itr){
                    if((*itr).second>ttl)++result;
                 }
                 result += graph.size()-visited.size(); //Aaaaaah!!! The graph could has no connected nodes
                printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cases,result,start,ttl); 
                cases++;  
             }
                          
    }
 return 0;   

}