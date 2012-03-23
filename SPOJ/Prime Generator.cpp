#include <stdio.h>

const int LIMIT = 100000000;

int sieve[LIMIT + 1]; // Inicializar con 0’s.
int primes[LIMIT + 1];
int primeCount = 1;

/******** Criba de Eratóstenes ********/
void generatedPrimes(){
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
	generatedPrimes();
	int t;
	scanf("%d",&t);
	while(t--){
		int m,n;
		scanf("%d %d",&m,&n);
		if (m <= 2 && 2 <= n){
	      printf("2\n");
	    }
		// i es primo si primes[sieve[i]] == i, y compuesto si no.
		for(int i=m;i<=n;i+=2){
			if(primes[sieve[i]] == i)
				printf("%d\n",i);
		}
	}
	return 0;
}