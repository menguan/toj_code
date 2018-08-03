#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
long long a[30010];
long long b[30010];
long long c[30010];
int n;long long t;
long long gcd(long long aa,long long bb)
{
    return bb?gcd(bb,aa%bb):aa;
}
int main()
{
    int cas=1;
    while(cin>>n>>t)
    {
        if(n==0&&t==0)
            return 0;
        int bc=0,cc=0;
        long long sum=n*n;
        long long ans=0;
        int zero=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int l,r,mid;
        for(int i=0;i<n;i++)
        {
            if(a[i]>=0)
            {
                l=0;r=n-1;
                while(l<=r)
                {
                    mid=l+(r-l)/2;
                    if(a[i]*a[mid]>t)
                    {
                        r=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                    }
                }
                ans+=n-l;
            }
            else
            {
                l=0;r=n-1;
                while(l<=r)
                {
                    mid=l+(r-l)/2;
                    if(a[i]*a[mid]<=t)
                    {
                        r=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                    }
                }
                ans+=l;
            }
        }
        long long tt=gcd(ans,sum);
        cout<<"Case "<<cas++<<": "<<ans/tt<<"/"<<sum/tt<<endl;
    }
}
