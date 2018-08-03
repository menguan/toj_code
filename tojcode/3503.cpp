#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int k[10000];
int main()
{
	int a;
	cin>>a;
	while(a--)
	{
		int b,t;
		cin>>b;
		memset(k,0,sizeof(k));
		while(b--)
		{
			cin>>t;
			k[t]++;
	    }
	    sort(k,k+10000);
	    cout<<k[9999]<<endl;
    }
    return 0;
}  