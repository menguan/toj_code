#include<stdio.h>
#define N 100
typedef double coo;
typedef struct POINT
{
    coo x,y;
}point,vector;
typedef struct POLYGON
{
    point p[N];/*顺时针或逆时针储存*/
    int n;/*n边形*/
}polygon;
double cross_product(vector p1,vector p2)
{/*x1y2-x2y1*/
    return p1.x*p2.y-p1.y*p2.x;
}
/*多边形的重心*/
point polygon_barycenter(polygon p)
{
    int i;
    point en={0,0};
    double s=0,ss=0;
    s=0;
    for(i=1;i<p.n;i++)
    {
        s=cross_product(p.p[i],p.p[i-1]);
        ss+=s;
        en.x+=(p.p[i].x+p.p[i-1].x)/3*s;
        en.y+=(p.p[i].y+p.p[i-1].y)/3*s;
    }
    s=cross_product(p.p[0],p.p[i-1]);
    ss+=s;
    en.x+=(p.p[0].x+p.p[i-1].x)/3*s;
    en.y+=(p.p[0].y+p.p[i-1].y)/3*s;
    en.x/=ss;
    en.y/=ss;
    return en;
}
int main()
{
    int t,i;
    polygon p;
    point c;
    int cas=1;
    while(scanf("%d",&t)&&t)
    {
        p.n=t;
        for(i=0;i<t;i++)
        {
            scanf("%lf%lf",&p.p[i].x,&p.p[i].y);
        }
        c=polygon_barycenter(p);
        printf("Stage #%d: %lf %lf\n",cas++,c.x,c.y);
    }
    return 0;
}
