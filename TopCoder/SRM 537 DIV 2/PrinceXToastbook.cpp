/*
  SRM 537 - Div 2 Hard - PrinceXToastbook
  TopCoder
  Esteban Arango Medina
*/

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class PrinceXToastbook {
	public:
	double eat(vector <int> prerequisite) {
		int size = prerequisite.size(), numPer=0,sumaTotal=0;
		vector<int> possible;			//Vector with all the possible choices.
        for (int i = 0; i < size; ++i){possible.push_back(i);}   //Initialize it.
	    do {
	  	  numPer++;
	      vector<int> eaten;
	      for (int i = 0; i < size; ++i)
	      {
	        if(prerequisite[possible[i]] == -1)			//Check if it's -1 push it.
	          eaten.push_back(possible[i]);
	        else if(find(eaten.begin(), eaten.end(), prerequisite[possible[i]])!=eaten.end()) //Check if I've already eaten the book, if so push it too.
	          eaten.push_back(possible[i]);
	      }
	  	  sumaTotal += eaten.size();					//The number of books gained is equals to the size of the vector.
	    } while ( next_permutation (possible.begin(),possible.end()) );
	    double result = (float)sumaTotal/(float)numPer;
	    return result;
	}
};
