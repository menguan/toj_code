#include<iostream>
using namespace std;
int dp[20]={0};
bool a[20]={0};

int main()
{
  dp[1]=0;
  dp[2]=1;
  for(int i=3;i<=12;i++)
    dp[i]=dp[i-1]*i+((i%2)?(-1):(1));
  int t,n;
  cin>>t;
  while(t--)
  {
    cin>>n;
    cout<<dp[n]<<endl;
  }  
}        
 