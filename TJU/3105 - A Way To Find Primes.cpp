/*
  3105 - A Way To Find Primes
  TJU Online Judge
  Esteban Arango Medina
  
  Solution:
  	Generate the sieve of eratosthenes until the limit (100000) and then just print the k-th prime.
  	In this case the first prime is in the position primes[1].

  Notes.
  	Here is a nice gif showing the process of the algorithm.
  	http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
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

const int LIMIT = 100000;
int sieve[LIMIT + 1]; // Inicializar con 0’s.
int primes[LIMIT + 1];
int primeCount = 1;
void criba(){
	for (int i = 2; i <= LIMIT; ++i) {
	  if (!sieve[i]) {
	  	primes[primeCount] = i;
	    sieve[i] = primeCount;
	    primeCount++;
	  }
	  for (int j = 1; j <= sieve[i] && i * primes[j] <= LIMIT; j++){
	    sieve[ i * primes[j] ] = j;
	  } 
	}
}

int main(){
	criba();
    int cases;scanf("%d",&cases);
    while(cases--){
        int k;
        scanf("%d",&k);
        printf("%d\n",primes[k]);

    }
    return 0;
}