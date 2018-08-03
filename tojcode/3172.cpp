#include<iostream>
#include<stdio.h>
#include<cstring>
#define VM 150
#define EM 20550
#define inf 0x3f3f3f3f
using namespace std;
struct Edge
{
   int frm,to,cap,next;
}edge[EM];
int head[VM];
int dep[VM],ep,n;
void addedge(int cu,int cv,int cw)
{
    edge[ep].frm=cu;
    edge[ep].to=cv;
    edge[ep].cap=cw;
    edge[ep].next=head[cu];
    head[cu]=ep;
    ep++;
    edge[ep].frm=cv;
    edge[ep].to=cu;
    edge[ep].cap=0;
    edge[ep].next=head[cv];
    head[cv]=ep;
    ep++;
}
int BFS(int src,int des)
{
    int que[VM],i,front=0,rear=0;
    memset(dep,-1,sizeof(dep));
    que[rear++]=src;
    dep[src]=0;
    while(front!=rear)
    {
        int u=que[front++];
        front=front%VM;//这里竟然还用了一个循环队列
        for(i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap>0&&dep[v]==-1)
            {
              dep[v]=dep[u]+1;
              que[rear++]=v;
              rear=rear%VM;
              if(v==des)
               return 1;
            }
        }
    }
    return 0;
}       
int dinic(int src,int des)
{
    int i,res=0,top;
    int stack[VM];
    int cur[VM];
    while(BFS(src,des))
    {
       memcpy(cur,head,sizeof(head));
       int u=src;
       top=0;
       while(1)
       {
          if(u==des)
          {
               int minn=inf,loc;
               for(i=0;i<top;i++)
                 if(minn>edge[stack[i]].cap)
                 {
                    minn=edge[stack[i]].cap;
                    loc=i;
                 }
               for(i=0;i<top;i++)
               {
                  edge[stack[i]].cap-=minn;
                  edge[stack[i]^1].cap+=minn;
               }
               res+=minn;
               top=loc;
               u=edge[stack[top]].frm;
          }
          for(i=cur[u];i!=-1;cur[u]=i=edge[i].next)
            if(edge[i].cap!=0&&dep[u]+1==dep[edge[i].to])
               break;
          if(cur[u]!=-1)
          {
            stack[top++]=cur[u];
            u=edge[cur[u]].to;
          }
          else
          {
            if(top==0)
              break;
            dep[u]=-1;
            u=edge[stack[--top]].frm;
          }
       }  
    }
    return res;
}
int main()
{
    int np,nc,m,v1,v2,w;char g1,g2;
    int src,des;
    char str[30];
    while(scanf("%d",&n)!=EOF)
    {
       //cout<<"ll"<<endl;
       ep=0;
       src=0;
       des=25;
       memset(head,-1,sizeof(head));
       while(n--)
       {
           cin>>g1>>g2>>v1;
           //cout<<"kk"<<endl;
           addedge(g1-'A',g2-'A',v1);
       }      
       int ans=dinic(src,des);
       printf("%d\n",ans);
    }
    return 0;
}                                                            
                                                                                                                                                                                             
