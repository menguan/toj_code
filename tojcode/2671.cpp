#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
              double ans=0;
              double weizhi;
              for(int i=1;i<=n;i++)
              {
                   weizhi=1.0*i/n*(n+m);
                   ans+=fabs(weizhi-floor(weizhi+0.5));
              }
              cout<<setprecision(4)<<fixed<<ans*10000/(n+m)<<endl;
    }
}
                      
