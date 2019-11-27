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
#include <tuple>
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
#define deb(x) cout<<#x<<": "<<x<<endl;
#define printArray(arr) for(auto x: arr) { cout<<x<<", "; }
#define printMatrix(mat) for(auto x: mat) { cout<<" "; printArray(x); cout<<endl; }

int main(){
  // freopen("in.in", "r", stdin);
  string grid = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  // freopen("out.out", "w", stdout);
  int T, R, C, K;
  scanf("%d\n",&T);
  while(T--) {
    int currentGrid = 0, totalRice = 0, currentChicken, perGrid, remaining;
    scanf("%d %d %d\n",&R, &C, &K);
    vector<vc> chickenRun(R, vc(C));
    for(int i = 0; i < R; i++) {
      for(int j = 0; j < C; j++) {
        cin>>chickenRun[i][j];
        if(chickenRun[i][j] == 'R') { totalRice++; }
      }
    }
    perGrid = totalRice / K;
    remaining = totalRice - (perGrid * K);

    currentChicken =  perGrid + (remaining > 0 ? 1 : 0);
    remaining--;
    // Build corral
    for(int i = 0, twist = 1; i < R; i++) {
      for(int j = twist > 0 ? 0 : C -1 ; j < C && j > -1; twist > 0 ? j++ : j--) {
        if(currentChicken == 0){
          if(totalRice>0) currentGrid++; // Keep painting if there are no more rice
          currentChicken = perGrid + (remaining > 0 ? 1 : 0);
          remaining--;
        }
        if(chickenRun[i][j] == 'R'){ currentChicken--; totalRice--; }
        chickenRun[i][j] = grid[currentGrid];
      }
      twist *= -1;
    }
    // Print corral
    for(int i = 0; i < R; i++) {
      for(int j = 0; j < C; j++) {
        cout<<chickenRun[i][j];
      }
      cout<<endl;
    }
  }
  return 0;
}