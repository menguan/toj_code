#include<iostream>
#include<algorithm>
int a[5]={0,1,5,3,6}; 
int dp[200000]; 
using namespace std;
int main()
{

    int sum,t,count=1; 
    cin>>t;
    while(t--)
    {
    cin>>sum;
    for(int i=0;i<=sum;i++)
      dp[i]=0; 
    for(int i=1;i<=4;i++) 
    { 
        
       dp[a[i]]=1; 
    }
    
    for(int i=1;i<=4;i++) 
    {
      for(int j=a[i];j<=sum;j++) 
      {
        if(dp[j-a[i]]) 
        {
        
        if(dp[j])
        { 
          
          dp[j]=min(dp[j],dp[j-a[i]]+1);
        }   
        else 
          
          dp[j]=dp[j-a[i]]+1;
        }
      }      
    }   
    cout<<"Case "<<count++<<": "<<dp[sum]<<endl; 
    }
    return 0;
}
