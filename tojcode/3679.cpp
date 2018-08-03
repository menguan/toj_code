#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[110][2020];
int a[110];
int main()
{
     int t;int n;
    cin>>t;int cas=1;
    while(t--)
    {
            cin>>n;
            memset(dp,-1,sizeof(dp));
            //cout<<"Case "<<cas++<<": ";
            int sum=0;int ling=0;
            for(int i=1;i<=n;i++)
            {
                cin>>a[i];
                sum+=a[i];
                if(a[i]==0)
                  ling++;
            }
            cout<<"Case "<<cas++<<": ";
             dp[1][0]=0;
             dp[1][a[1]]=0;
             for(int i=2;i<=n;i++)
             {
                for(int j=0;j<=sum;j++)
                {
                    dp[i][j]=dp[i-1][j];
                    if(j>=a[i]&&dp[i-1][j-a[i]]!=-1)
                      dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]);
                    if(j<a[i]&&dp[i-1][a[i]-j]!=-1)
                      dp[i][j]=max(dp[i][j],dp[i-1][a[i]-j]+a[i]-j);
                    if(j+a[i]<=sum&&dp[i-1][a[i]+j]!=-1)
                      dp[i][j]=max(dp[i][j],dp[i-1][a[i]+j]+a[i]);
                }
             }
             if(dp[n][0]||(dp[n][0]==0&&ling>0))
             {
                  cout<<dp[n][0]<<endl;
             }
             else
               cout<<-1<<endl;
    }
}                                    
                        
                                  
                      
