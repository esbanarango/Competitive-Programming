#include<iostream>

using namespace std;

int main(){
    int cases;
    long long l1;
    long long l2;
    long long l3;
    
    int i=0;
    
    cin>>cases;
    
    while(cases--){
            
            cin>>l1>>l2>>l3;
            
         if(l1 + l2 <= l3)  
             cout<<"Case "<<i+1<< ": Invalid"<<endl;  
         else if(l1 == l2 && l2 == l3)  
             cout<<"Case "<<i+1<< ": Equilateral"<<endl;  
         else if(l1 == l2 || l2 == l3)  
             cout<<"Case "<<i+1<< ": Isosceles"<<endl;  
         else  
             cout<<"Case "<<i+1<< ": Scalene"<<endl;

            i++;   
 }
 system("pause");
    return 0;
}

