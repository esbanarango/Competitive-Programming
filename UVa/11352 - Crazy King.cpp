/*
  11352 - Crazy King
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
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,int> si;
typedef pair<int,ii> iii;
typedef vector <si> vsi;
typedef vector <ii> vii;
typedef vector <int> vi;
typedef vector <char> vc;
#define INF 1000000000

int posX[8]={-1,-1,0,1,1,1,0,-1};
int posY[8]={0,1,1,1,0,-1,-1,-1};
int posHx[8]= {-2,-1,1,2,2,1,-1,-2};
int posHy[8]= {1,2,2,1,-1,-2,-2,-1};
int M,N;

bool validMove(int x, int y){
    return ((x>=0 && x<M) && (y>=0&&y<N));
}

int bfs(ii a, ii b, vector<vi> *visited, vector<vc> *graph){
    queue<ii> q;
    visited->at(a.first)[a.second]=0;
    q.push(a);
    while(!q.empty()){
        ii top = q.front();q.pop();
        if(top.first == b.first && top.second == b.second)
            return visited->at(b.first)[b.second];
        for (int i = 0; i < 8; ++i)
        {   int nx=top.first+posX[i],ny=top.second+posY[i];
            if(validMove(nx,ny) && (graph->at(nx)[ny]=='.' || graph->at(nx)[ny]=='B')&& visited->at(nx)[ny]==-1){
                visited->at(nx)[ny]=visited->at(top.first)[top.second]+1;
                ii newNode (nx,ny);
                q.push(newNode);
            }
            
        }
        
    }
    return -1;
}

int main(){
    int n;scanf("%d",&n);
    while(n--){
        scanf("%d %d",&M,&N);
        vc rowIni(N,'.');
        vector<vc> graph(M,rowIni);
        char c;
        ii a,b;
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cin>>c;
                if(c=='Z'){
                    graph[i][j]='Z';
                    for(int k=0;k<8;k++){
                        int nx=i+posHx[k],ny=j+posHy[k];                        
                        if(validMove(nx,ny) && graph[nx][ny]=='.')
                            graph[nx][ny]='Z';
                    }
                }else if(c=='A'){
                    graph[i][j]='A';
                    a.first=i;a.second=j;
                }else if(c=='B'){
                    graph[i][j]='B';
                    b.first=i;b.second=j;
                }
            }
        }
        vi rowVIni(N,-1);
        vector<vi> visited(M,rowVIni);
        int resp = bfs(a,b,&visited,&graph);
        (resp!=-1)?printf("Minimal possible length of a trip is %d\n",resp):printf("King Peter, you can't go now!\n");
        

    } 
 return 0;   

}