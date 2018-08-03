#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 100000+10;
int n,m;

struct Point{
    double x,y;
    Point(){};
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }

    Point operator - (const Point & B) const
    {
        return Point(x-B.x, y-B.y);
    }
}p[maxn], ch[maxn];

bool cmp(Point p1, Point p2)
{
    if(p1.x == p2.x) return p1.y < p2.y;
    return p1.x < p2.x;
}

double squarDist(Point A, Point B) /**距离的平方*/
{
    return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
}

double Cross(Point A, Point B) /**叉积*/
{
    return A.x*B.y-A.y*B.x;
}

void ConvexHull() /** 基于水平的Andrew算法求凸包 */
{
    sort(p,p+n,cmp); /**先按照 x 从小到大排序, 再按照 y 从小到大排序*/
    m = 0;

    for(int i = 0; i < n; i++) /** 从前往后找 */
    {
        while(m > 1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2; i >= 0; i--) /**从后往前找, 形成完整的封闭背包*/
    {
        while(m > k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    if(n > 1) m--;
}

int rotating_calipers() /**旋转卡壳模板*/
{
    int q = 1;
    double ans = 0;
    ch[m] = ch[0]; /**凸包边界处理*/
    for(int i = 0; i < m; i++) /**依次用叉积找出凸包每一条边对应的最高点*/
    {
        while(Cross(ch[i+1]-ch[i], ch[q+1]-ch[i]) > Cross(ch[i+1]-ch[i], ch[q]-ch[i]))
            q = (q+1)%m;
        ans = max(ans, max(squarDist(ch[i], ch[q]), squarDist(ch[i+1], ch[q+1])));
    }
    return ans;
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0) break;
        for(int i = 0; i < n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);

        ConvexHull();

        printf("%.2f\n",sqrt(1.0* rotating_calipers()));
    }
    return 0;
}
