#include<cstdio>//这种把价值当容量的dp要好好学学
#include<algorithm>
#include<string>
#include<climits>
using namespace std;
const int N = 100010;
int dp[N],k,n,m;
int cal(int x,int y)
{
    int num=(x+k-1)/k;
    if(x+y<=num*k)
        return x+y;
    return num*k+y;
}
int main()
{
    int a,b,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&n,&m,&k);
        for(int i=1;i<N;i++)
            dp[i]=INT_MAX;
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            a++;
            for(int j=N-1;j>=b;j--)
            {
                if(dp[j-b]!=INT_MAX)
                    dp[j]=min(dp[j],cal(dp[j-b],a));
            }
        }
        int ans=N-1,t=m*k;
        while(dp[ans]>t)
            ans--;
        printf("%d\n",ans);
    }
}
