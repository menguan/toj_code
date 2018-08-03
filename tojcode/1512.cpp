#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int t;int now,y;int d;
int w[20];
int p[20];
int dp[1000001];
int main()
{
    cin>>t;
    
    while(t--)
    {
       cin>>now>>y;
       cin>>d;
       for(int i=0;i<d;i++)
       {
             cin>>w[i]>>p[i];
           w[i]/=1000;
           }
       while(y--)
       {
          int temp=now/1000;
          memset(dp,0,sizeof(dp));
          for(int i=0;i<d;i++)
          for(int j=w[i];j<=temp;j++)
          {
              dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
          }
          now+=dp[temp];
       }
       cout<<now<<endl;
    }
}                    
