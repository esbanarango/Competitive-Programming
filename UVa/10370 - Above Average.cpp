/*
  10370 - Above Average
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

int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
            int n;       
            float grade,resp=0,average=0;
            scanf("%d",&n);
            float students[n];
            
            for(int i=0;i<n;i++){
                    scanf("%f",&grade);
                    students[i]=grade;
                    average+=grade;  
            }
            average/=n;
            for(int i=0;i<n;i++){
                    if(students[i]>average){
                            resp++;                
                    }
            }
            resp/=n;
            resp*=100;
            printf("%.3lf",resp);
            cout<<"%"<<endl;     
    }

 return 0;   
}
