#include<iostream>
#include<list>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct rectangle
{
    double x1,y1;
    double x2,y2;
};
double area(rectangle r)
{
    return (r.x2-r.x1)*(r.y2-r.y1);
}
bool isInter(rectangle r1,rectangle r2)
{
    rectangle r3;
    r3.x1=max(r1.x1,r2.x1);
    r3.y1=max(r1.y1,r2.y1);
    r3.x2=min(r1.x2,r2.x2);
    r3.y2=min(r1.y2,r2.y2);
    if(r3.x2 > r3.x1 && r3.y2 > r3.y1)
        return true;
    else
        return false;
}
list<rectangle> rl;
int N;
void Add(double x1,double y1,double x2,double y2)
{
    rectangle r;
    r.x1=x1;
    r.x2=x2;
    r.y1=y1;
    r.y2=y2;
    rl.push_back(r);
}
void Cut(rectangle r1,rectangle r2)
{
    double k1,k2,k3,k4;
    //上下左右
    k1=max(r1.x1,r2.x1);
    k2=min(r1.x2,r2.x2);
    if(r1.x1 < k1)
        Add(r1.x1, r1.y1, k1, r1.y2);
    if(k2 < r1.x2)
        Add(k2, r1.y1, r1.x2, r1.y2);

    k3=max(r1.y1,r2.y1);
    k4=min(r1.y2,r2.y2);
    if(r1.y1 < k3)
        Add(k1, r1.y1, k2, k3);
    if(k4 < r1.y2)
        Add(k1, k4, k2, r1.y2);
}

int main()
{
    int i;
    double s;
    int c=0;
    while(scanf("%d",&N))
    {
        if(N==0)
            break;
        c++;
        s=0.0;
        rl.clear();
        for(i=0;i<N;++i)
        {
            rectangle rec;
            scanf("%lf%lf%lf%lf",&rec.x1, &rec.y1,&rec.x2,&rec.y2);
            list<rectangle>::iterator it;
            for(it=rl.begin();it!=rl.end(); )
            {
                if(isInter(rec,*it)==true)
                {
                    Cut(*it,rec);
                    list<rectangle>::iterator del;
                    del=it;
                    it++;
                    rl.erase(del);
                    continue;
                }
                it++;
            }
            rl.push_back(rec);
        }
        for(list<rectangle>::iterator it=rl.begin(); it!=rl.end(); ++it)
        {
            s+=area(*it);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n",c,s);
    }
    return 0;
}
