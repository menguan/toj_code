#include<iostream>
#include<algorithm>
using namespace std;
int maxn=1<<31-1;
int dp[110][110];
int a[110];
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int j=0;j<n;j++)
  for(int k=0;k<n;k++)  
  {  
     if(j==k)
     dp[j][k]=0;
     else
     dp[j][k]=maxn; 
  } 
  for(int i=1;i<n;i++)
  {
    for(int j=1,k=i+1;k<n;j++,k++)
    {
      
      for(int m=j;m<k;m++)
      {
         dp[j][k]=min(dp[j][k],dp[j][m]+dp[m+1][k]+a[j-1]*a[k]*a[m]);
      }
      
    }
  }
  cout<<dp[1][n-1]<<endl;       
             
  //while(1);
}  
  