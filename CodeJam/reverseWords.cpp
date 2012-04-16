/*
    Reverse Words
    Code Jam
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
    freopen("B-small-practice.in", "r", stdin);
    freopen("reverseWords.out", "w", stdout);

    string s;
    int n,cases=1;scanf("%d",&n);
    getline(cin,s);
    while(n--){
        
        size_t found;
        vector<string> words;
        getline(cin,s);
        printf("Case #%d: ",cases++);
        found = s.find(" ");
        while(found!=string::npos){
            //cout<<found<<" "<<s<<endl;
            words.push_back(s.substr (0,found));
            s=s.substr(found+1,(s.length()-1));
            found = s.find(" ");
        }
        words.push_back(s);
        for (int i = words.size()-1; i >=0 ; --i)
        {
            cout<<words[i];
            if(i-1>=0)
                cout<<" ";
        }
        if(n)
            cout<<endl;

    }

    return 0;
}