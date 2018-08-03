#include<iostream>
#include<stdio.h>
#include<cstring>
#include<iomanip>
#include<string>
#include<queue>
#include<stack>
using namespace std;
int a[40][40];
int d[4][2]={-1,0,0,-1,1,0,0,1};
int e[2][8][2]={{{0,-1},{-1,0},{0,1},{1,0},{0,-1},{-1,0},{0,1},{1,0}},{{0,1},{-1,0},{0,-1},{1,0},{0,1},{-1,0},{0,-1},{1,0}}};
int n,m,x0,y0,x1,y1;
int Go(int k)
{
    int d,i,x,y,x2,y2,s=1;
    a[x1][y1]=2;
    d=0;
    x=x0;
    y=y0;
    while(a[x][y]==0)
      for(d=(d+3)%4,i=d;i<d+4;i++)
      {
        x2=x+e[k][i][0];
        y2=y+e[k][i][1];
        if(x2>=0&&y2>=0&&x2<n&&y2<m&&a[x2][y2]>=0)
        {
          x=x2;
          y=y2;
          d=i%4;
          s++;
          break;
        }
      }
    return s;
}                                                                                
                     
int bfs()
{
    int c[2000][2];
    int i,j,t0,t1,t2,t3,x,y;
    a[x1][y1]=0;
    c[0][0]=x0;
    c[0][1]=y0;
    a[x0][y0]=1;
    t1=0;
    t2=t3=1;
    t0=2;
    for(t1=0,t2=t3=1;t1<t2;t1=t2,t2=t3,t0++)
    {
      for(i=t1;i<t2;i++)
      {
        for(j=0;j<4;j++)
        {
           x=c[i][0]+d[j][0];
           y=c[i][1]+d[j][1];
           if(x>=0&&y>=0&&x<n&&y<m&&a[x][y]==0)
           {
              c[t3][0]=x;
              c[t3][1]=y;
              a[x][y]=t0;
              t3++;
           }
        }
        if(a[x1][y1]>0)  return a[x1][y1];
      }
    }    
    return 0;
}
int main()
{
    int n1;
    scanf("%d",&n1);
    for(;n1>0;n1--)
    {
       scanf("%d%d",&m,&n);
       char c;int i,j;
       for(i=0;i<n;i++)
       {
         for(getchar(),j=0;j<m;j++)
         {
            scanf("%c",&c);
            if(c=='#')  a[i][j]=-1;
            else
            {
                if(c=='S')
                  x0=i,y0=j;
                else if(c=='E')
                  x1=i,y1=j;
                a[i][j]=0;
            }
         }
       }
       printf("%d ",Go(0));        
       printf("%d ",Go(1));        
       printf("%d\n",bfs());
    }
}              
                                         
                                                                                                                 
