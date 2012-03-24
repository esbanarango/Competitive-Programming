/*
  3004 - Mispelling 
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include <iostream>
#include <string>

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
