/*
  429 - Word Transformation
  UVa Online Judge
  Esteban Arango Medina

  Solution.
    If two words differ by one letter conect them. Then BFS.
    *Remeber to clear the visted map! :P

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

map<string,int> visited;

int bfs(string start, string to, map< string,vector<string> > graph){
  
  queue<string> s;
  s.push(start);
  visited[start]=0;
  while(s.empty()==false){
    string top = s.front();
    s.pop();
    if(top==to)
      return visited[top];
    int total =graph[top].size();
    for (int i = 0; i < total; ++i)
    {
      if(!visited.count(graph[top][i])){
        visited[graph[top][i]]=visited[top]+1;
        s.push(graph[top][i]);
      }
    }
  }
}

int main(){
  int n;scanf("%d",&n);
  while(n--){
    map<string, vector<string> > graph;
    string word,tmp;
    cin>>word;
    while(word != "*"){
      graph[word];
      map<string, vector<string> >::const_iterator it;
      for (it = graph.begin(); it != graph.end(); ++it)
      {
        tmp=(*it).first;
        int tamTmp = tmp.size(),dif=0;
        if(tamTmp == word.size()){
          for (int i = 0; i < tamTmp && dif<2; ++i)
          {
            if(tmp[i]!=word[i])
              dif++;
          }
          if(dif==1){
            graph[tmp].push_back(word);
            graph[word].push_back(tmp);
          }
        }
      }
      cin>>word;
    }
    string start,to,line;
    size_t pos;
    getline(cin,line);
    getline(cin,line);
    while(line != ""){
      pos = line.find(" ");
      start = line.substr(0,pos);
      to = line.substr(pos+1,line.size());
      visited.clear();
      cout<<start<<" "<<to<<" "<<bfs(start,to,graph)<<endl;
      if(!getline(cin,line))
        break;
    }
    if(n != 0)
      cout<<endl;
  }
  return 0;
}