#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[200010];
int num1[200010];
int num[200010];
int n,m;int tmp;int ans;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(num1,0,sizeof(num1));
        memset(num,0,sizeof(num));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
              scanf("%d",&num1[j]);
            }
            
            for(int j=1;j<=m;j++)
            {
				if(j-3>=1)
            dp[j]=num1[j]+max(dp[j-2],dp[j-3]);
            else if(j-2>=1)
                dp[j]=num1[j]+dp[j-2];
            else
                dp[j]=num1[j];
               // cout<<dp[j]<<endl;
            num[i]=max(num[i],dp[j]);
		    }
		    //cout<<num[i]<<endl;
        }
        ans=-1;
        for(int i=1;i<=n;i++)
        {
            if(i-3>=1)
            dp[i]=num[i]+max(dp[i-2],dp[i-3]);
            else if(i-2>=1)
                dp[i]=num[i]+dp[i-2];
            else
                dp[i]=num[i];
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }

}
