#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[9000][150];
int e[20][20];
int c[20][20];
int exp[20];
int n;
int t;
int dfs(int now,int num)
{
	 if(dp[now][num]!=-1) return dp[now][num];
	 dp[now][num]=0;
	 for(int i=0;i<n-1;i++)
	 {
			if((now&(1<<i))==0)
			{
				int next=(now|(1<<i));
				if(num>exp[i+1])
				  dp[now][num]=max(dp[now][num],dfs(next,num+e[0][i+1])+c[0][i+1]);
				else dp[now][num]=max(dp[now][num],dfs(next,num+e[0][i+1]));
			}
	 }
	 return dp[now][num];
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>e[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>c[i][j];
			}
		}
		for(int i=0;i<n;i++)
		  cin>>exp[i];
		dfs(0,exp[0]);
		cout<<dp[0][exp[0]]<<endl;
	}
}

