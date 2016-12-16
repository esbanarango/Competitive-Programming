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
typedef vector <vi> vivi;
typedef vector <char> vc;
typedef vector <string> vs;
typedef map <string,vs> msvs;
typedef map <string,int> msi;
typedef map <string,string> mss;
#define INF 1000000000

class GridSort {
  public:
  bool checkRow(int n, int m, vector <int> grid) {
    int row = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m - 2 ; ++j, ++row){
        cout<<"Row: ("<<row<<","<<row+1<<") Result:"<<abs(grid[row] - grid[row+1])<<endl;
        if(abs(grid[row] - grid[row+1]) >= m)
          return false;
      }
    return true;
  }
  bool checkColumn(int n, int m, vector <int> grid) {
    int dif = (n*m)- m;
    for (int i = 0; i < m; ++i)
      for (int j = 0, column=i; j < n - 1; ++j, column += m){
        cout<<"column: ("<<column<<","<<column+m<<") Result:"<<abs(grid[column] - grid[column+m])<<endl;
        if(abs(grid[column] - grid[column+m]) > dif)
          return false;
      }
    return true;
  }
  string sort(int n, int m, vector <int> grid) {
    if(n == 1 || m == 1)
      return "Possible";
    else{
      // cout<<checkRow(n,m,grid);
      // cout<<checkColumn(n,m,grid);
      if(checkRow(n,m,grid) && checkColumn(n,m,grid))
        return "Possible";
      else
        return "Impossible";
    }
  }
};

int main(){
  GridSort grid_sort;
  static const int arr[] = { 10,6,8,9,7, 5,1,3,4,2, 15,11,13,14,12 };
  vector<int> vec;
  for (int i = 1; i < 2501; ++i)
    vec.push_back(i);
  cout<<grid_sort.sort(50,50,vec);
  return 0;
}

