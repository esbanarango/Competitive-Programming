/*
  3004 - Mispelling 
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <utility>
#include <list>
#include <set>
#include <map>
using namespace std;

using namespace std;

int main(){
    int n,num,cas=1;
    string word;
    scanf("%d",&n);
    while(n--){
            cin>>num>>word;
            word.erase(num-1,1);
            cout<<cas<<" "<<word<<endl;
            cas++;
    }
    return 0;
}
