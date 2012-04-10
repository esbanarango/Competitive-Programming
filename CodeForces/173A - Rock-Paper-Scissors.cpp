/*
  173A - Rock-Paper-Scissors 
  CodeForces
  A. Rock-Paper-Scissors
  Croc Champ 2012 - Round 1 
  Esteban Arango Medina

  Solution.
    In this problem I got hacked twice :(, until I realized that you don't have to simulate the process all the n rounds (TLE), 
    so if sequenceA.length*sequenceB.lentgh is greater or equals to rounds simulate the process until round otherwise simulate
    the process until sequenceA.length*sequenceB.lentgh rounds and then it will be the same cyclic, then it's just a math problem.

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

  map<char,char> rules;
  rules['P']='R';
  rules['R']='S';
  rules['S']='P';

  vector<pair<long,long> > scores;

  long long rounds;
  cin>>rounds;
  string sN,sP;

  long long cN=0,cP=0;
  cin>>sN;
  cin>>sP;
  int sSize = sN.size();
  int pSize = sP.size();
  int realsRounds = sSize*pSize;
  if(realsRounds >= rounds){
    for (long long i = 0, in=0,ip=0; i < rounds; ++i,++in,++ip)
    {
        if(in==sSize)in=0;
        if(ip==pSize)ip=0;
        if(!(sN[in] == sP[ip])){
          (rules[sN[in]] == sP[ip])?cN++:cP++;
        }

    }
  }else{
    for (long long i = 0, in=0,ip=0; i < realsRounds; ++i,++in,++ip)
    {
        if(in==sSize)in=0;
        if(ip==pSize)ip=0;
        if(!(sN[in] == sP[ip])){
          (rules[sN[in]] == sP[ip])?cN++:cP++;
        }
        pair <long,long> temp(cN,cP);
        scores.push_back(temp);
    }
    int times=(rounds/realsRounds);
    rounds -= times*realsRounds;
    if(rounds==0){
      cN=(scores[realsRounds-1].first*times);
      cP=(scores[realsRounds-1].second*times);
    }else{
      cN=scores[rounds-1].first+(scores[realsRounds-1].first*times);
      cP=scores[rounds-1].second+(scores[realsRounds-1].second*times);
    }
  }
  cout<<cP<<" "<<cN;
 return 0;  
}
