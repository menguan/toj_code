#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int vis[1010];
int p[1010];
int cnt;
void getprime()
{
     memset(vis,0,sizeof(vis));
     memset(p,0,sizeof(p));
     cnt=0;
     for(int i=2;i<1010;i++)
     {
         if(!vis[i])
         {
            p[cnt++]=i;
            for(int j=i+i;j<1010;j+=i)
            {
                vis[j]=1;
            }       
         }
     }
}  
int f(int q)
{
    int ret=0;
    for(int i=0;i<cnt&&p[i]<=q;i++)
    {
       while(q%p[i]==0)
       {
           ret++;
           q/=p[i];
       }
    }
    return ret;
}                           
int main()
{
    int n,m;
    getprime();
    //memset(sg,-1,sizeof(sg));
   // sg[2][2]=sg[2][3]=sg[3][2]=0;
    //f(1000,1000);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(f(n)<=f(m))
          puts("Lose");
        else
          puts("Win");
    }
}                                
    
