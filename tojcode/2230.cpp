#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int dp[30005],n,m,T,ans;
struct node
{
  int t,p,s;
  friend bool operator<(const node &a,const node &b)
  {
        return a.t<b.t;
  } 
}a[110];
int main()
{
   cin>>n>>m>>T;
   ans=0;
   memset(dp,0,sizeof(dp));
   for(int i=1;i<=n;i++)
     cin>>a[i].t;
   for(int i=1;i<=n;i++)
     cin>>a[i].p;
   for(int i=1;i<=n;i++)
     cin>>a[i].s;
   sort(a+1,a+n+1);
   for(int i=1;i<=n&&a[i].t<=T;i++)
   {
        if(a[i].s<=a[i].t&&a[i].s<=m)
        {
           for(int j=0;j<i;j++)
           {
              if(a[j].s<=m&&a[i].t-a[j].t>=abs(a[i].s-a[j].s))
                 dp[i]=max(dp[i],dp[j]+a[i].p);
              ans=max(ans,dp[i]);
           }
        }
   }
   cout<<ans<<endl;
   //while(1);
}                                              
           
