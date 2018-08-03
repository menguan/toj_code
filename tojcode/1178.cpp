#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>

using namespace std;

char maps[1000][1000];
int n;

void dfs(int n,int x,int y)
{
    if(n==1)
        maps[x][y]='X';
    else
    {
        if(n-1)
        {
            int size=1;
            for(int i=2;i<n;i++) size*=3;
            dfs(n-1,x,y);
            dfs(n-1,x+size*2,y);
            dfs(n-1,x,y+size*2);
            dfs(n-1,x+size,y+size);
            dfs(n-1,x+size*2,y+size*2);
        }
    }
}

int main()
{
    while(~scanf("%d",&n)&&n!=-1)
    {
        int size=1;
        for(int i=1;i<n;i++) size*=3;
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
                maps[i][j]=' ';
            maps[i][size]='\0';
        }
        dfs(n,0,0);
        for(int i=size-1;i>=0;i--)
        {
            for(int j=size-1;j>=0;j--)
             {
                if(maps[i][j]==' ')
                  maps[i][j]='\0';
                else
                break;  
                }
            
        }
        for(int i=0;i<size;i++)
            printf("%s\n",maps[i]);
        printf("-\n");
    }
    return 0;
}
