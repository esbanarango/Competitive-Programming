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

vsi moves;

bool eat(vi &initial, int from,  int limit_left, int goal, bool reversed, bool variation){
  int size = initial.size();
  int new_eaten, eaten_r, eaten_l;
  bool cond_left, cond_right;
  cond_left = (from-1 > limit_left) && (initial[from] > initial[from-1]);
  cond_right = (from+1 < size) && (initial[from] > initial[from+1]);

  // There could be a better in front
  if(variation && (cond_left || cond_left) && from + 1 < size && initial[from+1] > initial[from]) from++;

  cond_left = (from-1 > limit_left) && (initial[from] > initial[from-1]);
  cond_right = (from+1 < size) && (initial[from] > initial[from+1]);

  if(cond_left){
    new_eaten = initial[from-1] + initial[from];
    initial.erase(initial.begin()+(from-1));
    initial[from-1] = new_eaten;
    if(reversed){
      moves.push_back(si("R",size-from));
    }else{
      moves.push_back(si("L",from+1));
    }
    return true;
  }
  if(cond_right){
    new_eaten = initial[from+1] + initial[from];
    initial.erase(initial.begin()+(from+1));
    initial[from] = new_eaten;
    if(reversed){
      moves.push_back(si("L",size-from));
    }else{
      moves.push_back(si("R",from+1));
    }
    return true;
  }
  return false;
}

bool solve(vi initial, vi final, bool reversed, bool variation){
  int final_monsters = final.size();
  bool reachable = true;
  if(reversed) reverse(initial.begin(),initial.end());
  moves.clear();
  for (int i=0,j=0; (i < final_monsters) && reachable; ++i,++j){
    int current_j = j;
    if(final[i] < initial[j]){
      reachable = false;
      break;
    }
    while(final[i] != initial[j]){
      if(!eat(initial,current_j,i-1,initial[j],reversed,variation)){
        current_j++;
        if(current_j >= initial.size()){
          reachable = false;
          break;
        }
      }else{
        if(final[i] < initial[j]){
          reachable = false;
          break;
        }
        current_j=i;
      }
    }
  }
  return reachable;
}

int main(){
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  int initial_monsters, final_monsters, initial_sum=0, final_sum=0;
  scanf("%d",&initial_monsters);
  vi initial(initial_monsters);
  for (int i = 0; i < initial_monsters; ++i){
    scanf("%d",&initial[i]);
    initial_sum += initial[i];
  }
  scanf("%d",&final_monsters);
  vi final(final_monsters);
  for (int i = 0; i < final_monsters; ++i){
    scanf("%d",&final[i]);
    final_sum += final[i];
  }
  if(final_sum == initial_sum){
    // Solve
    if(solve(initial,final,false,false) || solve(initial,final,true,false) || solve(initial,final,false,true)){
      printf("YES\n");
      int total_moves = moves.size();
      for (int i = 0; i < total_moves; ++i) cout<<moves[i].second<<" "<<moves[i].first<<endl;
    }else{
      printf("NO\n");
    }
  }else{
    printf("NO\n");
  }
  return 0;
}