#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double pi=acos(-1.0);
struct node
{
    double x,y;
};
double dis(node a, node b)
{
     return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
int main()
{
    int n;
    node a[1100];
    double t[1100];
    while(scanf("%d",&n)==1&&n>0)
    {
        for(int i=0;i<n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
        double cnt=0;
        for(int i=0;i<n;i++)
        {
            int l=0;
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                t[l++]=acos((a[j].x-a[i].x)/dis(a[i],a[j]));
                if(a[j].y<a[i].y) t[l-1]=2*pi-t[l-1];
            }
            sort(t,t+l);
            double _min=2*pi-t[l-1]+t[0];
            for(int i=1;i<l;i++) if(t[i]-t[i-1]<_min) _min=t[i]-t[i-1];
            if(_min>cnt) cnt=_min;
        }
        printf("%.4lf\n",cnt*180/pi);
    }
    return 0;
}
