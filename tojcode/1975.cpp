#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,x,y,ans[5100];
int y1,y2;
struct node
{
    int x,y;
}p[5100];
bool jud(int a)
{
    int x1=p[a].x-x,yy1=y1-y;
    int x2=p[a].y-x,yy2=y2-y;
    return x2*yy1-yy2*x1>0;
}
int main()
{
    int gg=0;
    while(scanf("%d",&n))
    {
        if(n==0)break;
        if(gg++) puts("");
        memset(ans,0,sizeof ans);
        scanf("%d%d%d%d%d",&m,&p[0].x,&y1,&p[n+1].x,&y2);
        p[0].y=p[0].x;
        p[n+1].y=p[n+1].x;
        int i,j;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        while(m--)
        {
            scanf("%d%d",&x,&y);
            for( i=1;i<=n;i++)
            {
                if(jud(i))
                break;
            }
            ans[i-1]++;
        }
        for(i=0;i<=n;i++)
        {
            printf("%d: %d\n",i,ans[i]);
        }
    }
}
