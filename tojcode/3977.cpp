#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
double dp[110];
double pro1[110];
double pro2[110];
double pro3[110];
int main()
{
  int n;
  while(cin>>n)
  {
    memset(dp,0,sizeof(dp));
    memset(pro1,0,sizeof(pro1));
    memset(pro2,0,sizeof(pro2));
    memset(pro3,0,sizeof(pro3));
    for(int i=1;i<n;i++)
    {
      cin>>pro1[i]>>pro2[i]>>pro3[i];
    }
    pro1[n]=1;
    dp[n]=0;
    for(int i=n-1;i>=1;i--)
    {
      dp[i]=(1+dp[i+1]*pro2[i]+dp[i+2]*pro3[i])/(1-pro1[i]);
        
    }
    cout<<setprecision(2)<<fixed<<dp[1]<<endl;
  }
}      
       