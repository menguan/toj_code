#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=50010;
struct node{
    int F,S,id;
    bool operator<(const node &x) const {
        if(F!=x.F) return F<x.F;
        return id>x.id;
    }
}P[maxn];
priority_queue<node> speed[110];
int main()
{
    int T,n;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&P[i].F,&P[i].S);
            P[i].id=i+1;
            speed[P[i].S].push(P[i]);
        }
        int t;
        node tmp;
        int mtime=0;
        int ide;
        int k;
        printf("Case #%d:\n",ca);
        int flag=1;
        int flag1=n;
        while(n--)
        {
            flag++;
            t=-1;
            for(int i=1;i<=100;i++)
            {

                if(!speed[i].empty())
                {
                    tmp=speed[i].top();
                    if(tmp.F+tmp.S*mtime>t)
                    {
                        t=tmp.F+tmp.S*mtime;
                        ide=tmp.id;
                        k=i;
                    }
                    else if(tmp.F+tmp.S*mtime==t)
                    {
                        if(tmp.id<ide)
                        {
                            ide=tmp.id;
                            k=i;
                        }
                    }
                }
            }
            speed[k].pop();
            if(flag==flag1+1) printf("%d\n",ide);
            else printf("%d ",ide);
            mtime++;
        }
    }
    return 0;
}
