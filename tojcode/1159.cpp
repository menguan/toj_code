#include<stdio.h>//把牛拆点  限制牛和牛流量为一 保证一只牛只有一份食物 这种类型题搞通
#include<string.h>
#include<algorithm>
#include<string>
#include<map>
#include<iostream>
#define inf 1010101010
using namespace std;
const int MAXN=20010;//点数的最大值
const int MAXM=880010;//边数的最大值
const int INF=0x3f3f3f3f;

struct Node
{
    int from,to,next;
    int cap;
}edge[MAXM];
int tol;
int head[MAXN];
int dep[MAXN];
int gap[MAXN];
int n;

void init()
{
    tol=0;
    memset(head,-1,sizeof(head));
}

void addedge(int u,int v,int w)
{
    //cout<<u<<" "<<v<<" "<<w<<endl;
    edge[tol].from=u;
    edge[tol].to=v;
    edge[tol].cap=w;
    edge[tol].next=head[u];
    head[u]=tol++;
    edge[tol].from=v;
    edge[tol].to=u;
    edge[tol].cap=0;
    edge[tol].next=head[v];
    head[v]=tol++;
}
void BFS(int start,int end)
{
    memset(dep,-1,sizeof(dep));
    memset(gap,0,sizeof(gap));
    gap[0]=1;
    int que[MAXN];
    int front,rear;
    front=rear=0;
    dep[end]=0;
    que[rear++]=end;
    while(front!=rear)
    {
        int u=que[front++];
        if(front==MAXN)front=0;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dep[v]!=-1)continue;
            que[rear++]=v;
            if(rear==MAXN)rear=0;
            dep[v]=dep[u]+1;
            ++gap[dep[v]];
        }
    }
}
int SAP(int start,int end)
{
    int res=0;
    BFS(start,end);
    int cur[MAXN];
    int S[MAXN];
    int top=0;
    memcpy(cur,head,sizeof(head));
    int u=start;
    int i;
    while(dep[start]<n)
    {
        if(u==end)
        {
            int temp=INF;
            int inser;
            for(i=0;i<top;i++)
               if(temp>edge[S[i]].cap)
               {
                   temp=edge[S[i]].cap;
                   inser=i;
               }
            for(i=0;i<top;i++)
            {
                edge[S[i]].cap-=temp;
                edge[S[i]^1].cap+=temp;
            }
            res+=temp;
            top=inser;
            u=edge[S[top]].from;
        }
        if(u!=end&&gap[dep[u]-1]==0)//出现断层，无增广路
          break;
        for(i=cur[u];i!=-1;i=edge[i].next)
           if(edge[i].cap!=0&&dep[u]==dep[edge[i].to]+1)
             break;
        if(i!=-1)
        {
            cur[u]=i;
            S[top++]=i;
            u=edge[i].to;
        }
        else
        {
            int min=n;
            for(i=head[u];i!=-1;i=edge[i].next)
            {
                if(edge[i].cap==0)continue;
                if(min>dep[edge[i].to])
                {
                    min=dep[edge[i].to];
                    cur[u]=i;
                }
            }
            --gap[dep[u]];
            dep[u]=min+1;
            ++gap[dep[u]];
            if(u!=start)u=edge[S[--top]].from;
        }
    }
    return res;
}
int nam;
map<string,int> mapp;
map<string ,int>::iterator it;
int getnum(string s)
{
    for(it=mapp.begin();it!=mapp.end();it++)
    {
        if(s==it->first)
            return mapp[s];
    }
    return mapp[s]=nam++;
}

int main()
{

        mapp.clear();
        init();
        nam=2;
        int s=0,t=1,nn,m,k;

        int temp,temp2;
        string s1,s2;
        cin>>nn;
        for(int i=0;i<nn;i++)
        {
           cin>>s1;
           temp=getnum(s1);
           addedge(temp,t,1);
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>s1>>s2;
            temp=getnum(s1);
            temp2=getnum(s2);
            addedge(s,temp,1);
            addedge(temp,temp2,1);

        }
        cin>>k;
        for(int i=0;i<k;i++)
        {
            cin>>s1>>s2;
            temp=getnum(s1);
            temp2=getnum(s2);
            addedge(temp,temp2,1010101010);
        }
        n=nam;
        int ans=SAP(s,t);
        printf("%d\n",m-ans);

    return 0;
}

