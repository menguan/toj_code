#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int m,n,t;int q;
long long a[100010];
int dp[10010];
int main()
{
    cin>>t;
    while(t--)
    {
              cin>>n;
              memset(dp,0,sizeof(dp));
              int sum=0;
              for(int i=0;i<n;i++)
                {cin>>a[i];dp[a[i]]++;}
              //sort(a,a+n);
              cin>>q;
              while(q--)
              {
                cin>>m;
                if(m>2000){cout<<0<<endl;continue;}
                int ans=0;
                for(int i=0;i<=m;i++)
                {
                   if(i*2==m) ans+=dp[i]*(dp[i]-1);
                   else
                   ans+=dp[i]*dp[m-i];
                }
                cout<<ans<<endl;     
              } 
    }         
    
}
