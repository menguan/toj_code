#include<iostream>
#include<cstring>>
#include<algorithm>
#include<stdio.h>
#include<cmath>
using namespace std;
const int N=205;
const double inf=100000000;
int n,m;
double dp[N][N];
double w[N][N];
int x[N];
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",x+i);
		}
		memset(dp,0,sizeof(dp));
	memset(w,0,sizeof(w));
	for(int i=1;i<=n;i++)
		for(int j=i+2;j<=n;j++)
		{
			for(int k=i+1;k<=j;k++)
			{
				double tmp=x[i]+(x[j]-x[i])*(k-i)*1.0/(j-i);
				w[i][j]+=fabs(tmp-x[k]);
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=inf;
		}
	dp[1][1]=0;
	for(int i=2;i<n;i++)
		for(int j=2;j<m&&j<=i;j++)
		{
			for(int k=1;k<=i-1;k++)
			{
				dp[i][j]=min(dp[i][j],w[k][i]+dp[k][j-1]);
			}
		}
	for(int k=1;k<=n-1;k++)
		dp[n][m]=min(dp[n][m],w[k][n]+dp[k][m-1]);
	printf("%.4lf\n",dp[n][m]/n);
	}
	return 0;
}
