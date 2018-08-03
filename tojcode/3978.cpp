#include<iostream>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
const double inf=101010101010.0;
double dp[1200][1200];
double p[1200][4];
int main()
{
    while(cin>>n>>m)
    {
        memset(dp,0,sizeof(dp));
        bool flag=1;
        for(int i=1;i<=n-1;i++)
        {
            cin>>p[i][0]>>p[i][1]>>p[i][2]>>p[i][3];
            /*
            if(fabs(p[i][0]-1)<0.00000001)
            {
                if(m==0)
                    flag=0;
            }*/
        }
        /*
        if(!flag)
        {
            cout<<"impossible"<<endl;
            continue;
        }*/
        for(int j=m;j>=0;j--)
        for(int i=n-1;i>=1;i--)
        {

                if(j==m)
                {
                    if(fabs(p[i][3]-1)<0.0000001) dp[i][j]=inf;
                    dp[i][j]=(dp[i+1][j]*p[i][1]+dp[i+2][j]*p[i][2]+1)/(1-p[i][0]);
                }
                else
                {
                    if(fabs(p[i][3]-1)<0.0000001)
                        dp[i][j]=1;
                    else if(fabs(p[i][0]-1)<0.0000001)
                    {
                        dp[i][j]=dp[i][j+1]*(1-p[i][3])+1;
                    }
                    else
                        dp[i][j]=min((dp[i+1][j]*p[i][1]+dp[i+2][j]*p[i][2]+1)/(1-p[i][0]),dp[1][j+1]*(1-p[i][3])+1);
                }

           //dp[i]=(dp[i+1]*p[i][1]+dp[i+2]*p[i][2]+1)/(1-p[i][0]);
          // cout<<dp[i]<<endl;
        }
        double ans=inf;
        for(int i=0;i<=m;i++)
        {
            //cout<<dp[1][i]<<endl;
            ans=min(ans,dp[1][i]);
        }
        if(ans>101010100)
        {
            puts("impossible");
        }
        else
            printf("%.1f\n",ans);
        //cout<<fixed<<setprecision(1)<<ans+0.05<<endl;
    }
}
ndl;
    }
}
