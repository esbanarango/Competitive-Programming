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
typedef map <int,int> mii;
typedef map <string,string> mss;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define endl '\n' // Normal `cout << endl` flushes the output every time wich hit performance badly
#define INF 1000000000
#define deb(x) cout<<#x<<": "<<x<<endl;
#define printArray(arr) for(auto x: arr) { cout<<x<<", "; }
#define printMatrix(mat) for(auto x: mat) { cout<<" "; printArray(x); cout<<endl; }
#define printMap(mmap) for(auto p: mmap) { cout<< p.first<<": "<<p.second<<endl; }

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  int n, ans = 1; cin>>n;
  mii totals;
  vi nums(n);
  rep(i, 0, n) { cin>>nums[i]; totals[nums[i]]++; }
  sort(rbegin(nums), rend(nums));
  // printArray(nums); cout<<endl;
  rep(i, 0, n) {
    if(!totals.count(nums[i]+1)) {
      totals[nums[i]+1]++;
      totals[nums[i]]--;
    }else if(nums[i]-1 > 0 && !totals.count(nums[i]-1)) {
      totals[nums[i]-1]++;
      totals[nums[i]]--;
    }
    if(totals[nums[i]] == 0){
      auto it=totals.find(nums[i]);
      totals.erase(it);
    }
  }
  printMap(totals);
  cout<<totals.size()<<endl;
  return 0;
}