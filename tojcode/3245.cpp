#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
double dp[100100];
int a[100100];
int main()
{
    int t;
    cin>>t;
    int m,n;
    while(t--)
    {
       cin>>m>>n;
       for(int i=1;i<=m;i++)
         dp[i]=0;
       for(int i=1;i<=m;i++)
       {
           cin>>a[i];
       }
       a[0]=0;
       dp[m]=a[m];
       for(int i=m-1;i>=0;i--)
       {
           dp[i]=a[i];
           if(m-i<n)
           {
               for(int j=i+1;j<=m;j++)
                 dp[i]+=dp[j]*1/(m-i);
           }
           else
           for(int j=i+1,k=1;k<=n;j++,k++)
           {
              dp[i]+=dp[j]*1/n;
           }
       }     
       
       cout<<setprecision(1)<<fixed<<dp[0]<<endl;    
       }
}    
                              
            
