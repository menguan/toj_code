#include<cstdio>

#include<cstdlib>

#include<cmath>

#include<algorithm>

const double eps=1e-11;

using namespace std;

struct point

{

    double x, y;

} bub;

struct pipe

{

    point o;

    double r;

    double s, e;

} p[505];

int n;

double dist(point a, point b)

{

    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

}

inline void findint(int i)

{

    double di=dist(p[i].o, bub);

    double a=asin((p[i].r)/di);

    double b=asin((p[i].o.x-bub.x)/di);

    p[i].s=tan(b-a)*(bub.y)+bub.x;

    p[i].e=tan(b+a)*(bub.y)+bub.x;

}

bool cmp(pipe a, pipe b)

{

    if(fabs(a.s-b.s)<eps)return a.e<b.e;

    return a.s<b.s;

}

int main()

{

    int i;

    while(~scanf("%d", &n)&&n)

    {

        scanf("%lf%lf", &bub.x, &bub.y);

        for(i=0; i<n; i++)

        {

            scanf("%lf%lf%lf", &p[i].o.x, &p[i].o.y, &p[i].r);

            findint(i);

        }

        sort(p, p+n, cmp);

        double l, r;

        l=p[0].s;

        r=p[0].e;

        for(i=1; i<n; i++)

        {

            if(p[i].s>r)

            {

                printf("%.2lf %.2lf\n", l, r);

                l=p[i].s;

                r=p[i].e;

            }

            else r=r>p[i].e?r:p[i].e;

        }

        printf("%.2lf %.2lf\n\n", l, r);

    }

    return 0;

} 


 

//hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
