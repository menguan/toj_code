#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1000000];
int main()
{
    int n;int y;
    int sum=0;
    while(~scanf("%d",&n)){
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&y,&a[i]);
     //   sum+=a[i];
    }
    sort(a,a+n);
    //sum/=n;
    sum=a[n/2];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=abs(sum-a[i]);
    }
    printf("%d\n",ans);
    //cout<<ans<<endl;
     }
}
