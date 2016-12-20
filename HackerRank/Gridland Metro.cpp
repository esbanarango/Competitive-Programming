/*
  Gridland Metro (25 points)
  HackerRank
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
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef map <ll,iii> miiii;

int main() {
  // freopen("in.in", "r", stdin);
  ll n,m,k,r,from,to; scanf("%lld %lld %lld",&n,&m,&k);
  ll total_lamps = n*m, total_trakcs = 0;
  miiii tracks;
  for (int i = 0; i < k; ++i){
    scanf("%lld %lld %lld", &r, &from, &to);
    if(!tracks.count(r)){
      tracks[r].first = (to - from) + 1; tracks[r].second.first = from; tracks[r].second.second = to;
    }else{
      if((from <= tracks[r].second.second &&  from >= tracks[r].second.first) || (to >= tracks[r].second.second &&  to <= tracks[r].second.first)){
        if(tracks[r].second.first > from)
          tracks[r].second.first = from;
        if(tracks[r].second.second < to)
          tracks[r].second.second = to;
        tracks[r].first = (tracks[r].second.second - tracks[r].second.first) + 1;
      }else{
        tracks[r].first += (to - from) + 1;
      }
    }
  }

  for (miiii::iterator it=tracks.begin(); it!=tracks.end(); ++it){
    // cout<<"Fomr :"<< it->second.second.first<<" To:" << it->second.second.first<<" Total "<<it->second.first<<endl;
    total_trakcs += it->second.first;
  }

  // cout<<"Lamps:"<< total_lamps<<endl;
  // cout<<"Tracks: "<< total_trakcs<<endl;
  cout<<total_lamps - total_trakcs<<endl;
  // printf("%d\n", total_lamps - total_trakcs);

  return 0;
}