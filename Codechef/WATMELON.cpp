#include <iostream>
using namespace std;

int main() {
	// your code goes here
    int t,i;
    cin>>t;
    while(t--)
    {
        int n,x;
        int sum=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>x;
            sum+=x;
        }
        if(sum>=0)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
	return 0;
}
