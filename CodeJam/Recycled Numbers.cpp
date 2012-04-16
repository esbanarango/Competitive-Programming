/*
    Recycled Numbers
    Code Jam    2012
    Esteban Arango Medina
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
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

string trunc(string s, int pos){
    string temp;
    temp = s.substr(0,pos);
    return s.substr(pos,s.length())+temp; 
}

bool diferente (string s){
    int size = s.length();
    for (int i = 1; i < size; ++i)
    {
        if(s[i-1]!=s[i])
            return true;
    }

    return false;
}

int main(){
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int n,a,b,cases=1;scanf("%d",&n);
    while(n--){
        map<int, set<int> > ealos;
        scanf("%d %d",&a,&b);
        printf("Case #%d: ",cases++);
        int contador = 0;
        if(a>=10){
            for (int i = a; i < b; ++i)
            {   
                string s;
                stringstream out;
                out << i;
                s = out.str();
                int size = s.length();            
                for(int j = size-1; j>0;--j)
                {
                    int depronto;
                    if(s[j]!='0' && diferente(s)){
                        depronto = atoi(trunc(s,j).c_str());
                        if((depronto>=a && depronto<=b) && depronto > atoi(s.c_str())){
                            ealos[depronto].insert(atoi(s.c_str()));
                        }                   
                    }
                }
            }
            map<int, set<int> >::const_iterator itr;
            for (itr = ealos.begin(); itr != ealos.end(); itr++)
            {
                contador+=(*itr).second.size();
            }
        }
        printf("%d",contador);
        if(n)
            printf("\n");

    }
    return 0;
}