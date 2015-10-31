/*
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
#include <bitset>
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
typedef vector <string> vs;
typedef map <string,vs> msvs;
typedef map <string,int> msi;
typedef map <string,string> mss;
#define INF 1000000000

vii white_paws;
vii black_paws;
char board[8][9]={'.'};


int road(ii position,int direction){
  int i = position.first, j = position.second;
  int total = 0;
  while((direction == 1 && i >= 0 && i< 7) || (direction == -1 && i <= 7 && i > 0)){
    i += direction;
    if (board[i][j] == 'W' || board[i][j] == 'B'){
      total = 10000;
      i = -1;
    }else{
      total++;
    }
  }
  return total;
}

int main(){
  // freopen("in.in", "r", stdin);

  string line;
  si current_winner ("X",100);
  for (int i = 0; i < 8; ++i){
    cin>>line;
    for (int j = 0; j < 8; ++j){
      if(line[j] == 'B'){

        black_paws.push_back(ii(i,j));
      }else if(line[j] == 'W'){
        white_paws.push_back(ii(i,j));
      }
      board[i][j] = line[j];
    }
  }

  for (int i = 0; i < black_paws.size(); ++i){
    int total = road(black_paws[i],1);
    if(current_winner.second > total){
      current_winner.second = total;
      current_winner.first = 'B';
    }
  }

  for (int i = 0; i < white_paws.size(); ++i){
    int total = road(white_paws[i],-1);
    if(current_winner.second >= total){
      current_winner.second = total;
      current_winner.first = 'A';
    }
  }
  cout<<current_winner.first;

 return 0;

}