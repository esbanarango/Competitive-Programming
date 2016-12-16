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

double side(int x1, int y1, int x2, int y2){
  return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}

int main(){
  // freopen("in.in", "r", stdin);
  int x1,y1,x2,y2,x3,y3;
  double r,my_r,A,a,b,c, result;
  scanf("%d %d", &x1, &y1);
  scanf("%d %d", &x2, &y2);
  scanf("%d %d", &x3, &y3);
  scanf("%lf", &r);

  A = 0.5*abs((x1*y2)+(x2*y3)+(x3*y1)-(x2*y1)-(x3*y2)-(x1*y3));
  a = side(x1,y1,x2,y2);
  b = side(x1,y1,x3,y3);
  c = side(x2,y2,x3,y3);

  my_r = A / ((a+b+c)/2.0);

  if(my_r == r){
    printf("0\n");
  }else{
    result = (my_r * 100.0 / r);
    printf("%lf\n",((my_r * 100.0 / r) - 100));
  }
 return 0;
}