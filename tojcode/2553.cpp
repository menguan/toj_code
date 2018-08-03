#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
using namespace std;
const int maxn=1010;
int c[maxn];
struct Node
{
      int a,b;
}node[maxn*maxn];
int N,M,K;
bool cmp(Node a,Node b)
{
     if(a.a==b.a)  return a.b<b.b;
     return a.a<b.a;
}
int lowbit(int x)
{return x&(-x);}
void add(int i,int val)
{
     while(i<=M)
     {c[i]+=val;
     i+=lowbit(i);
     }
}
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}   
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
         scanf("%d%d%d",&N,&M,&K);
         for(int i=1;i<=K;i++)
           scanf("%d%d",&node[i].a,&node[i].b);
         sort(node+1,node+1+K,cmp);
         memset(c,0,sizeof(c));
         long long ans=0;
         for(int i=1;i<=K;i++)
         {
             ans+=(sum(M)-sum(node[i].b));
             add(node[i].b,1);
         }
         printf("Test case %d: %lld\n",cas,ans);
    }
}
      
         
             

