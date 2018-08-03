#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
    {
      cin>>num[i];
    }
    int dp[n];
    for(int i=0;i<n;i++)
      dp[i]=1;
      
    for(int i=0;i<n;i++)
    {
       for(int j=i;j<n;j++)
       {
           if(num[j]>num[i]&&dp[j]<dp[i]+1)
             dp[j]=dp[i]+1;
       }
    }
    int hh=0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]>hh)
        hh=dp[i];
        
            }
    cout<<hh<<endl;
    
 }  