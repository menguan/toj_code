#include<iostream>
#include<algorithm>
using namespace std;
int dp[2000][2000];
int main()
{

    int a;
    int end,road;
    while(cin>>end>>road)
    {
        if(end==0&&road==0)
          return 0;
        int max=10000000;
        
        int &city=end;
        int start=1;
        
        
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
        
        cout<<dp[start][end]<<endl;
        
    }
}  