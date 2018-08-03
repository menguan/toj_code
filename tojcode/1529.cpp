#include<iostream>
#include<stdio.h>
#include<cstring>
#define max 11
int edges[max][max];
int visited[max];
int N,M,x,y,count,flag;
void dfs(int pos,int step)
{
     if(flag)  return ;
     int j;
     if(step==N)
     {
       if(edges[pos][0]==1)
        { flag=1;
          return ;
          } 
     }
     for(j=1;j<=N;j++)
     if(edges[pos][j]==1&&!visited[j])
     {
         visited[j]=1;
         dfs(j,step+1);
         visited[j]=0;
     }
}    
                                      
                                      
int main()
{
    char a[1000];
    int k,i,ss=0;
    while(scanf("%d",&N)!=EOF&&N)
    {
        getchar();
        ss++;
        count=0;
        x=0;
        k=0;
        flag=0;
        M=N;
        memset(edges,0,sizeof(edges));
        memset(visited,0,sizeof(visited));
        while(M--)
        {
            x++;
            gets(a);
            int len=strlen(a);
            for(i=0;i<len;i++)
            {
               if(a[i]>='0'&&a[i]<='9')
               {
                 y=a[i]-'0';
                 edges[x][y]=edges[y][x]=1;
               }
            }
        }
        dfs(0,0);
         if(flag==1)
 printf("Case %d: Granny can make the circuit.\n",ss);
 else
 printf("Case %d: Granny can not make the circuit.\n",ss);
 }
 return 0;
 }
                          
