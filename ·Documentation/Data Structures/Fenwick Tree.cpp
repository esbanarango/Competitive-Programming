#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int get(vector<int> *tree,int i){
	int sum = 0;
	while(i>0){
		sum +=tree->at(i);
		i-=i&-i;
	}
	return sum;
}
void add(vector<int> *tree, int idx ,int val){
	while (idx < tree->size()){
		tree->at(idx) += val;
		idx += (idx & -idx);
	}
}

int main(){
	long long n;
	while(scanf("%lld",&n) && n != 0){
		vector <long long> inv;
		long long total=0;
		long long size=0;
		for (long long i = n,num; i--; scanf("%lld",&num),size=max(size,num),inv.push_back(num));
		vector<int> tree (size+1,0);
		for (int i = inv.size()-1; size > 0 && i >= 0 ; --i)
		{
			total += get(&tree,inv[i]-1);
			add(&tree,inv[i],1);
		}
	}	
    return 0;
}