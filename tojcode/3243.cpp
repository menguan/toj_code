#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int t;
int n,m,k,x,y,z;
int c[100010];
int cc[100010];
int b[100010];
int p(int x)
{
    return x&(-x);
}
void modify1(int x,int s)
{
     while(x<=100000)
     {
         cc[x]+=s;
         x+=p(x);
     }
}
int getsum(int x)
{
    int sum=0;
    while(x)
    {
         sum+=c[x];
         x-=p(x);
    }
    return sum;
}
void modify(int x,int s)
{
     while(x<=n)
     {
           c[x]+=s;
           x+=p(x);
     }
}
int main()
{
    for(int i=0;i<=100000;i++)cc[i]=0;
    for(int i=1;i<=100000;i++)  modify1(i,1);
    //cin>>t;
    scanf("%d",&t);
    while(t--)
    {
          //cin>>n>>m;
          scanf("%d%d",&n,&m);
          c[0]=0;
          for(int i=1;i<=n;i++)
          {
             c[i]=cc[i];
             b[i]=1;
          }
          while(m--)
          {
             //cin>>k;
             scanf("%d",&k);
             if(k)
             {
                  //cin>>x>>y;
                  scanf("%d%d",&x,&y);
                  if(x>y)
                  {
                       int tmp=x;
                       x=y;y=tmp;
                  }
                  if(getsum(y-1)-getsum(x-1)==y-x) puts("1");// cout<<1<<endl;
                  else
                  {
                      if(getsum(n)-getsum(y-1)+getsum(x-1)==n-(y-x)) puts("1");// cout<<1<<endl;
                      else
                        puts("0");//cout<<0<<endl;
                  }                           
             }
             else
             {
                 //cin>>z;
                 scanf("%d",&z);
                 if(b[z])  modify(z,-1);
                 else modify(z,1);
                 b[z]=!b[z];
             }
          }
    }
}    
                        
