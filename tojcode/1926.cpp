#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

int match[700],N;
bool vis[700],map[700][700];

struct Node
{
    int r,c;
}node[700];

bool dfs(int n)
{
    int i,t;
    for(i=1;i<=N;i++)
    if(!vis[i]&&map[n][i])
    {
        vis[i]=true;
        t=match[i];
        match[i]=n;
        if(!t||dfs(t))
            return true;
        match[i]=t;
    }
    return false;
}

int main()
{
    int i,j,ans;

    while(~scanf("%d%d",&i,&j)&&(i>=0&&j>=0))
    {
        memset(map,0,sizeof(map));
        N=1;
        node[N].r=i,node[N].c=j;
        N++;
        while(~scanf("%d%d",&i,&j)&&(i&&j))
        {
            node[N].r=i,node[N].c=j;
            N++;
        }

        for(i=1;i<N;i++)
        {
            for(j=1;j<=N;j++)
            if(i-j&&node[j].c>=node[i].c&&node[j].r>=node[i].r)
                map[i][j]=true;
            match[i]=0;
        }

        for(i=1,ans=0;i<N;i++)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i))
                ans++;
        }
        printf("%d\n",N-1-ans);
    }
}
