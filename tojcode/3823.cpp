#include <iostream> 
#include <cstring>
using namespace std;//又得重写 
int s[1000010];
int dp[500010];
int main()
{

    int c,d,n;
    cin>>c;
    while(c--)
    {
       int re=0;
       memset(s,0,sizeof(s));
       memset(dp,0,sizeof(dp));
       cin>>d>>n;
       s[0]=1;
       int t;
       for(int i=1;i<=n;i++)
       {
           cin>>t;
           dp[i]=(t+dp[i-1])%d;
           re+=s[dp[i]]++;
       }
       cout<<re<<endl;
    }
    return 0;
}