/*
  206 - Bitmap
  Sphere Online Judge
  Esteban Arango Medina

	Solution.
		BFS, but you have to do it once, otherwise if you try doing BFS for each position it'll be TLE (I know :P)
		so basically put into the queue each white (1) pixel and and set it's distance equals to 0, and the distance 
		for the black pixels equals to something BIG, then just do the normal BFS. :)

	Notes.
		http://apps.topcoder.com/forums/;jsessionid=61B18C2F90D8E14B038F8F3F7412A163?module=Thread&threadID=680765&start=0&mc=5#1262594
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

//Posibles moves
int positionsX[4]= {0,-1,0,1};
int positionsY[4]= {-1,0,1,0};
int n,m;
queue< pair <int,int> > s;

bool validPosition(int a, int b){
    return ((a<n && a>=0) && (b<m && b>=0))?true:false;
}

int bfs(vector< vector<int> > *visited, vector< vector<int> > *graph) {
    while (s.empty() == false) {
        pair <int,int> top = s.front();
        s.pop();
        for(int i=0;i<4;i++){
            int newx=top.first+positionsX[i],newy=top.second+positionsY[i];
            if(validPosition(newx,newy)){
                if(visited->at(top.first)[top.second]+1 < visited->at(newx)[newy]){
                    visited->at(newx)[newy] = visited->at(top.first)[top.second]+1;
                    pair <int,int> node (newx,newy);
                    s.push(node);
                }
            }
        }
     }
}
int main(){
	int cases;scanf("%d",&cases);
    while(cases--){
    	scanf("%d %d",&n,&m);
    	vector< vector<int> > graph;
    	vector<int> ceros(m,0);
    	vector< vector<int> > visited(n,ceros); 
        //Read the graph
        string line;
        for (int i = 0; i < n; ++i)
        {	
        	vector<int> temp;
        	cin>>line;
        	for (int j = 0; j < m; ++j)
        	{	
        		visited[i][j]= 1<<30;
        		int borw = line[j]-'0';
        		if(borw==1){
        			pair <int,int> start (i,j);
    				s.push(start);
    				visited[i][j]= 0;
    			}
        		temp.push_back(borw);
        	}
        	graph.push_back(temp);
        }
        
        bfs(&visited,&graph);
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < m; ++j)
        	{
        		if(graph[i][j]==0){
        			int result =visited[i][j];
        			(j+1<m)?printf("%d ",result):printf("%d",result);
        		}else{
        			(j+1<m)?printf("0 "):printf("0");
        		}
        	}
        	printf("\n");
        }
    }
 return 0;   

}