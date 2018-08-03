#include<stdio.h>
#include<string.h>
#define clr(x)memset(x,0,sizeof(x))
int g[18][18];
long long dp[1<<18];
int n;
long long c_c(int s)
{
    long long res=dp[s];
    if(res>=0)
        return res;
    int i,j;
    for(i=0;i<n;i++)        
        if(s&(1<<i))
            for(j=0;j<n;j++)
                if(g[j][i]&&!(s&(1<<j)))
                    return dp[s]=0;
    dp[s]=0;
    for(j=s;j;j^=i)
    {
        i=j&-j;
        dp[s]+=c_c(s^i);
    }
    return dp[s];
}
int main()
{
    int flag,m,a,b,i,j,k,st,stat;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        flag=0;
        clr(g);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            g[a-1][b-1]=1;
        }
        for(k=0;k<n;k++)
            for(i=0;i<n;i++)
                if(g[i][k])
                for(j=0;j<n;j++)
                    g[i][j]=g[i][j]||(g[i][k]&&g[k][j]);
        for(i=0;i<n;i++)
            if(g[i][i])
                break;
        if(i<n)
        {
            printf("0\n");
            continue;
        }
        st=(1<<n)-1; 
        memset(dp,0xff,sizeof(dp));
        dp[0]=1;
        printf("%lld\n",c_c(st));
    }
    return 0;
}
