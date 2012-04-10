/*
ID: marrano1
PROG: gift1
LANG: C++
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

struct person
{
    int inicial,recibido;
};

int main(){
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    int n,ini,par;
    string name,parName;
    map<string,person>people;
    vector<string> order;
    scanf("%d",&n);
    for(int i = 0;i<n;++i){
        cin>>name;
        person p = {0,0};
        people[name]=p;
        order.push_back(name);
    }
    int count = n;
    while(count--){
        cin>>name;
        scanf("%d %d",&ini,&par);
        int dar=0;
        if(ini!=0 && par != 0)
            dar = ini/par;
        people[name].recibido += (ini-(dar*par));
        people[name].inicial = ini;
        for (int i = 0; i < par; ++i)
        {
            cin>>parName;
            people[parName].recibido+=dar;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        string name = order[i];
        int total = people[name].recibido-people[name].inicial;
        cout<<name<<" "<<total<<endl;
    }

    return 0;
}