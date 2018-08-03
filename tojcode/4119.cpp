#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
const long long mod=1000000007;
long long n;
int main()
{
    int t;int x;

    //cin>>t;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
        scanf("%lld",&n);
        long long ff=(1+n)*n;
        long long gg=1;
        //cout<<n<<endl;
        //system("pause");
        for(long long i=1;i<=n;i++)
        {
            gg=gg*i%mod;//cout<<i<<endl;
            gg=gg*i%mod;
        }
        long long kk=1;
        for(int i=0;i<2*n-2;i++)
        {
            //cin>>x;
            scanf("%d",&x);
            ff-=x;
            kk=kk*x%mod;
        }
       long long hh=1;
        for(int i=1;i<=n;i++)
        {
            int j=ff-i;
            hh=kk;
            hh=hh*i%mod;
            hh=hh*j%mod;
            if(hh==gg)
            {
                //cout<<i<<" "<<j<<endl;
                printf("%d %d\n",i,j);
                break;
            }
        }
    }
}
