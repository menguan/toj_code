#include<stdio.h>
#include<cstring>
const int mod=5000011;
int dp[100010]; 
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
   	dp[0]=1;
	for (int i=1;i<=n;i++)
    {
		if(i<k+1)dp[i%(k+1)]=1;
		dp[i%(k+1)]=(dp[i%(k+1)]+dp[(i+k)%(k+1)])%mod;
	}
	printf("%d\n", dp[n%(k+1)]);
	//while(1);
}
