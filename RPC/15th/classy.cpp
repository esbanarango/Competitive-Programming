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

struct person{
  string name;
  string classes;
};

bool compareitor (person a, person b){
  if(a.classes == b.classes){
    return a.name > b.name;
  }else{
    return a.classes < b.classes;
  }
}

int main() {
  // freopen("in.in", "r", stdin);
  int n; scanf("%d",&n);
  vector <person> people(n);
  string claz;
  for (int i = 0; i < n; ++i){
    person p;
    string classes = "";
    cin>>p.name;
    p.name.erase(p.name.end()-1);
    cin>>claz;
    do{
      classes.insert(0,claz);
      cin>>claz;
    }while(claz != "class");
    while(classes.length() < 256)
      classes.append("middle");
    p.classes = classes;
    people[i] = p;
  }

  sort(people.begin(), people.end(), compareitor);

  for (int i = n-1; i >= 0; --i){
    cout<<people[i].name<<endl;
    // cout<<people[i].classes<<endl;
  }
  return 0;
}