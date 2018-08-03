#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int used[500];
int a[500][100];
int c[100];
int d[100];
int main()
{
    int i,j,len;
    memset(used,0,sizeof(used));
    memset(a,0,sizeof(a));
    memset(c,0,sizeof(c));
    for(i=2;i*i<500;i++)
    {
       if(used[i]==0)
       for(j=i+i;j<500;j+=i)
         used[j]=1;
    }
    j=1;
    for(i=2;i<500;i++)
      if(!used[i])
        c[j++]=i;
    len=j;
    int m,n,num,flag=0;
    for(i=499;i>=2;i--)
    {
      num=i;
      for(j=1;j<len;j++)
      {
         while(num%c[j]==0)
         {
            a[i][j]++;
            num/=c[j];
         }
         if(num==1)
           break;
      }
    }
    for(i=3;i<500;i++)
    {
      for(j=1;j<len;j++)
      {
       a[i][j]+=a[i-1][j];
      }
    }
    while(~scanf("%d%d",&m,&n))
    {
       memset(d,0,sizeof(d));
       for(i=1;i<len;i++)
       {
         d[i]=a[m][i]-a[m-n][i]-a[n][i];
       }
       long long sum=1;
       for(i=1;i<len;i++)
       {
        if(d[i]!=0)
          sum*=d[i]+1;
       }
       printf("%lld\n",sum);
    }
}                                                                                                                                                    
                           
                        
    
