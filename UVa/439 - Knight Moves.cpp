/*
  439 - Knight Moves
  UVa Online Judge
  Esteban Arango Medina

    Solution.
        "The graph here is harder to see. Each location on the chessboard represents a vertex. There is an edge 
        between two positions if it is a legal knight move. Graph Problem: Single Source Shortest Path." 
        (Art of programming contest)
        There is no need to construct the graph at all, just BFS, check the valid moves for the knight and return 
        the sum of visited at the position asked.
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

//Posibles moves for the Knight
int recorrerA[8]= {-2,-1,1,2,2,1,-1,-2};
int recorrerB[8]= {1,2,2,1,-1,-2,-2,-1};

int visited[9][9]={0};

bool validPosition(int a, int b){
    return ((a<9 && a>0) && (b<9 && b>0))?true:false;
}

int bfs(int a1,int a2, int b1, int b2) {
    queue<pair <int,int> > s;
    pair <int,int> start (a1,a2);
    s.push(start);
    visited[a1][a2]=1;
    while (s.empty() == false) {
        pair <int,int> top = s.front();
        s.pop();
        if(top.first == b1 && top.second == b2)
            return visited[b1][b2]; //I found it
        for(int i=0;i<8;i++){
            int newA=top.first+recorrerA[i],newB=top.second+recorrerB[i];
            if(validPosition(newA,newB)){
                if(visited[newA][newB] == 0){
                    visited[newA][newB] = visited[top.first][top.second]+1;
                    pair <int,int> node (newA,newB);
                    s.push(node);
                }
            }
        }
     }
}

int main(){
    string node1,node2;
    string m = "abcdefgh";
    while(cin>>node1>>node2){
        int a1,a2,b1,b2;
        memset (visited,0,sizeof visited);
        //Get the positions
        a2 = m.find(node1[0])+1;   
        b2 = m.find(node2[0])+1;
        a1=atoi(&node1[1]);
        b1=atoi(&node2[1]);
        int resp = bfs(a1,a2,b1,b2)-1;
        resp = (resp == -1)?0:resp;
        cout<<"To get from "<<node1<<" to "<<node2<<" takes "<<resp<<" knight moves."<<endl;
    }
 return 0;   

}