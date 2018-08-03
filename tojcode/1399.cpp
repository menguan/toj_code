#include<stdio.h>
#include<algorithm>
using namespace std;
int ans[1001];
void solve()
{
    int i,j,k;
    for(i=1;i<1001;i++)
      ans[i]=1000000000;
    for(i=1;i<1001;i++)
    {
        for(j=1;j<1001;j++)
        {
            if(i*j>1000)break;
            for(k=1;k<1001;k++)
            {
                if(i*j*k>1001)break;
                ans[i*j*k]=min(ans[i*j*k],(i*j+j*k+k*i)*2);
            }
        }
    }
}
int main()
{
    int n,t;
    solve();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
