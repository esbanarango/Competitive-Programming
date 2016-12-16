#include <bits/stdc++.h>

using namespace std;

vector<int> cycles;
vector<int> used;
bool ok = true;

void dfs(vector<int> &a, int start, int v, int len){
  used[v] = true;
  if(used[a[v]]) {
    if(start == a[v])cycles.push_back(len & 1 ? len : len / 2);
    else ok = false;
  } else dfs(a, start, a[v], len + 1);
}

int gcd(int x, int y){
  while(x > 0 && y > 0){
    if(x > y)x %= y; else y %= x;
  }
  return x + y;
}

int lcm(int x, int y){
  return x * y / gcd(x, y);
}

int solve(vector<int> &a){
  int res = -1;
  int n = a.size();
  used.resize(n);
  for (int i = 0; i < n; i++){
    if(!used[i])dfs(a, i, i, 1);
  }
  if (cycles.empty() || !ok)return -1;
  res = cycles[0];
  for(int i = 1; i < cycles.size(); i++){
    res = lcm(res, cycles[i]);
  }
  return res;
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  cout << solve(a) << endl;
  return 0;
}