#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[1000],visit[1000],sum,l,n;
int dfs(int x,int pos,int len)
{
    if(x == 3)
        return 1;
    int i;
    for(i = pos; i>=0; i--)
    {
        if(!visit[i])
        {
            visit[i] = 1;
            if(len+a[i]<l)
            {
                if(dfs(x,i-1,len+a[i]))
                    return 1;
            }
            else if(len+a[i]==l)
            {
                if(dfs(x+1,n-1,0))
                    return 1;
            }
            visit[i] = 0;
        }
    }
    return 0;
}

int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        sum = 0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }    
        l = sum/4;
        memset(visit,0,sizeof(visit));
        sort(a,a+n);
        if(l*4!=sum||n<4||l<a[n-1])
        {
            printf("no\n");
            continue;
        }
        if(dfs(0,n-1,0))
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
