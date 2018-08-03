#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[10010];
struct f
{
       int s,w;
}a[1000];
int main()
{
      int t;int n,m;
      cin>>t;
      while(t--)
      {
         cin>>n>>m;
         for(int i=0;i<=1010;i++)
         {
              dp[i]=100000;
         }
         
         int sum=0;int temp=0;
         
         for(int i=0;i<n;i++)
         {     
            cin>>a[i].s>>a[i].w;
            sum+=a[i].w;
            
         }
         for(int i=0;i<n;i++)
         {
              for(int j=m;j>=0;j--)
              {
                    if(j<=a[i].s)
                      dp[j]=min(dp[j],a[i].w);
                    else  
                    dp[j]=min(dp[j],dp[j-a[i].s]+a[i].w);
              }
         }  int i;
         if(dp[m]<100000)
           cout<<sum-dp[m]<<endl;     
         else
           cout<<"JUMP DOWN!"<<endl;
    }
}       
                
                           
                   
                           
      
