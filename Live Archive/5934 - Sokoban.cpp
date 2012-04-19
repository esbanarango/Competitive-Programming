/*
  5934 - Sokoban
  ACM-ICPC Live Archive
  Esteban Arango Medina

  Solution.
    Simulation.
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

int posX[4] = {-1,0,1,0};
int posY[4] = {0,1,0,-1};

int r,c;
bool validPos(int x, int y, vector< vector<char> > mapa){
  return (mapa[x][y]!='#');
}

bool validPosBloq(int x, int y, vector< vector<char> > mapa){
  return (mapa[x][y]!='#' && mapa[x][y]!='b' && mapa[x][y]!='B');
}

int main(){

  //freopen("sokoban.in", "r", stdin);
  //freopen("sokoban.out", "w", stdout);

  map<char, int> direc;
  direc['U']=0;direc['R']=1;
  direc['D']=2;direc['L']=3;
  int cases = 1;
  while(scanf("%d %d",&r,&c) && r && c){
    string instructions;
    vector< vector<char> > mapa;
    int xw=0,yw=0;
    int t=0;
    for (int i = 0; i < r; ++i)
    {
      vector<char> fila;
      for (int j = 0; j < c; ++j)
      {
        char c;
        cin>>c;
        fila.push_back(c);
        if(c=='w' || c=='W'){
          if(c=='W'){
            t++;
          }
          xw=i;yw=j;
        }else if(c=='+'){
          t++;
        }
      }
      mapa.push_back(fila);
    }
    cin>>instructions;
    int totalInst=instructions.size();
    bool encontro = false;
    for (int i = 0; i < totalInst; ++i)
    {
      int nxtDir = direc[instructions[i]];
      int newX =xw+posX[nxtDir];
      int newY =yw+posY[nxtDir];
      if(validPos(newX,newY,mapa)){
        if(mapa[newX][newY]=='.'){
          mapa[xw][yw] = (mapa[xw][yw]=='W')?'+':'.';
          mapa[newX][newY] = 'w';
          xw=newX;
          yw=newY;
        }else if(mapa[newX][newY]=='+'){
          mapa[xw][yw] = (mapa[xw][yw]=='W')?'+':'.';
          mapa[newX][newY] = 'W';
          xw=newX;
          yw=newY;
        }else if(mapa[newX][newY]=='b' && validPosBloq(newX+posX[nxtDir],newY+posY[nxtDir],mapa)){
          mapa[xw][yw] = (mapa[xw][yw]=='W')?'+':'.';
          mapa[newX+posX[nxtDir]][newY+posY[nxtDir]] = (mapa[newX+posX[nxtDir]][newY+posY[nxtDir]]=='.')?'b':'B';
          mapa[newX][newY] = 'w';
          xw=newX;
          yw=newY;
          if(mapa[newX+posX[nxtDir]][newY+posY[nxtDir]] == 'B'){
            t--;
          }
        }else if(mapa[newX][newY]=='B' && validPosBloq(newX+posX[nxtDir],newY+posY[nxtDir],mapa)){
          mapa[xw][yw] = (mapa[xw][yw]=='W')?'+':'.';
          mapa[newX+posX[nxtDir]][newY+posY[nxtDir]] = (mapa[newX+posX[nxtDir]][newY+posY[nxtDir]]=='+')?'B':'b';
          mapa[newX][newY] = 'W';
          xw=newX;
          yw=newY;
          if(mapa[newX+posX[nxtDir]][newY+posY[nxtDir]] == 'b'){
            t++;
          }
        }
      }
      if(t==0){
        encontro=true;
        printf("Game %d: complete\n",cases++);
        for (int k = 0; k < r; ++k)
        {
          for (int j = 0; j < c; ++j)
          {
            cout<<mapa[k][j];  
          }
          cout<<endl;
        }
        break;
      }
    }
    if(!encontro){
      printf("Game %d: incomplete\n",cases++);
      for (int i = 0; i < r; ++i)
      {
        for (int j = 0; j < c; ++j)
        {
          cout<<mapa[i][j];  
        }
        cout<<endl;
      }
    }
    

  }
  return 0;
}
