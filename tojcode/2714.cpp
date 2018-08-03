#include<iostream>
#include<iomanip>
using namespace std;
double dp[1010][1010];
int main()
{
  int n,s;
  cin>>n>>s;
  dp[n][s]=0;
  for(int i=n;i>=0;i--)
  {
    for(int j=s;j>=0;j--)
    {
      if(i==n&&j==s)
        continue;
      dp[i][j]=(n*s+(n-i)*1.0*j*dp[i+1][j]+i*1.0*(s-j)*dp[i][j+1]+(n-i)*1.0*(s-j)*dp[i+1][j+1])/(n*s*1.0-i*j) ;
    }
  }
  cout<<setprecision(4)<<fixed<<dp[0][0]<<endl;
  //while(1);
}        