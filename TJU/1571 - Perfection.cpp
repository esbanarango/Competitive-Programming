/*
  1571 - Perfection  
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <sstream>

using namespace std;

int digits (int n){
  stringstream ss;
  ss << n;
  string s = ss.str();
  return s.length();
}

int main(){

  printf("PERFECTION OUTPUT\n");
  int n;
  int num;
  while(scanf("%d", &n) && n){
    vector<int> v;
    int digit = digits(n); 
    for (int i = 1; i <= n/2; i++){
      if(n%i == 0){
	         v.push_back(i);
      }
    }
    int sum = accumulate(v.begin(), v.end(), 0);
    string s;
    for (int i = 0; i < 5 - digit; i++){
      s += " ";
    }
    cout <<s;
    if(n < sum){
      printf("%d  ABUNDANT\n", n);
    } else if(n > sum){
      printf("%d  DEFICIENT\n", n);
    } else {
      printf("%d  PERFECT\n", n);
    }

  }
  printf("END OF OUTPUT\n");
  return 0;
}
