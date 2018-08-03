#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

#define epx 1e-6

int main()
{
    int T,Case;
    double ua,u0,u1,t1,c0;
    double k,s;
    int n,m;
    double ans;

    cin>>T;
    for (Case=1;Case<=T;Case++)
    {
        printf("Case %d:\n",Case);
        cin>>ua>>u0>>u1>>t1>>n;
        c0=u0-ua;
        k=(log(u1-ua)-log(c0))/t1;
        while (n--)
        {
            cin>>m>>s;
            if (m==0)
            {
                if (fabs(ua-u0)<epx)
                    ans=0;
                else
                    ans=(log(s-ua)-log(c0))/k;
            }
            else
            {
                if (fabs(ua-u0)<epx)
                    ans=ua;
                else
                    ans=ua+c0*exp(s*k);
            }
            printf("%.2lf\n",ans);
        }
        printf("\n");
    }
    return 0;
}
