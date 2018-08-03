#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
long long dp[30];
int cnt[30];
char s[100010];
long long mod=1000000007;
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	long long ans;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		gets(s);
		ans=0;
		int tmp;
		int len=strlen(s);
		for(int i=0;i<len;i++)
		{
			tmp=s[i]-'A';
			if(dp[tmp]==0)
			{
				dp[tmp]=1;
				for(int j=0;j<26;j++)
				{
					if(j==tmp) continue;
					dp[tmp]=(dp[tmp]+dp[j])%mod;
				}
			}
			else
			{
			     for(int j=0;j<26;j++)
				{
					if(j==tmp) dp[tmp]=(dp[tmp]+1)%mod;
					else 
					dp[tmp]=(dp[tmp]+dp[j])%mod;
				}
			}
			cnt[tmp]++;
		}
		ans=1;
		for(int i=0;i<26;i++)
		{
			ans=(ans+mod+dp[i])%mod;
		}
		
		printf("%lld\n",ans);
	}
}	
					
