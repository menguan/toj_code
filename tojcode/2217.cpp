#include<iostream>
#include<cstring>
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int inf=1212121212;
int n,m;int ans;
int zdis[1000010];
int fdis[1000010];
int t;
int zadj[1000010];int znum;
int fadj[1000010];int fnum;
bool zvis[1000010];
bool fvis[1000010];
struct f1
{
   int v,w,next;
}zedge[1000010];
struct f2
{
   int v,w,next;
}fedge[1000010];
void zadd(int st,int en,int le)
{
    zedge[znum].v=en;
    zedge[znum].w=le;
    zedge[znum].next=zadj[st];
    zadj[st]=znum;
    znum++;
}               
void fadd(int st,int en,int le)
{
    fedge[fnum].v=en;
    fedge[fnum].w=le;
    fedge[fnum].next=fadj[st];
    fadj[st]=fnum;
    fnum++;
} 
void zspfa()
{
     queue<int> q;
     zvis[1]=1;
     q.push(1);
     int temp;int now;
     while(!q.empty())
     {
        now=q.front();
        q.pop();
        zvis[now]=0;
        for(int i=zadj[now];i!=-1;i=zedge[i].next)
        {
             temp=zdis[zedge[i].v];
             zdis[zedge[i].v]=min(zdis[zedge[i].v],zdis[now]+zedge[i].w);
             if(temp>zdis[zedge[i].v])
             {
                if(!zvis[zedge[i].v])
                {
                   zvis[zedge[i].v]=1;
                   q.push(zedge[i].v);
                }
             }
        }
     }
}                                            
void fspfa()
{
     queue<int> q;
     fvis[1]=1;
     q.push(1);
     int temp;int now;
     while(!q.empty())
     {
        now=q.front();
        q.pop();
        fvis[now]=0;
        for(int i=fadj[now];i!=-1;i=fedge[i].next)
        {
             temp=fdis[fedge[i].v];
             fdis[fedge[i].v]=min(fdis[fedge[i].v],fdis[now]+fedge[i].w);
             if(temp>fdis[fedge[i].v])
             {
                if(!fvis[fedge[i].v])
                {
                   fvis[fedge[i].v]=1;
                   q.push(fedge[i].v);
                }
             }
        }
     }
}                
int main()
{     
   scanf("%d",&t);int s,e,cost;
   while(t--)
   {
      scanf("%d%d",&n,&m);
      memset(zadj,-1,sizeof(zadj));
      memset(fadj,-1,sizeof(fadj));
      memset(zvis,0,sizeof(zvis));
      memset(fvis,0,sizeof(fvis));
      znum=0;
      fnum=0;
      for(int i=0;i<=n;i++)
      {
         zdis[i]=inf;
         fdis[i]=inf;
      }
      zdis[1]=0;
      fdis[1]=0;
      for(int i=0;i<m;i++)
      {
           scanf("%d%d%d",&s,&e,&cost);
           zadd(s,e,cost);
           fadd(e,s,cost);
      }
      zspfa();
      fspfa();
      ans=0;
      for(int i=1;i<=n;i++)
      {
           ans+=zdis[i];
           ans+=fdis[i];
      }
      printf("%d\n",ans);
   }
}                                        
