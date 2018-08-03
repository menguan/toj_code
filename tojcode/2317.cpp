#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctype.h>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <deque>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
const double eps = 1e-9;
const double pi = 3.1415926535897932384626;
#define INF 1e18

const int MAXN = 1017;

struct point
{
    int x,y;
}e[MAXN],res[MAXN];

bool cmp(point a,point b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int cross(point a,point b,point c)
{
    return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}

double lenght(point a,point b)
{
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int convex(int n)
{
    sort(e,e+n,cmp);
    int m=0, i, k;
    for(i = 0; i < n; i++)
    {
        while(m>1 && cross(res[m-1],e[i],res[m-2])<=0)
            m--;
        res[m++]=e[i];
    }
    k = m;
    for(i = n-2; i >= 0; i--)
    {
        while(m>k && cross(res[m-1],e[i],res[m-2])<=0)
            m--;
        res[m++]=e[i];
    }
    if(n > 1)
        m--;
    return m;
}

int main()
{
    int t, n, m, L;


        scanf("%d%d",&n,&L);
        for(int i = 0; i < n; i++)
            scanf("%d%d",&e[i].x,&e[i].y);
        m = convex(n);
        double ans = 0;
        for(int i = 1; i < m; i++)
            ans+=lenght(res[i],res[i-1]);
        ans+=lenght(res[m-1],res[0]);
        ans+=2*pi*L;
        printf("%.0lf\n",ans);

    return 0;
}
