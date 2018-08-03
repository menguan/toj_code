#include<iostream>
#include<cstring>
using namespace std;
int dp[20][20];
int ka[20][20];
int x[20],y[20];
int n;
int dfs(int l,int r)
{
    if(dp[l][r]!=-1)  return dp[l][r];
    if(l==r)  return dp[l][r]=0;
    dp[l][r]=1010101010;
    for(int i=l;i<r;i++)
    {
       int temp=dfs(l,i)+dfs(i+1,r)+x[l]*y[i]*y[r];
       if(temp<dp[l][r])
       {
           dp[l][r]=temp;
           ka[l][r]=i;
       }
    }
    return dp[l][r];
} 
void print(int l,int r)
{
     if(l==r)
       cout<<"A"<<l+1;
     else
     {
       cout<<"(";
       print(l,ka[l][r]);
       cout<<" x ";
       print(ka[l][r]+1,r);
       cout<<")";
     }
}  
int main()
{
    int cas=1;
    while(cin>>n,n)
    {
         memset(dp,-1,sizeof(dp));
         for(int i=0;i<n;i++)
         {
           cin>>x[i]>>y[i];
         }
         dfs(0,n-1);
         cout<<"Case "<<cas++<<": ";
         print(0,n-1);
         cout<<endl;
    }
}      
         
                 
