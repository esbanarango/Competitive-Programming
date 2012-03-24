/*
  2945 - HERMAN
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include<iostream>

using namespace std;

int main(){   
    int r;
    double pi = 3.14159265358979323846;
    
    cin>>r;
    
    double areaE;
    double areaT;
    
    areaE = pi*r*r;
    areaT = 2*r*r;
    
    cout.precision(6);
    cout<<fixed<<areaE<<endl<<areaT<<endl;
    return 0;
}
