#include<stdio.h>
#include<string.h>
char map[1005][1005];
int dp[1005][1005];
int main()
{
    int t,i,j;
	int r,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&r,&c);
		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
				scanf("%1s",&map[i][j]);
		memset(dp,0,sizeof(dp));
		for(i=1;i<=c;i++)
		{
			if(map[1][i]!='#')
			dp[1][i]=1;
			else break;
		}
		for(i=1;i<=r;i++)
		{
			if(map[i][1]!='#')
			dp[i][1]=1;
			else break;
		}
        for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
			{
				if(i-1>=1&&j-1>=1)
				{
					if(map[i][j-1]=='#')
						dp[i][j-1]=0;
					if(map[i-1][j]=='#')
						dp[i-1][j]=0;
					dp[i][j]=dp[i][j-1]+dp[i-1][j];
				}
			}
			printf("Existuje %d ruznych cest.\n",dp[r][c]);
	}
	return 0;
}
