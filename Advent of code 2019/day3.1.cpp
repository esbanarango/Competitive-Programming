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
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;
#define deb(x) cout<<#x<<": "<<x<<endl;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("in.in", "r", stdin);
  map<pair<int, int>, bool> visitedPath;
  string wirePath;
  int minDistance = INT_MAX;
  int i = 1;
  // Read path
  while(getline (cin,wirePath)) {
    map<pair<int, int>, bool> currentPath;
    stringstream ss(wirePath);
    string move;
    pair<int, int> pos = {0,0};
    // Read moves
    while (getline(ss, move, ',')) {
      char direction = move.front();
      move.erase(move.begin());
      int distance = stoi(move);
      while(distance--){
        switch (direction) {
        case 'U': pos.first++; break;
        case 'D': pos.first--; break;
        case 'R': pos.second++; break;
        case 'L': pos.second--; break;
        }
        if(visitedPath[pos] && !currentPath[pos]){
          minDistance = min(minDistance, abs(pos.first) + abs(pos.second));
        }
        currentPath[pos] = true;
        visitedPath[pos] =  true;
      }
    }
  }
  cout<<minDistance<<endl;
  return 0;
}