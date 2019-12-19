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
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
  int q; cin>>q;
  while(q--) {
    vector<ll> nums(3); cin>>nums[0]>>nums[1]>>nums[2];
    sort(begin(nums), end(nums));
    if(nums[0]==nums[1] && nums[1] ==nums[2]) { cout<<0<<endl; continue; }
    // printArray(nums);cout<<endl;
    if(nums[0]==nums[1] && nums[1] < nums[2]) { nums[1]++; nums[0]++;} else{
      if(nums[0]!=nums[1]) { nums[0]++;}
      if(nums[0]!=nums[1]) { nums[1]--;}
    }

    if(nums[2]!=nums[1]) { nums[2]--;}
    // printArray(nums);cout<<endl;
    cout<<(abs(nums[0] - nums[1]) + abs(nums[0] - nums[2]) + abs(nums[2] - nums[1]))<<endl;

  }
  return 0;
}