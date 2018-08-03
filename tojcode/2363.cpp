#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const double eps=1e-8;
int n;
double a;
int main()
{
    while(scanf("%d%lf",&n,&a)!=EOF)
    {
        double l=0,r=1e13,ans=0;
        while(r-l>eps)
        {
            double mid=(l+r)/2;
            double pre1=a,pre2=mid;
            bool is=true;
            for(int i=2;i<n;i++)
            {
                double v=pre2;
                pre2=2*pre2-pre1+2;
                pre1=v;
                if(pre2<eps)
                {
                    is=false;
                    break;
                }
            }
            if(is)
            {
                ans=pre2;
                r=mid;
            }
            else
                l=mid;
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
