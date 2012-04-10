/*
  156 - Ananagrams
  UVa Online Judge
  Esteban Arango Medina

    Solution.
        Ad Hoc, I used a map (string, pair<string,int>) to count how many times appears one letter and then just print 
        those that appears once.

    Note.
        Didn't know how to convert a string to upper or lower case.
            http://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/

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
    map <string, pair<string,int> > words;
    vector<string> result;
    string word,wordSorted;cin>>word;
    while(word != "#"){
        wordSorted=word;
        transform(wordSorted.begin(), wordSorted.end(),wordSorted.begin(),::toupper);
        sort(wordSorted.begin(),wordSorted.end());
        words[wordSorted].first=word;
        words[wordSorted].second++;
        cin>>word;
    }
    map<string, pair<string,int> >::const_iterator itr;
    for(itr = words.begin(); itr != words.end(); ++itr){
            if((*itr).second.second == 1)
                result.push_back((*itr).second.first);
    }
    sort(result.begin(),result.end());
    int total = result.size();
    for (int i = 0; i < total; ++i)
    {
        cout<<result[i]<<endl;
    }
 return 0;   
}