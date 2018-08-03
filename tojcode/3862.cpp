#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n;int num[20][20];
int pos[20];long long ans;
bool vis[20];
int nixu()
{
    int temp=0;
    for(int i=1;i<=n;i++)
    {
       for(int j=i+1;j<=n;j++)
       {
          if(pos[i]>pos[j])
            temp++;
       }
    }
    return temp;
}         
void dfs(int step,int p,long long nu)
{
     pos[step]=p;
     if(step==n)
     {
      // cout<<"kk"<<nu<<endl;
       if(nixu()%2==1)
         ans-=nu;
       else
         ans+=nu;
       return ;
     }
     for(int i=1;i<=n;i++)
     {
        if(vis[i]==0)
        {
            vis[i]=1;
            dfs(step+1,i,nu*num[step+1][i]);
            vis[i]=0;
        }
     }
     return ;
}                                    
                
int main()
{
    while(cin>>n)
    {                        
       memset(vis,0,sizeof(vis));
       ans=0;
       for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
         cin>>num[i][j];
       for(int i=1;i<=n;i++)
       {
         vis[i]=1;
         dfs(1,i,num[1][i]);
         vis[i]=0;
       }
       cout<<ans<<endl;
    }
}     
         
         
                 
    
