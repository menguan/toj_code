#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[50010];
int main()
{
    int l,n,m,i,j,k,minn,maxn,mid,sum,cnt;
    while(cin>>l>>n>>m)
    {
        minn=1000000005;
        maxn=l;
        a[0]=0,a[n+1]=l;
        for(int i=1;i<=n;i++)
        cin>>a[i];
        n++;
        sort(a,a+n);
        for(int i=1;i<=n;i++)
        minn=min(minn,a[i]-a[i-1]);
        while(minn<=maxn)
        {
            mid=(maxn+minn)/2;
            cnt=sum=0;
            for(int i=1;i<=n;i++)
            {
                if((sum+=a[i]-a[i-1])<=mid)
                    cnt++;
                else
                    sum=0;
            }
            if(cnt<=m)
            minn=mid+1;
            else
            maxn=mid-1;
        }
        cout<<minn<<endl;

    }
}
