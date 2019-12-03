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
#define printMap(mmap) for(auto p: mmap) { cout<< p.first<<": "<<p.second<<endl; }


int main(){
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  ll T, N;
  scanf("%lld\n",&T);
  while(T--) {
    vi nums(3);
    for(int i = 0; i<3; i++) { cin>>nums[i]; }
    sort(begin(nums), end(nums));
    // printArray(nums);
    if(nums[2] >= nums[1] + nums[0]){
      cout<<nums[1] + nums[0]<<endl;
    } else {
      int toEat = (nums[1] + nums[0])-nums[2];
      cout<<(nums[1] + nums[0] - toEat) + toEat/2<<endl;
    }
  }
  return 0;
}