/*
  String Similarity (25 Points)
  Interviewstreet Challenge
  Esteban Arango Medina
  
  Solution:
    At first look this problem can be achieve using a naive algorithm, two for's and then check and count
    the similarity for each substring. But it's O(n^2), so this just passed 6/10 of the testcases at most.
    So we need an algorithm that runs in O(n), and here's where the Z Algorithm appears on the scene.
    Z[i] = length of the longest prefix of S.str(i,n) that is also prefix of S.str(0,n).
    So the answer is  (S.length + ∑ z[i] from i - n).

  Notes.
    The Z Algorithm
        http://codeforces.com/blog/entry/3107
        http://www.notjustrandom.com/2008/11/01/the-z-algorithm/  
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
    int cases;scanf("%d",&cases);
    while(cases--){
        string s;
        cin>>s;
        int total=s.length();
        int n = s.size();
        //Z Algorithm
        vector<int> z(n);
        z[0] = 0;
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            z[i] = 0;
            if (i <= r) z[i] = min(z[i - l], r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
            total+=z[i];    //∑ z[i] from i - n)
        }
        printf("%d\n",total);
    }
    return 0;
}