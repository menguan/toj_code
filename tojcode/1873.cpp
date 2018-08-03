#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1010][1010];
char s[1010];
int main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
            cin>>s;
            int len=strlen(s);
            memset(dp,0,sizeof(dp));
            for(int i=len-1;i>=0;i--)
            {
                 for(int j=i+1;j<len;j++)
                 {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=dp[i+1][j-1];
                    }
                    else
                    {
                        dp[i][j]=min(min(dp[i+1][j],dp[i][j-1]),dp[i+1][j-1])+1;
                    }
                 }
            }
            cout<<"Case "<<cas<<": "<<dp[0][len-1]<<endl;
    }
}                      
            
