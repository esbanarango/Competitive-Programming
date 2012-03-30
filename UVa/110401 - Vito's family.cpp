/*
  110401 - Vito's Family
  UVa Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
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

int *relatives;
int *distances;

int main(){
    int cases;
    scanf("%d",&cases);   
    
    while(cases--){
            int num,sum=0;
            scanf("%d",&num);
            
            distances = new int [num-1];
            relatives = new int [num];
            
            
            for(int i=0;i<num;i++){
                  cin>>relatives[i];
            }
            for(int i=0;i<num;i++){
                    for(int j=0;j<num;j++){
                            if(j!=i){sum+=abs(relatives[i]-relatives[j]);}
                    }
                    distances[i]=sum;
                    sum=0;
            }
            cout<<*min_element(distances,distances+num-1)<<endl;
            
    }

    return 0;
}
