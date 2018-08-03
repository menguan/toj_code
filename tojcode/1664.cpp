#include<iostream>
#include<cstring>
#include<stdio.h>
#include<string>
#include<queue>
using namespace std;
int n,m;
struct Edge
{
       int u,v;int w;
       int next;
}edge[200001];
bool vis[60000];
int head[60000];int cnt;
int st,en;
int dis[60000];
void addedge(int u,int v,int w)
{
     edge[cnt].v=v;
     edge[cnt].u=u;
     edge[cnt].w=w;
     edge[cnt].next=head[u];
     head[u]=cnt++;
}
int spfa()
{
    //memset(dis,0,sizeof(dis));
    for(int i=st;i<=en;i++)
      dis[i]=-1010101010;//这里的i一直写成st  找了半天错 
    dis[st]=0;
    memset(vis,0,sizeof(vis));
    vis[st]=1;
    queue<int>q;
    q.push(st);
    while(!q.empty())
    {
       int temp=q.front();
       //cout<<temp<<endl;
       vis[temp]=0;
       q.pop();
       for(int i=head[temp];i!=-1;i=edge[i].next)
       {
            //cout<<temp<<" "<<edge[i].v<<endl;
            //cout<<dis[edge[i].v]<<" "<<dis[temp]<<" "<<edge[i].w<<endl;
            if(dis[edge[i].v]<dis[temp]+edge[i].w)
            {
               //cout<<edge[i].v<<endl;
               dis[edge[i].v]=dis[temp]+edge[i].w;
               if(!vis[edge[i].v])
                 {
                      vis[edge[i].v]=1;
                      q.push(edge[i].v);
                 }
            }
       }
    }
    return  dis[en];
}                                                              
int main()
{
    int n;int a,b,c;
    while(cin>>n)
    {
        memset(head,-1,sizeof(head));
        cnt=0;
        st=700000;
        en=-700000;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b>>c;
            if(a<st)
              st=a;
            if(b+1>en)
              en=b+1;
            addedge(a,b+1,c);
        }
        for(int i=st;i<en;i++)
        {
           //cout<<"kk"<<endl;
           addedge(i,i+1,0);
           addedge(i+1,i,-1);
        }
        //for(int i=0;i<cnt;i++)
        //{
        //   cout<<edge[i].v<<" "<<edge[i].w<<" "<<edge[i].next<<endl;
        //}     
        cout<<spfa()<<endl;
    }
}                        
