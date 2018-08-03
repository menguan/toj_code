#include<cstdio>//看了一个小时 终于融会贯通
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> tree[2600];
int maps[2600][2600];
int dp[2600];
int fat[2600];
int FA[2600];
int maxn,node,ans;
void input()
{
    int a,b,c;
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        tree[i].clear();
    }
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        tree[a].push_back(b);
        tree[b].push_back(a);
        maps[a][b]=maps[b][a]=c;
    }
}
void dfs(int now,int NOT,int fa,int num=0)
{
    if(fa==-1) node=now;
    for(int i=0;i<tree[now].size();i++)
    {
        int to=tree[now][i];
        if(to!=fa&&to!=NOT)
        {
            fat[to]=now;
            dp[to]=dp[now]+maps[now][to];
            dfs(to,NOT,now);
        }
    }
    if(dp[now]>maxn)
    {
        maxn=dp[now];
        node=now;
    }
}
int main()
{
    int cas,a,b,c;
    cin>>cas;
    int ca=1;
    while(cas--)
    {
        input();
        ans=0x3f3f3f3f;
        dfs(0,-1,-1);
        int aa=node;
        dfs(aa,-1,-1);
        int bb=node;
        for(int i=0;i<n;i++) FA[i]=fat[i];
        while(bb!=aa)
        {
            int i=bb;
            int l1,l2;
            int t1=0x3f3f3f3f,t2=0x3f3f3f3f;
            maxn=0;dp[i]=0;dfs(i,FA[bb],-1);int a=node;
            maxn=0;dp[a]=0;dfs(a,FA[bb],-1);int b=node;
            l1=maxn;
            if(a==b)
            {
                l1=0;
                t1=0;
            }
            else
            {
                while(b!=a)
                {
                    t1=min(t1,max(dp[b],maxn-dp[b]));
                    b=fat[b];
                }
            }
            maxn=0;dp[FA[bb]]=0;dfs(FA[bb],i,-1);a=node;
            maxn=0;dp[a]=0;dfs(a,i,-1);b=node;
            l2=maxn;
            if(a==b)
            {
                l2=0;
                t2=0;
            }
            else
            {
                while(b!=a)
                {
                    t2=min(t2,max(dp[b],maxn-dp[b]));
                    b=fat[b];
                }
            }
            ans=min( ans, max(max(l1,l2),t1+t2+maps[i][FA[bb]]) );
            bb=FA[bb];
        }
        printf("Case %d: %d\n",ca++,ans);
    }
    return 0;
}
