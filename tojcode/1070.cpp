#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1<<16;
int n,m,k,len,cnt[maxn],ans[maxn];
void dfs(int v)
{
    while(cnt[v]<2)
    {
        int w=(v<<1)+cnt[v];
        cnt[v]++;
        dfs(w&m);
        ans[len++]=w;
    }
}
int main()
{
    while(cin>>n>>k&&(n+k))
    {
        len=0;
        memset(cnt,0,sizeof(cnt));
        m=(1<<(n-1))-1;
        dfs(0);
        while(k--)
            len--;
        cout<<ans[--len]<<endl;
    }
    return 0;
}
