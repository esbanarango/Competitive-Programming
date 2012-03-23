/*
  42 - Adding Reversed Numbers
  Sphere Online Judge
  Esteban Arango Medina
  
  Solution:
  	Reverse both numbers, sum them and print the reverse result.
*/
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

unsigned reverse(unsigned num){
  unsigned reversed = 0;
  while(num){
    reversed = reversed*10+num%10;
    num = num/10;
  }
  return reversed;
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		unsigned num1,num2;
		scanf("%u %u",&num1,&num2);
		printf("%u\n",reverse(reverse(num1)+reverse(num2)));
	}
	return 0;
}