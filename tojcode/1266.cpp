#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  eps 1e-8
using namespace std;

struct  point
{
    double x,y;
};
point p[1010],stack[1010];
int N,top;

double multi(point p1, point p2, point p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

double dis(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int cmp(const void *a, const void *b)
{
    point c = *(point *)a;
    point d = *(point *)b;
    double k = multi(p[0], c, d);
    if(k < 0 || (!k && dis(c, p[0]) > dis(d, p[0])))    return 1;
    return -1;
}

void Convex()
{
    for(int i = 1; i < N; i++)
    {
        if(p[i].y < p[0].y || ( p[i].y == p[0].y && p[i].x < p[0].x))
        {
            swap(p[0],p[i]);
        }
    }
    qsort(p + 1, N - 1, sizeof(p[0]), cmp);
    stack[0] = p[0];
    stack[1] = p[1];
    top = 1;
    for(int i = 2; i < N; i++)
    {
        while(top >= 1 && multi(stack[top - 1], stack[top], p[i]) < 0)     top--;
        stack[++top] = p[i];
    }
}

bool judge()
{
    for(int  i=1;i<top;i++)
    {
        if((multi(stack[i-1],stack[i+1],stack[i]))!=0&&(multi(stack[i],stack[i+2],stack[i+1]))!=0)
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>N;
        for(int i=0;i<N;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
        if(N<6)   puts("NO");
        else
        {
                Convex();
                if(judge())
                    puts("YES");
                else
                    puts("NO");
        }
    }
    return 0;
}
