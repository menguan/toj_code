#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,m;
long long prime[110000][30];
long long yz[110000];
void init()
{
    memset(yz,0,sizeof(yz));
    for(int i=2;i<=100000;i++)
    {
        if(yz[i])continue;
        prime[i][0]=i;
        yz[i]=1;
        for(int j=2;j*i<=100000;j++)
            prime[i*j][yz[i*j]++]=i;
    }
}
long long dfs(int now,long long n,int pos)
{
    long long ret=0;
    for(int i=pos;i<yz[now];i++)
    {
        ret+=n/prime[now][i]-dfs(now,n/prime[now][i],i+1);
    }
    return ret;
}
int main()
{
    init();
    int t;

    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        long long ans=n;
        for(int i=2;i<=m;i++)
            ans+=n-dfs(i,n,0);
        cout<<ans<<endl;
    }
}
