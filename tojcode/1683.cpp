#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char a[3000];
char b[3000];
int dp[3000][3000];
int main()
{
   while(cin>>a>>b)
   {
     int la=strlen(a);
     int lb=strlen(b);
     for(int i=0;i<=la;i++)
     {
       for(int j=0;j<=lb;j++)
       {
       dp[i][j]=0;
       }
     }
     
        
     
        
     for(int i=0;i<la;i++)
     {
       for(int j=0;j<lb;j++)
       {
           if(a[i]==b[j])
             {dp[i+1][j+1]=dp[i][j]+1;
              
             } 
              
           else
             {dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
             
             } 
       }
     }
     cout<<dp[la][lb]<<endl;
   }
} 