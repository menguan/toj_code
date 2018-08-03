#include<iostream>//深搜 
#include<cstring>
#include<algorithm>
#include<string>
#include<cstdio>

using namespace std;

int dep,n;
int a[20];

bool dfs(int cnt,int maxs)
{
    if(a[cnt]==n) return 1;
    if(cnt>=dep) return 0;
    if(maxs>n && a[cnt]>n) return 0;
    maxs=max(maxs,a[cnt]);
    if(maxs*(1<<(dep-cnt))<n) return 0;
    for(int i=0;i<=cnt;i++)
    {
        a[cnt+1]=a[cnt]+a[i];
        if(dfs(cnt+1,maxs)) return 1;
        if(a[cnt]>a[i]) a[cnt+1]=a[cnt]-a[i];
        else a[cnt+1]=a[i]-a[cnt];
        if(dfs(cnt+1,maxs)) return 1;
    }
    return 0;
}

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        if(n==1) printf("0\n");
        else
        {
            a[0]=1;
            for(dep=1;1;dep++)
            {
                if(dfs(0,1))
                {
                    printf("%d\n",dep);
                    break;
                }
            }
        }
    }
    return 0;
}
