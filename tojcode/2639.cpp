#include <iostream>//定长圆覆盖点 还是有现成的

#include <cstdio>

#include <cmath>

#include <algorithm>

#define Mn 300

using namespace std;

const double eps = 1e-9;

const double pi = acos(-1.0);

#define sqr(x) ((x) * (x))

double R;

/*
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#define pi acos(-1.0)
#define eps 0.000000001
struct Point
{
    double x,y;
    Point(){}
    Point(double tx,double ty){x=tx;y=ty;}
}p[310];
int n;
int max(int a,int b)
{
    if(a>b)return a;
    return b;
}*/
int Scan()     //输入外挂
{
    int res=0,ch,flag=0;
    if((ch=getchar())=='-')
        flag=1;
    else if(ch>='0'&&ch<='9')
        res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+ch-'0';
    return flag?-res:res;
}
double DScan()
{
    int ch,flag=0;int cnt=1;
    double res2=0;
    double res=0;
    if((ch=getchar())=='-')
        flag=1;
    else if(ch>='0'&&ch<='9')
        res=(double)(ch-'0');
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
    {
        cnt*=10;
        res2=res2*10+ch-'0';
    }
    res+=res2/cnt;
    return flag?-res:res;
}
void Out(int a)    //输出外挂
{
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}
/*
double dist(Point p1,Point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
Point get_circle(Point p1,Point p2)
{
    Point mid=Point((p1.x+p2.x)/2,(p1.y+p2.y)/2);
    double angle=atan2(p1.x-p2.x,p2.y-p1.y);
    double d=sqrt(1-dist(p1,mid)*dist(p1,mid));
    return Point(mid.x+d*cos(angle),mid.y+d*sin(angle));
}
int main()
{
    int cnt;int i,j,k;
    while(n=Scan())
    {
        if(n==0)return 0;
        for(int i=0;i<n;i++)
        {
            p[i].x=DScan();
            p[i].y=DScan();
        }
        int ans=1;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(dist(p[i],p[j])>2.0) continue;
                Point central=get_circle(p[i],p[j]);
                cnt=0;
                for(k=0;k<n;k++)
                    if(dist(central,p[k])<1.0+eps)
                        cnt++;
                if(ans<cnt)
                    ans=cnt;
            }
        }
        Out(ans);
        puts("");
    }
    return 0;
}*/

struct point

{

    double x,y;

    void read()

    {

       x=DScan();
       y=DScan();

    }

    void print()

    {

       printf("%lf%lf\n",x,y);

    }

    double friend dis(const point &a,const point &b)

    {

       return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));

    }

}p[Mn + 5];

struct alpha

{

    double v;

    bool flag;

    bool friend operator <(const alpha &a,const alpha &b)//排序专用偏序关系

    {

       return a.v < b.v;

    }

}alp[Mn * Mn + 5];

void solve(int n)

{

    R = 1.0;

    for(int i = 0;i < n;i++)

       p[i].read();

    int MAX = 0;

    for(int i = 0;i < n;i++)

    {

       int t = 0;

       for(int j = 0;j < n;j++)

       {

           if(i == j)

              continue;

           double theta,phi,D;

           D = dis(p[i],p[j]);

           if(D > 2.0 * R)

              continue;



           theta = atan2(p[j].y - p[i].y,p[j].x - p[i].x);

           if(theta < 0)

              theta += 2 * pi;

           phi = acos(D / (2.0 * R));

           alp[t].v = theta - phi + 2 * pi;

           alp[t].flag = true;

           alp[t + 1].v = theta + phi + 2 * pi;

           alp[t + 1].flag = false;

           t += 2;

       }

       sort(alp,alp + t);

       int sum = 0;

       for(int j = 0;j < t;j++)

       {

           if(alp[j].flag)

              sum ++;

           else

              sum --;

           if(sum > MAX)

              MAX = sum;

       }

    }

    Out(MAX+1);
    puts("");

}

int main()

{

    int n;

    while(n=Scan())

    {
       if(n==0)return 0;
       solve(n);

    }

}
