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


class PermutationAndMultiplication {
  public:
  string MakeShifting(string str, int stepnum) {
      string shifted = str;
      for (int i = 0 ; i < stepnum ; i++)
          shifted = shifted + '0';
      return shifted;
  }
  string addBinary(string a, string b) {
      string result = "";
      int s = 0;

      int i = a.size() - 1;
      int j = b.size() - 1;
      while (i >= 0 || j >= 0 || s == 1)
      {
          s += ((i >= 0)? a[i] - '0': 0);
          s += ((j >= 0)? b[j] - '0': 0);

          result = char(s % 2 + '0') + result;

          s /= 2;

          i--;
          j--;
      }
      return result;
  }
  string MakeMultiplication(string str1, string str2) {
    string allSum = "";
    for (int j = 0 ; j<str2.length(); j++) {
        int secondDigit = str2[j] - '0';
        if (secondDigit == 1) {
            string shifted = MakeShifting(str1,str2.size()-(j+1));
            allSum = addBinary(shifted, allSum);
        } else {
          continue;
        }
    }
    return allSum;
  }
  int multiplyAndCount(int ones, int zeroes) {
    // Build A
    string a, b;
    rep(i, 0, ones) { a += '1'; }
    rep(i, 0, zeroes) { a += '0'; }

    b = "1";
    rep(i, 0, zeroes) { b += '0'; }
    rep(i, 1, ones) { b += '1'; }
    string result = MakeMultiplication(a,b);
    deb(result);
    int total = 0;
    for(const auto p: result){if(p == '1') total++;}
    // cout<<"a"<<stoi(a, 0, 2)<<;
    // unsigned long long value = bitset<64>(s).to_ullong();
    // deb(a); deb(b);
    return total;
  }
};
int main(){
  PermutationAndMultiplication perm;
  cout<<perm.multiplyAndCount(2,0)<<endl;
  // for(int i = 0; i < 20; i++){
  //   cout<<i<<": "<<plus_castle.maximiseClosedFigures(i)<<endl;
  // }

  return 0;
}

