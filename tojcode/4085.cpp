#include<iostream>
using namespace std;
long long dp[110000];
int main()
{
    int con=1;
    int t;
    cin>>t;int n,p;
    while(t--)
    {
      cin>>n>>p;
      cout<<"Case #"<<con++<<": ";
      dp[1]=p;
      dp[0]=0;
      for(int i=2;i<=n;i++)
      {
            dp[i]=p*(dp[i-1]+1)%1000000007;
      }
      cout<<dp[n]<<endl;
    }
}        