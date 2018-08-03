#include<iostream>
#include<algorithm>
using namespace std;
int dp[2000][2000];
int main()
{

    int a;
    cin>>a;
    while(a--)
    {
        int max=10000000;
        int city,road;
        cin>>city>>road;
        int start,end;
        cin>>start>>end;
        
        for(int i=1;i<=city;i++)
        {
          for(int j=1;j<=city;j++)
          {
            dp[i][j]=max;
          }
        }
        int st,en;
        for(int i=0;i<road;i++)
        {
           cin>>st>>en;
           int t;
           cin>>t;
           if(dp[st][en]>t) 
           dp[st][en]=dp[en][st]=t;
           
           
        }
        for(int k=1;k<=city;k++)
        {
          for(int i=1;i<=city;i++)
          {
            for(int j=1;j<=city;j++)
            {
              
                
                if( dp[i][k] + dp[k][j] < dp[i][j] &&i!=j)
                   dp[i][j]=dp[i][k]+dp[k][j];
              
            }    
          }
        }
        if(dp[start][end]<max)
        cout<<dp[start][end]<<endl;
        else 
        cout<<"-1"<<endl;
    }
}                  
      