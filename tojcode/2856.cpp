#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
bool vis[1010];
long long x[1010];
long long y[1010];
long long dis(int a,int b,int c,int d)
{
     return (a-b)*(a-b)+(c-d)*(c-d);
}
int main()
{
    int n;long long temp;
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       scanf("%d%d",&x[i],&y[i]);
    }
    int pos;int out=0;
    while(out<n-1)
    for(int i=0;i<n;i++)
    {
        temp=1010110100;
        if(!vis[i])
        {
              for(int j=0;j<n;j++)
              {
                  if(i==j||vis[j])
                    continue;
                  if(temp>dis(x[i],x[j],y[i],y[j]))
                  {
                      temp=dis(x[i],x[j],y[i],y[j]);
                      pos=j;
                  }
              }
              vis[pos]=1;
              out++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
              cout<<i+1<<endl;
              break;
        }
    }
    //while(1);
}                                                             
