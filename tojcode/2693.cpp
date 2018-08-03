#include<iostream>
#include<algorithm>
#define inf 10000000;
using namespace std;
int dp[11][110][110];
int main()
{
	for(int i=1;i<=100;i++)
	for(int j=1;j<=100;j++)
	  dp[1][i][j]=(j-i+1)*(i+j)/2;
	for(int k=2;k<=10;k++)
	for(int j=100;j>=1;j--)
	for(int i=j;i>=1;i--)
	{
		  dp[k][i][j]=inf;
		  for(int t=i;t<=j;t++)
		  {
				dp[k][i][j]=min(dp[k][i][j],t+max(dp[k][t+1][j],dp[k-1][i][t-1]));
			}
		}
		
	int t;int n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cout<<dp[n][1][m]<<endl;
	}
}
		
