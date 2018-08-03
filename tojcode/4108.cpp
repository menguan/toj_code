#include<iostream>
#include<cstring>
using namespace std;
int  dp[1000000];
int cost[1000000];
int aa[1000000];
int main()
{
  int n,m,a,b;
  int t;
  cin>>t;
  while(t--)
  {
            cin>>n>>m>>a>>b;
            int sum=0;int ss=0;
            for(int i=0;i<n+m;i++)
            {cin>>aa[i];sum+=aa[i];
              if(i>=n)ss+=aa[i];}
            memset(cost,-1,sizeof(cost));
            memset(dp,-1,sizeof(dp));
            dp[0]=1;
            for(int i=0;i<n+m;i++)
            {
                   for(int j=sum;j>=aa[i];j--)
                   {
                            if(dp[j-aa[i]]!=-1)
                            {
                                dp[j]=1;
                            }
                   }
            }
            int ans=0;
            for(int i=b;i<=a+b;i++)
            {
                if(dp[i]==1)
                {                   
                  ans=i;
                    break;
                }
            }
            if(sum-ans>=a||ss>=a)
              cout<<"wellplay"<<endl;
              else
               cout<<"wash your face"<<endl;

               }    
  
      
}
