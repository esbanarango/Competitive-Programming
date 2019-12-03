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
#include <set>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("in.in", "r", stdin);

  vector <long long> nums(145);

  for(int i = 0; i < 145; i++) cin>>nums[i];
  nums[1] = 12;
  nums[2] = 2;
  int pos = 0;
  int code = nums[pos];
  while(code != 99) {
    if(code == 1) {
      nums[nums[pos+3]] = nums[nums[pos+1]] + nums[nums[pos+2]];
    } else {
      nums[nums[pos+3]] = nums[nums[pos+1]] * nums[nums[pos+2]];
    }
    pos += 4;
    code = nums[pos];
  }

  cout<<nums[0]<<endl;
  return 0;
}