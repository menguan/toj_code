#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int n,m;
struct interval
{
    int a,b;
};
vector<interval> e;
bool cmp(interval a,interval b)
{
    if(a.a==b.a)return a.b<b.b;
    return a.a<b.a;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        e.clear();
        while(n--)
        {
            interval now;
            scanf("%d%d",&now.a,&now.b);
            e.push_back(now);
        }
        sort(e.begin(),e.end(),cmp);
        int k=0;
        for(int i=0;i<e.size();i++)//去掉能直接覆盖别的区间的区间
        {
            bool flag=0;
            for(int j=i+1;j<e.size();j++)
            {
                if(e[j].a>=e[i].a&&e[j].b<=e[i].b)
                {
                    flag=1;break;
                }
                if(e[j].a>=e[i].b)break;
            }
            if(!flag)e[k++]=e[i];

        }
        n=k;
        int a,b;
        while(m--)
        {
            scanf("%d%d",&a,&b);
            int ans=0,i=0;
            while(e[i].a<a&&i<n)i++;
            while(i<n)
            {
                if(e[i].a>=a&&e[i].b<=b)
                {
                    ans++;
                    a=e[i].b;
                }
                i++;
            }
            printf("%d\n",ans);
        }
    }
}
