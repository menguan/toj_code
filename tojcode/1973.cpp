#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int ans[10];
	char s[10];
	int len;
	memset(ans,0,sizeof(ans));
	while(cin>>s)
	{
		len=strlen(s);
		for(int i=0;i<len;i++)
		{
			ans[i]+=s[i]-'0';
			ans[i]=ans[i]%10;

		}
	}

	for(int i=0;i<len;i++)
	{
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}