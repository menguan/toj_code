#include<iostream>//照打 
#include<algorithm>
#include<cstdio>
using namespace std;
const long long int inf=10000000000000;
const int maxn=10002;
const int maxm=5000000;
int t,l,ll;
long long d[maxn],s[maxm],a,b;
void dfs(long long p,int step)
{
    if(step>12) return;
    d[l++]=p*10+4;
    d[l++]=p*10+7;
    dfs(p*10+4,step+1);
    dfs(p*10+7,step+1);
}
void dfs1(long long p,int step)
{
    if(step>=l)return;
    if(d[step]>inf/p) return;
    dfs1(p,step+1);
    while(d[step]<=inf/p)
    {
        p*=d[step];
        s[ll++]=p;
        dfs1(p,step+1);
    }
}
int main()
{
    l=0,s[ll=1]=0;
    dfs(0,1);
    sort(d,d+l);
    dfs1(1,0);
    sort(s,s+ll);
    int len=unique(s,s+ll)-s;
     cin>>t;
    while(t--)
    {
        cin>>a>>b;
        int id1=upper_bound(s,s+len,a-1)-s;
        int id2=upper_bound(s,s+len,b)-s;
        cout<<id2-id1<<endl;
    }
    return 0;
}
