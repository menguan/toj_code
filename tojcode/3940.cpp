#include <iostream>//只需要算有几个格子可以独立染色 然后求幂就好了
#include <cstdio>
#include <cstring>
#include <map>
#include <cstdlib>
#include <cmath>
using namespace std;
const int maxx = 10010;
long long power(long long a, int k,int m)
{
    long long b = 1;
    while(k>=1)
    {
        if(k%2==1)  b = b*a%m;
        a = a*a%m;
        k = k/2;
    }
    return b;
}

int main()
{
    int n,m,k;
    while(scanf("%d %d %d",&n,&m,&k)!=EOF)
    {
        map<int,bool> q;
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if(x>n-1-x) x=n-1-x;
            if(y>n-1-y) y=n-1-y;
            if(y<x)
            {
                int tem;
                tem = y;
                y = x;
                x = tem;
            }
            q[(x-1)*n+y] = true;
        }
        int N = (((n+1)/2 + 1)*((n+1)/2))/2;//
        int M = N - q.size();
        long long ans = power(k,M,100000007);
        printf("%lld\n",ans);
    }
    return 0;
}
