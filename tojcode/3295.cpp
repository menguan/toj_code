#include<cstdio>//想麻烦了
#include<cstring>
const int MAXN=110;
int N;
int g[MAXN][MAXN];
int match[MAXN];
bool used[MAXN];
int a[10000],b[10000];
bool dfs(int u)
{
    int v;
    for(v=1;v<=N;v++)
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
            if(match[v]==-1||dfs(match[v]))
            {
                match[v]=u;
                return true;
            }
        }
    return false;
}
int hungary()
{
    int cnt=0;
    int u;
    memset(match,-1,sizeof(match));
    for(u=1;u<=N;u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u))  cnt++;
    }
    return cnt;
}
int main()
{
    int i,j,u,v;
    while(scanf("%d",&N)!=EOF)
    {
        for(i=1;i<=N;i++)
          for(j=1;j<=N;j++)
            scanf("%d",&g[i][j]);
        int ans=hungary();
        if(ans<N){printf("-1\n");continue;}
        int cnt=0;
        for(i=1;i<=N;i++)
        {
            for(j=i;j<=N;j++)
               if(match[j]==i) break;
            if(j!=i)
            {
                a[cnt]=i;b[cnt++]=j;
                int t=match[i];match[i]=match[j];match[j]=t;
            }
        }
        printf("%d\n",cnt);
        for(i=0;i<cnt;i++)
          printf("C %d %d\n",a[i],b[i]);

    }
    return 0;
}
