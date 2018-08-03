#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;
int t,n;long long d;
int a[40];int cnt;
int ans;
bool vis[40];
map<long long,int> mapp;
map<long long,int> ::iterator it;  
void dfs(int pos,long long sum,int now,int stop)
{
    // cout<<pos<<" "<<sum<<" "<<now<<endl;
    // system("pause");
     if(sum>d)
       return ;
     it=mapp.find(sum);
     if(it==mapp.end())  
     mapp[sum]=now;
     else
     {
         if(mapp[sum]==-1||mapp[sum]!=now)
           mapp[sum]=-1;
     }        
     //if(cnt==2)
      // return ;
     //if(sum==d)
     //{
        
       // ans=now;  
       // cnt++;
       // return ;
     //}       
     if(pos==stop)
     {
         return ;
     }
     dfs(pos+1,sum,now,stop);
     dfs(pos+1,sum+a[pos],now+1,stop);
} 
void dfs2(int pos,long long sum,int now,int stop)
{
     //cout<<pos<<" "<<sum<<" "<<now<<" cnt "<<cnt<<endl;
    // system("pause");
    // cout<<"kk"<<pos<<" "<<sum<<" "<<now<<" "<<stop<<endl;
    if(cnt==2)
       return ;
     if(sum>d)
       return ;
     it=mapp.find(d-sum);
     if(it!=mapp.end())  
     {        
        if(mapp[d-sum]==-1)
        {cnt=2;}
        else if(ans==-1)
        {
           ans=now+mapp[d-sum];
          cnt=1;
        }
        else if(ans!=now+mapp[d-sum])
        {
           cnt=2;
        }
     }                  
     if(pos==stop)
     {
         return ;
     }
     //if(sum==d)
     //{
        
       // ans=now;  
       // cnt++;
       // return ;
     //}       
     
     dfs2(pos+1,sum,now,stop);
     dfs2(pos+1,sum+a[pos],now+1,stop);
}                  
int main()
{
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
         scanf("%d%lld",&n,&d);
         for(int i=0;i<40;i++)
           vis[i]=0;
         for(int i=0;i<n;i++)
         {
            scanf("%d",&a[i]);
         }
         mapp.clear();
         int hal=n/2;
         ans=-1;cnt=0;
         
         dfs(0,0,0,hal+1);
         dfs2(hal+1,0,0,n);
         printf("Case #%d: ",cas);
         if(cnt==0)
           puts("IMPOSSIBLE");
         else if(cnt==1)
           printf("%d\n",ans);
         else
           puts("AMBIGIOUS");
    }
}    
                 
