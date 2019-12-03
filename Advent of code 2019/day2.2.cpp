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
  // Read numbers
  for(int i = 0; i < 145; i++) cin>>nums[i];

  int noun, verb;
  for(noun = 0; noun < 100; noun++) {
    for(verb = 0; verb < 100; verb++) {
      vector<long long> numsCopy(nums);
      int pos = 0;
      numsCopy[1] = noun;
      numsCopy[2] = verb;
      int code = numsCopy[pos];
      while(code != 99) {
        if(code == 1) {
          numsCopy[numsCopy[pos+3]] = numsCopy[numsCopy[pos+1]] + numsCopy[numsCopy[pos+2]];
        } else {
          numsCopy[numsCopy[pos+3]] = numsCopy[numsCopy[pos+1]] * numsCopy[numsCopy[pos+2]];
        }
        pos += 4;
        code = numsCopy[pos];
      }
      if(numsCopy[0] == 19690720){
        cout<<"noun: "<<noun<<endl;
        cout<<"verb: "<<verb<<endl;
        return 0;
      }
    }
  }
  return 0;
}