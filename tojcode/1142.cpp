#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm> 
using namespace std;
bool flag[1000];
double dp[1000][1000];
double ans[1000];
struct f
{
  int x;int y;
  int id;
}a[1000];  
int main()
{
  int n;int cas=1;
  while(cin>>n,n)
  {
     memset(flag,0,sizeof(flag));
     memset(ans,0,sizeof(ans));
     for(int i=0;i<n;i++)
     {
       cin>>a[i].x>>a[i].y;
       a[i].id=i;
     }
     double temp1,temp2,temp3;
     for(int i=0;i<n;i++)
     {
       for(int j=0;j<n;j++)
       {
         dp[i][j]=dp[j][i]=hypot(a[i].x-a[j].x,a[i].y-a[j].y);
       }
     }    
     for(int i=0;i<n;i++)
     {
       for(int j=0;j<n;j++)
       {
         if(dp[j][i]>0)
         for(int k=0;k<n;k++)
         {
           if(dp[i][k]>0)
           if((dp[j][k]>dp[j][i]&&dp[j][k]>dp[i][k])&&j!=k)
           {
             dp[j][k]=max(dp[j][i],dp[i][k]);
           }
         }
       }
     }        
           
     cout<<"Scenario #"<<cas++<<endl<<"Frog Distance = ";
     cout<<setprecision(3)<<fixed<<dp[0][1]<<endl<<endl;
   }
 }               