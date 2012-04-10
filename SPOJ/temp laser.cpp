/*
  3861 - Laser Phones
  Sphere Online Judge
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

//Posibles moves
int positionsX[4]= {0,-1,0,1};
int positionsY[4]= {-1,0,1,0};
char orientation[4] ={'o','n','e','s'};
int h,w;
vector<vector<char> > pasture;
int visited [105][105];
char d[105][105];

bool validPosition(int a, int b){
    if((a<h && a>=0) && (b<w && b>=0))
        return (pasture[a][b]!='*')?true:false;
    else
        return false; 
}

void printM(){
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cout<<visited[i][j]<<d[i][j]<<" ";
        }
        cout<<endl;
    }
}
int bfs(pair <int,int> start, pair <int,int> end) {
    queue< pair <int,int> > s;
    s.push(start);
    visited[start.first][start.second]=0;
    d[start.first][start.second]='q';
    while (s.empty() == false) {
        pair <int,int> top = s.front();
        s.pop();
        //if(top.second.first == end.first && top.second.second == end.second)
        for(int i=0;i<4;i++){
            int newx=top.first+positionsX[i],newy=top.second+positionsY[i];
            char newp=orientation[i];
            if(validPosition(newx,newy)){  
                if(visited[newx][newy] == -1){
                    if(newp != d[top.first][top.second] && d[top.first][top.second] != 'q'){
                        visited[newx][newy] = visited[top.first][top.second]+1;
                    }else{
                        visited[newx][newy] = visited[top.first][top.second];
                    }
                    d[newx][newy] = newp;
                    pair <int,int> pos(newx,newy);
                    s.push(pos);
                }else{
                    //If there is a short route.
                    if(newp != d[newx][newy] && visited[newx][newy]>visited[top.first][top.second]){
                            visited[newx][newy] = visited[top.first][top.second]+1;
                            pair <int,int> pos(newx,newy);
                            s.push(pos);    
                            d[newx][newy] = newp;
                    }else if(newp != d[newx][newy] && newp == d[top.first][top.second]){
                            d[newx][newy]=newp;
                            visited[newx][newy] = min(visited[newx][newy],visited[top.first][top.second]);

                    }else if(newp == d[newx][newy]){
                        visited[newx][newy] = min(visited[newx][newy],visited[top.first][top.second]);
                    }
                }
            }
        }
       /* cout<<"papa: "<<top.first<<"-"<<top.second<<" "<<d[top.first][top.second]<<endl;
        printM();
        cout<<endl;*/
     }
     /*int minima =1<<30;
     for(int i=0;i<4;i++){
        int newx=end.first+positionsX[i],newy=end.second+positionsY[i];
        if(validPosition(newx,newy)){
            minima = min(minima,visited[newx][newy]);
        }
     }
     
     return minima;*/
     return visited[end.first][end.second];
}
int main(){
    scanf("%d %d",&w,&h);
    memset (visited,-1,sizeof(visited));
    vector<pair <int,int> > positions;
    char temp;
    for(int i=0;i<h;++i){
        vector<char> tempV;
        for (int j = 0; j < w; ++j)
        {
            char tempC;
            cin>>tempC;
            tempV.push_back(tempC);
            if(tempC == 'C'){
                pair <int,int> newP(i,j);
                positions.push_back(newP);
            }

        }
        pasture.push_back(tempV);
    }

    cout<<bfs(positions[0],positions[1]);
    return 0;   

}