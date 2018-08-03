#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m;
//int p[600],q[600],v[600];
struct  f
{
  int p,q,v;
  friend bool operator <(const f &aa,const f &bb)
  {
    return aa.q-aa.p<bb.q-bb.p;
  }
}a[600];
int dp[6000];
int main()
{
  while(scanf("%d%d",&n,&m)!=EOF)
  {
    for(int i=0;i<n;i++)
    {
      scanf("%d%d%d",&a[i].p,&a[i].q,&a[i].v);
    }
    memset(dp,0,sizeof(dp));
    //dp[0]=0;
    /*
    for(int i=0;i<n;i++)
    {
      for(int j=m;j>q[i]&&j>=n-p[i];j--)
      {
        if(dp[j-p[i]]!=-1)
        {
          
          dp[j]=max(dp[j],dp[j-p[i]]+v[i]);
          cout<<j<<" "<<dp[j]<<endl;
        }
      }
    }
    */
    sort(a,a+n);
    
    for(int i=0;i<n;i++)
    {
      for(int j=m;j>=a[i].q;j--)
      {
        dp[j]=max(dp[j],dp[j-a[i].p]+a[i].v);
      }
    }
    printf("%d\n",dp[m]);
  }
}
        
    
    