#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#define  inf 0x0f0f0f0f

using namespace std;
const int maxn=100010;

int type[maxn],n,m;

bool jud(int x)
{
    int cut=0;
    for (int i=1;i<=m;i++)
    {
        if (cut==n) break;
        cut+=type[i]/x;
    }
    if (cut>=n){
        return 1;
    }
    return 0;
}

int find(int x,int y)
{
    while (x<y)
    {
        int mid=x+(y-x)/2;
        if (jud(mid)) x=mid+1;
        else y=mid;
    }
    return x-1;
}

int main()
{
    int x;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=1;i<=m;i++)
        {
            scanf("%d",&type[i]);
        }
        int ans=find(1,n+1);
        printf("%d\n",ans);
        int i=1;
        while(n)
        {
            while(type[i]>=ans && n)
            {
                printf("%d\n",i);
                n--;
                type[i]-=ans;
            }
            i++;
        }
    }
}
