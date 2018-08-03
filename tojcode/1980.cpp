#include<iostream>
#include<cstring>
using namespace std;
long long dp[19][201];//前面表示位数 后面表示特定逆序数个数 
int main()
{
   memset(dp,0,sizeof(dp));
   dp[1][0]=1;
   dp[2][0]=1;
   dp[2][1]=1;
   
   for(int i=3;i<19;i++)
   {
     for(int j=0;j<=i*(i-1)/2;j++)
     {
         for(int k=0;k<i;k++)  
           dp[i][j]+=(dp[i-1][j-k]);
     }
   }
   //cout<<dp[4][2]<<endl;
  int n,k;
  while(cin>>n>>k&&(n+k))
  {
     cout<<dp[n][k]<<endl;
  }
}             

            
                    
   
      
