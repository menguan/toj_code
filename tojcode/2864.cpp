#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int t;int n;
int a,b;
int head[1010];
int vis1[1010];
int vis2[1010];
int match[1010];
int dep[1010];
int enu;
struct Edge
{
       int v,next;
}edge[3000];
void addedge(int u,int v)
{
     edge[enu].v=v;
     edge[enu].next=head[u];
     head[u]=enu++;
}
void dfs(int u,int depth)
{
     dep[u]=depth;
     //cout<<depth<<endl;
     for(int i=head[u];i!=-1;i=edge[i].next)
     {
            int v=edge[i].v;
            dfs(v,depth+1);
     }
}
             
int main()
{
    cin>>t;int tmp;
    for(int cas=1;cas<=t;cas++)
    {
       cin>>a>>b;  
       cin>>n;
       memset(head,-1,sizeof(head));
       //memset(match,-1,sizeof(match));
       memset(vis1,0,sizeof(vis1));
       memset(vis2,0,sizeof(vis2));
       enu=0;
       for(int i=1;i<n;i++)
       {
           cin>>tmp;
            addedge(tmp,i);
          // if(tmp)
           // addedge(i,0);
       }
       int ans=0;
       int sum1=0,sum2=0;
       int now=0;
       dfs(0,0);
       int even=0,odd=0;
       for(int i=0;i<n;i++)
       {
           if(dep[i]&1)
             odd++;
           else
             even++;
       }
       //cout<<odd<<" "<<even<<endl;
       ans=min(odd*a+even*b,even*a+odd*b);       
       cout<<"Scenario #"<<cas<<":"<<endl;
       cout<<ans<<endl<<endl;
    }
}  
                   
    
