#include<iostream>
#include<stdio.h>
using namespace std;
int a[11000][110],b[11000];
int main()
{
    int n,m,i,j,t;
    scanf("%d%d",&n,&m);
    for(i=0;i<=n;i++)
      for(j=0;j<=m-1;j++)
        a[i][j]=0;//前面是位置 后面是模几时成立 
    a[0][0]=1;
    for(i=1;i<=n;i++)
    {
      scanf("%d",&b[i]);
      b[i]=b[i]%m;
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=m-1;j++)
          if (a[i-1][j]==1)
          {
                t=((j+b[i])%m+m)%m;
                a[i][t]=1;
                t=((j-b[i])%m+m)%m;
                a[i][t]=1;
          }
    }
    if (a[n][0]==1) printf("Divisible\n");
    else
    printf("Not divisible\n");
    //cin>>i;
    return 0;
}

    
