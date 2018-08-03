#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<cstring>
#include<string>
using namespace std;
int dp[1010][1010];
//char s1[1010];
//char s2[1010];
string s1,s2;
int main()
{
    int l1,l2;
    while(cin>>l1)
    {
        if(l1==0)
        {
            cin>>l2;
            if(l2==0)
                cout<<0<<endl;
            else
            {

              cin>>s2;
            cout<<s2.length()<<endl;
            }
            continue;
        }
        cin>>s1>>l2;
        if(l2==0)
        {
            cout<<s1.length()<<endl;
            continue;
        }
        cin>>s2;
        for(int i=0;i<=l1;i++)
        for(int j=0;j<=l2;j++)
        dp[i][j]=0;
        for(int i=1;i<=l1;i++) dp[i][0]=i;
        for(int j=1;j<=l2;j++) dp[0][j]=j;
        for(int i=1;i<=l1;i++)
        for(int j=1;j<=l2;j++)
        {
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
        }

        cout<<dp[l1][l2]<<endl;
    }
}
