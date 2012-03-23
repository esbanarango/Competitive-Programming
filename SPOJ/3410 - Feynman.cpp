/*
	3410 - Feynman
	Sphere Online Judge
  	Esteban Arango Medina

	Solution:
		Simply the Sum of squares.
		1 + 2² + 3² + ... + n²= ∑ n² from i=1 - n = n(n + 1)(2n + 1) / 6 
	
	Notes.
		Sum of squares.
			http://www.trans4mind.com/personal_development/mathematics/series/sumNaturalSquares.htm
*/
#include <stdio.h>
using namespace std;

int main(){
	for(int n;scanf("%d",&n)&&n;printf("%d\n",((2*n+1)*n*(n+1))/6));
	return 0;
}