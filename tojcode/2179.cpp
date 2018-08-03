#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct f
{
       int a,b;
}t[21000];
bool cmp(f mm,f nn)
{
    if(mm.a==nn.a)
      return mm.b<nn.b;
    return mm.a<nn.a;
}   
int ans[21000];
int main()
{
    memset(ans,-1,sizeof(ans));int ret=0;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       scanf("%d%d",&t[i].a,&t[i].b);  
    }
    sort(t,t+n,cmp);
    int i,j;
    for(i=0;i<n;i++)
    {
       for(j=0;j<ret;j++)
       {
           if(ans[j]<=t[i].a)
           {
               ans[j]=t[i].b;
               break;
           }         
       }
       if(j==ret)
       {
          ans[ret++]=t[i].b;
       }
    }
    printf("%d\n",ret);
    //while(1);
}               
    
