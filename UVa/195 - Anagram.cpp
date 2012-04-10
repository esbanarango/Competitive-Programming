/*
  195 - Anagram
  UVa Online Judge
  Esteban Arango Medina

    Solution.
        Got WA until I found (on http://www.algorithmist.com/index.php/UVa_195) that I had to write my own compare function.
        because the alphabet order is 'A -> a -> B -> b -> C -> c ..... -> Y -> y -> Z -> z'
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

bool compare (char a, char b)
{
    bool minisculaA = true, minisculaB = true;
    if (a >= 'A' && a <= 'Z') 
        minisculaA = false;
    if (b >= 'A' && b <= 'Z') 
        minisculaB = false;
 
    //Both are upper or lower case
    if (minisculaA && minisculaB) 
        return a < b;
    if (!minisculaA && !minisculaB) 
        return a < b;
    
    //a it's a lowercase
    if (minisculaA)
    {
        a -= ('a'-'A');
        return a < b;
    }
    else
    {
        b -= ('a'-'A');
        return a <= b;
    }
}

int main(){
    int cases;scanf("%d",&cases);
    while(cases--){
        string s;
        cin>>s;
        sort(s.begin(),s.end(),compare);
        do{
            cout<<s<<endl;
        }while(next_permutation(s.begin(),s.end(),compare));
    }
 return 0;   
}