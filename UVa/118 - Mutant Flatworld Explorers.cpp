/*
  118 - Mutant Flatworld Explorers
  UVa Online Judge
  Esteban Arango Medina
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
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

int positionsX[4]= {-1,0,1,0};
int positionsY[4]= {0,1,0,-1};

string intToString(int i){

	string s;
	stringstream out;
	out << i;
	return out.str();
}

int main(){
	//freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
	string pointPosition = "WNES";
	map<string,char> moves;
	moves["ER"]='S';moves["EL"]='N';moves["SR"]='W';moves["SL"]='E';
	moves["WR"]='N';moves["WL"]='S';moves["NR"]='E';moves["NL"]='W';

	vector<string> prohibited;

	int r,c,x,y;
	scanf("%d %d",&r,&c);
	char ini;
	int p;

	while(scanf("%d %d %c",&x,&y,&ini) != EOF){
		string route;
		cin>>route;
		int size = route.size();
		bool lost = false;
		for (int i = 0; i < size; ++i)
		{
			char nxt = route[i];
			if(nxt=='F'){
				p=int(pointPosition.find(ini));
				int newX=x+positionsX[p];
				int newY=y+positionsY[p];

				string pProhibited =intToString(x);
				pProhibited +=intToString(y);
				if(!((newY>=0 && newY<=c) && (newX>=0 && newX<=r))){
					if(find(prohibited.begin(), prohibited.end(), pProhibited)==prohibited.end()){
						lost=true;
						prohibited.push_back(pProhibited);				
						break;
					}					
				}else{
					x=newX;
					y=newY;
				}

			}else{
				string nPos = "";
				nPos.push_back(ini);
				nPos.push_back(nxt);
				ini=moves[nPos];
			}
		}
		(lost)?printf("%d %d %c LOST\n",x,y,ini):printf("%d %d %c\n",x,y,ini);

	}



}