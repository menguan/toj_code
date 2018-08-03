#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int tr[1000000];
int N;
int n,m;
int a[120000],b[120000],c[120000];
int g[400000];
inline int lowbit(int p)
{
    return p&(-p);
}
void seti(int p,int val)
{
    while(p<=N)
    {
        tr[p]+=val;
        p+=lowbit(p);
    }
}
int gsum(int p)
{
    int ret=0;
    while(p)
    {
        ret+=tr[p];
        p-=lowbit(p);
    }
    return ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            g[cnt++]=a[i];
            g[cnt++]=b[i];
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&c[i]);
            g[cnt++]=c[i];
        }
        sort(g,g+cnt);
        cnt=unique(g,g+cnt)-g;
        for(int i=0;i<=cnt+2;i++)tr[i]=0;
        N=cnt+3;
        for(int i=0;i<n;i++)
        {
            a[i]=lower_bound(g,g+cnt,a[i])-g;
            b[i]=lower_bound(g,g+cnt,b[i])-g;
            seti(a[i]+1,1);seti(b[i]+2,-1);

        }
        printf("Case #%d:\n",cas++);
        for(int i=0;i<m;i++)
        {
            c[i]=lower_bound(g,g+cnt,c[i])-g;
            printf("%d\n",gsum(c[i]+1));
        }


    }
}
