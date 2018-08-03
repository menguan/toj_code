#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[20];int n;
bool vis[20];
int dif;
int ans;
int st;
void dfs(int dep,int num)
{
    //cout<<dep<<" "<<num<<endl;
    if(dep==n)
    {
        if(abs(num-st)<=dif)
            ans++;
        return ;
    }
    for(int i=2;i<=n;i++)
    {
        if(vis[i]) continue;
        if(abs(a[i]-num)>dif) continue;
        vis[i]=1;
        dfs(dep+1,a[i]);
         vis[i]=0;
    }
    return ;
}
int main()
{
    while(scanf("%d%d",&n,&dif)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        ans=0;
memset(vis,0,sizeof(vis));
           st=a[1];

           dfs(1,a[1]);


        printf("%d\n",ans);
    }

}
