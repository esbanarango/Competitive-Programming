/*
  10399 - Conga line
  Sphere Online Judge
  Esteban Arango Medina
  
  Solution:
  	This problem could have multiple approaches, the first that I took was, stay in the middle of the array,
  	then see where are more people, left side or right side, and move all the people that is in the other side,
  	and repeat it until all positions are contiguous. With this approach I got TLE, obviously cause it's
  	O(n^2). So here's a better approach "Take the ith person from the left and the ith person from the 
  	right. The steps they must walk is their current distance minus their desired distance.", this one is
  	O(n).

  Notes.
  	TopCoder forum where I found the second approach.
  	http://apps.topcoder.com/forums/?module=Thread&threadID=739383&mc=3&view=flat
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    long long n;
    while(scanf("%lld",&n) && n!=0){
    	long long a,b,total=0;
    	if(n < 3){
    		if(n == 1){scanf("%lld",&a);printf("%lld\n",total);}
    		else{scanf("%lld %lld",&a,&b);printf("%lld\n",(b-a-1));}
		}else{
			vector<long long> piso;
			long long totaIzq,totalDer,mitad,cambio;
			//Read the data
	        for (long long i = n,num; i--; scanf("%lld",&num),piso.push_back(num));

	        for (int i = 0; i < n/2; ++i)
	        	{
	        		//Current distance minus their desired distance.
	        		total += piso[n-1-i]-piso[i]-(n-2*i-1);
	        	}	
	        printf("%lld\n",total);
		}


    }
    return 0;
}

