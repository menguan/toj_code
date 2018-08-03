#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
using namespace std;
double a1,b1,c1,a2,b2,c2;
double get(double n)
{
    return max(a1*n*n+b1*n+c1,a2*n*n+b2*n+c2);
}
int main()
{
    int t;

    cin>>t;
    while(t--)
    {
        cin>>a1>>b1>>c1>>a2>>b2>>c2;
        double l=0,r=1000;
        while(r-l>0.00000001)
        {
            double ll=(2*l+r)/3;
            double rr=(l+2*r)/3;
            double ans1=get(ll);
            double ans2=get(rr);
            if(ans1>ans2)
                l=ll;
            else
                r=rr;
        }
        printf("%.4f\n",get(l));
    }
}
