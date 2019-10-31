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
typedef vector<int> vi;
typedef vector<vi> vivi;
typedef pair<int,int> ii;
typedef vector <ii> vii;
typedef vector<vii> vivii;


// Driver program to check findMaxPath
int main(){
  freopen("in.in", "r", stdin);
  int n, m, res = -1;
  scanf("%d %d", &n, &m);
  vivi matriz(n+2,vi(m));

  // read data
  for (int i = 1; i < n+1; ++i){
    for (int j = 0; j < m; ++j){
      scanf("%d", &matriz[i][j]);
    }
  }

  for (int i = 0; i < n+2; ++i){
    for (int j = 0; j < m; ++j){
      printf("%d ",matriz[i][j]);
    }
    printf("\n");
  }



  // // To find max val in first row
  // for (int i = 0; i < n; i++)
  //   res = max(res, mat[0][i]);

  // for (int i = 1; i < N; i++) {

  //   res = -1;
  //   for (int j = 0; j < M; j++) {

  //     // When all paths are possible
  //     if (j > 0 && j < M - 1)
  //       mat[i][j] += max(mat[i - 1][j],
  //               max(mat[i - 1][j - 1],
  //                 mat[i - 1][j + 1]));

  //     // When diagonal right is not possible
  //     else if (j > 0)
  //       mat[i][j] += max(mat[i - 1][j],
  //               mat[i - 1][j - 1]);

  //     // When diagonal left is not possible
  //     else if (j < M - 1)
  //       mat[i][j] += max(mat[i - 1][j],
  //               mat[i - 1][j + 1]);

  //     // Store max path sum
  //     res = max(mat[i][j], res);
  //   }
  // }

  // cout << findMaxPath(mat);
  return 0;
}
