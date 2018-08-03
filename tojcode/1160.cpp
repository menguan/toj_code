#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define eps 1e-8
using namespace std;
struct point
{
    double x,y;
    point(){}
    point(double _x,double _y):x(_x),y(_y){}
    point operator -(const point &b)const
    {
        return point(x - b.x,y - b.y);
    }
    double operator ^(const  point &b)const
    {
        return x*b.y - y*b.x;
    }
};
struct seg
{
    point a,b;
};
seg wall[40];
seg s[100];
int n;
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}
bool jud(seg l1,seg l2)
{
    return
        max(l1.a.x,l1.b.x) >= min(l2.a.x,l2.b.x) &&
        max(l2.a.x,l2.b.x) >= min(l1.a.x,l1.b.x) &&
        max(l1.a.y,l1.b.y) >= min(l2.a.y,l2.b.y) &&
        max(l2.a.y,l2.b.y) >= min(l1.a.y,l1.b.y) &&
        sgn((l2.a-l1.a)^(l1.b-l1.a))*sgn((l2.b-l1.a)^(l1.b-l1.a)) <= 0 &&
        sgn((l1.a-l2.a)^(l2.b-l1.a))*sgn((l1.b-l2.a)^(l2.b-l2.a)) <= 0;
}
int main()
{
    point t;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>wall[i].a.x>>wall[i].a.y>>wall[i].b.x>>wall[i].b.y;
    }
    cin>>t.x>>t.y;
    int ans=1010101010;
    for(int i=0;i<n;i++)
    {
        s[i].a=wall[i].a;
        s[i].b=t;
        s[i+n].a=wall[i].b;
        s[i+n].b=t;
    }
    for(int i=0;i<2*n;i++)
    {
        int tmp=0;
        for(int j=0;j<n;j++)
        {
            if(jud(s[i],wall[j]))
                tmp++;
        }
        ans=min(tmp,ans);
    }
    if(n==0)
        ans=1;
    cout<<"Number of doors = "<<ans<<endl;
}
