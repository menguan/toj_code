#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int t,n,a[1010],b[1010],f[1010],i,j;
    int sum[1010];
    cin>>t;
    while(t--)
    {
     memset(sum,0,sizeof(sum));
     cin>>n;
     for(i=1;i<=n;i++)
     {
        cin>>a[i]>>b[i];
        sum[i]+=a[i]+sum[i-1];
     }
     for(i=1;i<=n;i++)
     {
       f[i]=(sum[i]+10)*b[i];
       for(j=1;j<i;j++)
         f[i]=min(f[i],(sum[i]-sum[j]+10)*b[i]+f[j]);
     }
     cout<<f[n]<<endl;;
    }
}                                     
