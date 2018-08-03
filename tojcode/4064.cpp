#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<ctype.h>
using namespace std;
long long dp[1010];
char a[1010];
int T,n,s,t,w,c,len;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>s>>t;
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        w=c=-1;
        while(n)
        {
           cin>>a;
           if(isdigit(a[0])&&w==-1)
           {
               w=0;
               for(int i=0;i<strlen(a);i++)
               {
                   w*=10;
                   w+=a[i]-'0';
               }
           }
           else if(isdigit(a[0])&&w!=-1)
           {
               c=0;
               for(int i=0;i<strlen(a);i++)
               {
                   c*=10;
                   c+=a[i]-'0';
               }
               for(int i=t;i>=c;i--)
               {
                   if(dp[i-c]!=-1)
                   {
                       dp[i]=max(dp[i],dp[i-c]+w);
                   }
               }
               w=c=-1;
               n--;
           }

        }
        if(dp[t]>=s)
            cout<<"Final, I'm coming! "<<dp[t]<<endl;
        else
            cout<<"Where time goes by! "<<dp[t]<<endl;
    }
}
