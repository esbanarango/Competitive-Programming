/*
  SRM 537 - Div 2 Easy - KingXNewBaby
  TopCoder
  Esteban Arango Medina
*/

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class KingXNewBaby {
	public:
	string isValid(string name) {
		string vowels = "aeiou";
		if(name.size() != 8)
			return "NO";
		else{
			sort(name.begin(),name.end());
			int numVowels = 0;
			for (int i = 0; i < vowels.size(); ++i)
			{
				for (int j = 0; j < name.size(); ++j)
				{
					if(vowels[i]==name[j])
						numVowels++;
				}
			}
			if(numVowels != 2)
				return "NO";
			else
				for (int i = 0; i < name.size(); ++i)
				{
  					if (vowels.find(name[i])!=string::npos and name[i] == name[i+1]){
  						return "YES";
  					}
				}
			return "NO";
		}	
	}
};
