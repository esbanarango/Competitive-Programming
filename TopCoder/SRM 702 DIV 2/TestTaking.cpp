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
using namespace std;

class TestTaking {
  public:
  int findMax(int questions, int guessed, int actual) {
    return min(questions - guessed, questions - actual) + min(actual, guessed);
  //   if(guessed == actual)
  //     return questions;
  //   else{

  //     return abs(abs(actual-guessed)-questions);
  //   }
  }
};

int main(){
  TestTaking test_taking;
  cout<<test_taking.findMax(50,49,0);
  return 0;
}
