#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int ans[100010];
bool vis[100010];
void init()
{
     memset(ans,0,sizeof(ans));
     for(int i=1;i<100010;i++)
     {
         ans[i]=1;
         for(int j=2;j*j<=i;j++)
         {
               
               if(j*j==i)
               {
                  ans[i]+=j;
                  break;
               }    
               else if(i%j==0)
               {//cout<<i<<" "<<j<<" "<<ans[i]<<endl;
                  //cout<<i%j<<"kk"<<endl;
                  ans[i]+=j;
                  ans[i]+=(i/j);
                  
               }             
         }
     }
     ans[1]=0;
}
int main()
{
    int t;
    init();
   // while(cin>>t)
     // cout<<ans[t]<<endl;
     //cout<<ans[220]<<endl;
    cin>>t;
    int n;
    while(t--)
    {
           memset(vis,0,sizeof(vis));
           cin>>n;
           int ret=0;
           for(int i=1;i<=n;i++)
           {
               if(!vis[i]&&ans[i]<=100000&&ans[i]<=n)
                {
                       if(ans[ans[i]]==i)
                       {vis[ans[i]]=1;                     
                       ret++;}    }
           }
           cout<<ret<<endl;
    } 
    
}            
