#include<iostream>
#include<algorithm>
int a[11]={0}; 
int dp[1010]={0}; 
using namespace std;
int main()
{ 
    int sum,n; 
    
    cin>>sum>>n; 
    for(int i=1;i<=n;i++) 
    { 
       cin>>a[i]; 
       dp[a[i]]=1; 
    }
    for(int i=1;i<=n;i++) 
    {
      for(int j=a[i];j<=sum;j++) 
      {
        if(dp[j-a[i]]) 
        {
        if(dp[j]) 
          dp[j]=min(dp[j],dp[j-a[i]]+1); 
        else 
          dp[j]=dp[j-a[i]]+1;
        }
      }      
    }   
    cout<<dp[sum]<<endl; 
    
    return 0;
}
