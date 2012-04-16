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

int points [105];

int main(){
    //freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int t,n,s,p,cases=1;scanf("%d",&t);
    while(t--){        
        printf("Case #%d: ",cases++);
        scanf("%d %d %d",&n,&s,&p);        
        int actualScore,cont = 0;

        for (int i = 0; i < n; ++i)
        {
            scanf("%d",&actualScore);
            int rem = actualScore/3;
            if(rem*3 == actualScore && rem>=p)
                cont++;  
            else if(rem*3 == actualScore && s && rem+1>=p && actualScore > p){
                cont++;
                 s--;
            }
            else if((actualScore - (rem*3) == 1) && rem+1 >=p)
                cont++;
            else if((actualScore - (rem*3) == 2) && (rem>=p || rem+1>=p)){
                cont++;
            }else if((actualScore - (rem*3) == 2) && rem+2 >=p && s){
                 cont++;
                 s--;
            }
               

        }


        printf("%d",cont);
        if(n)
            printf("\n");

    }
    return 0;
}